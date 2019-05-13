#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

class SubtitlesException: public std::invalid_argument{
public:
    SubtitlesException(int line, const std::string &text):invalid_argument("SubtitlesException") {
        std::cout<<"ERROR: Line: "<<line<<", Contents: "<<text<<", ";
    }
};
class InvalidSubtitleLineFormat:public SubtitlesException {
public:
    InvalidSubtitleLineFormat(int line, const std::string &text):SubtitlesException(line,text) {
        std::cout<<"InvalidSubtitleLineFormat."<<std::endl;
    }
};
class OutOfOrderFrames: public SubtitlesException {
public:
    OutOfOrderFrames(int line,const std::string &text):SubtitlesException(line,text) {
        std::cout<<"OutOfOderFrames."<<std::endl;
    }
};
class SubtitleEndBeforeStart: public SubtitlesException {
public:
    SubtitleEndBeforeStart(int line,const std::string &text):SubtitlesException(line,text) {
        std::cout<<"SubtitleEndBeforeStart."<<std::endl;
    }
};
class NegativeFrameAfterShift: public SubtitlesException {
public:
    NegativeFrameAfterShift(int line,const std::string &text):SubtitlesException(line,text) {
        std::cout<<"NegativeFrameAfterShift"<<std::endl;
    }
};
class MovieSubtitles {
private:

public:
    virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second,
            std::istream *in, std::ostream *out)=0;
    virtual ~MovieSubtitles(){//std::cout<<"MovieSubtitles";
    }
};
class MicroDvdSubtitles:public MovieSubtitles {
private:
public:
    void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                             std::ostream *out) override {
        try {
            int offsetInFps = frame_per_second * (offset_in_micro_seconds / 1000);
            std::string content;
            int line = 1;
            int prevFrame=-1;
            while (std::getline(*in, content)) {
                if(content[0]!='{') throw InvalidSubtitleLineFormat(line,content);
                std::stringstream ss;
                std::string rest;
                ss.str("");
                int INT_IN=-1;
                int INT_OFF=-1;
                int i=1;
                bool err = true;
                while(content[i]!='}' && content[i]) {
                    ss << content[i];
                    i++;
                    if(content[i]=='}') {
                        err=false;
                        i++;
                        break;
                    }
                }
                if(err) throw InvalidSubtitleLineFormat(line,content);
                ss>>INT_IN;
                if((INT_IN+offsetInFps)<0) throw NegativeFrameAfterShift(line,content);
                if(INT_IN<prevFrame) throw OutOfOrderFrames(line,content);
                ss.clear();
                prevFrame=INT_IN;
                err = true;
                if(content[i]!='{') throw InvalidSubtitleLineFormat(line,content);
                i++;
                while(content[i]!='}' && content[i]) {
                    ss << content[i];
                    i++;
                    if(content[i]=='}') {
                        err=false;
                        i++;
                        break;
                    }
                }
                if(err) throw InvalidSubtitleLineFormat(line,content);
                ss>>INT_OFF;
                if(INT_IN>=INT_OFF) throw SubtitleEndBeforeStart(line,content);
                while(content[i]) {
                    rest+=content[i];
                    i++;
                }
                INT_IN+=offsetInFps;
                INT_OFF+=offsetInFps;
                *out<<"{"<<INT_IN<<"}{"<<INT_OFF<<"}"<<rest<<"\n";
                line++;
            }
        }
        catch(InvalidSubtitleLineFormat &w) {
            w.what();
            return;
        }
        catch(NegativeFrameAfterShift &w) {
            w.what();
            return;
        }
        catch(OutOfOrderFrames &w) {
            w.what();
            return;
        }
        catch(SubtitleEndBeforeStart &w) {
            w.what();
            return;
        }
    }
};
int main() {
    MicroDvdSubtitles sub;
    std::ifstream inplik;
    inplik.open("../Subtitles/In.txt");
    std::ofstream outplik;
    outplik.open("../Subtitles/Out.txt");
    sub.ShiftAllSubtitlesBy(1000,60,&inplik,&outplik);
    inplik.close();
    outplik.close();
}
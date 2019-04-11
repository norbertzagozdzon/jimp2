#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>

using std::string;
using std::vector;
using std::stringstream;
using std::cout;
using std::regex;
using std::smatch;
using std::regex_match;
using std::endl;
using std::getline;
using std::get;

vector<string> sifter(const vector<string> &v) { // przesianie czasow, niepasujacych do regexa
    regex time {"(^(0[0-9]|1[0-9]|2[0-3]|[0-9]):[0-5][0-9]$)"};
    smatch matches;
    vector<string> sifted;
    for (const auto &a: v) {
        if(regex_match(a,matches,time)) {
            sifted.push_back(a);
        }
    }
    return sifted;
}

int ToMinutes(string time_HH_MM) {
    stringstream ss,temp;
    string token;
    int tempInt, minutes;
    ss<<time_HH_MM;
    getline(ss,token,':');
    temp<<token;
    temp>>tempInt;
    minutes=60*tempInt;
    ss>>tempInt;
    minutes+=tempInt;
    return minutes;

}
unsigned int MinimalTimeDifference(vector<string> times) {
    times = sifter(times);
    vector<int> timesInMins;
    for (const auto &t: times) {
        timesInMins.push_back(ToMinutes(t));
    }
    int minTimeDiff=0;
    if (timesInMins.size()>=2) {
        minTimeDiff = timesInMins[0] - timesInMins[1];
        if (minTimeDiff<0) minTimeDiff*=-1;
    }
    int diff;
    for (int i=0;i<(timesInMins.size()-1);i++) {
        for(int j=i+1;j<timesInMins.size();j++) {
            diff = timesInMins[i]-timesInMins[j];
            if (diff<0) diff*=-1;
            if (diff>720) diff=1440-diff;
            if (diff<minTimeDiff) minTimeDiff=diff;
        }
    }
    return minTimeDiff;
}
void printTimez(const vector<string> &timez) {
    bool first=true;
    cout<<"|| ";
    for (const auto &n: timez) {
        if (!first)
            cout<<" | ";
        else
            first=false;
        cout<<n;
    }
    cout<<" ||"<<endl;
}
void printTimezThatMatches(vector<string> timez) {
    cout<<"Correcly given times: "<<endl;
    printTimez(sifter(timez));
}
int main() {
    vector<string> timez{"zle podany czas","41:40","11:00","23:15","00:55","14:12","18:15","znowu zle podany","15:15","18:02","2:05"};
    cout<<MinimalTimeDifference(timez);
}
#include <iostream>

class Serializer {
public:
   virtual void set(const std::string&) =0;
   virtual std::string get() =0;

};
class XmlSerializer : public Serializer {
private:
    std::string _text;
public:
    XmlSerializer():_text("") {}
    void set(const std::string& text) override {
        _text = text + "\nbut its xml.";
    }
    std::string get() override {return _text;}
};
class JsonSerializer : public Serializer {
    private:
    std::string _text;
public:
    JsonSerializer(): _text("") {}
    void set(const std::string& text) override {
        _text = text + "\nbut its json.";
    }
    std::string get() override { return _text;}
};
class Serializable {
public:
    virtual std::string Serialize(Serializer *) =0;
};

class Room : public Serializable {
private:
    std::string number;
    std::string floor;
    Serializer *state;

public:
    Room(const std::string& number,const std::string& floor): number(number),floor(floor) {}
    std::string Serialize(Serializer *serializer) override {
        state=serializer;
        state->set("number: "+number+"\n"+"floor: "+floor);
        return state->get();
    }

};

class Building : public Serializable {
    std::string floors;
    std::string rooms;
    std::string street;
    Serializer *state;
public:
    Building(const std::string& floors, const std::string& rooms, const std::string& street):floors(floors),rooms(rooms),street(street) {}
    std::string Serialize(Serializer *serializer) override {
        state=serializer;
        state->set("floors: "+floors+"\nrooms: "+rooms+"\nstreet: "+street);
        return state->get();
    }
};

int main() {
    auto *serializer = new JsonSerializer;
    Serializable *s = new Building("4","120","Lenox Ave ");
    std::string text = s->Serialize(serializer);
    std::cout<<text;
}
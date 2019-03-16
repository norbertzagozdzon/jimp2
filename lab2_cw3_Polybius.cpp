#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string PolibiusCrypt(string message) {
    string crypt="";
    string intz = "0123456789";
    for (int i=0;i<message.length();i++) {
        if (65<=message[i] && message[i]<=90) {
            int asci = message[i]-65;
            if (asci>=9) asci--;
            int poz = asci/5+1;
            crypt+=intz[poz];
            poz = asci%5+1;
            crypt+=intz[poz];
            if (i!=message.length()-1) crypt+=' ';
        }
    }
    return crypt;
}
string PolibiusDecrypt(string crypted) {
    string message="";
    int number1,number2;
    char letter;
    int poz;
    for (int i=0;i<crypted.length();i+=3) {
        number1 = crypted[i]-'0';
        number2 = crypted[i+1]-'0';
        poz = (number1-1)*5+(number2-1);
        if (poz>=9) poz++;
        letter = poz+65;
        message+=letter;
    }
    return message;
}

int main(int argc, char *argv[]) {
    if(argc==4) {
        string choice = argv[3];
        ifstream fileIn(argv[1]);
        ofstream fileOut(argv[2]);
        string word;
        string message ="";
        fileIn>>word;
        message+=word;
        while(fileIn>>word) {
            message+=" "+word;
        }
        cout<<"Wczytana wiadomosc: "<<message<<endl;
        if (choice=="1") {
            message=PolibiusCrypt(message);
        }
        else if(choice=="0") {
            message=PolibiusDecrypt(message);
        }
        cout<<"Wiadomosc wyjsciowa: "<<message<<endl<<"Zapisano do pliku "<<argv[2]<<" ...";
        fileOut<<message;
        fileIn.close();
        fileOut.close();
    }
}

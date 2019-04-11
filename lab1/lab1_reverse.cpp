#include<iostream>
#include<string>
using namespace std;

string reverseString(string a, int wsk, string b, size_t size) {
	if (a[wsk]=='\0') {
		return b;
	}
	else {
		b+=a[size-wsk-1];
		wsk+=1;
		return reverseString(a,wsk,b,size);
	}
}

int main() {
	cout<<"podaj napis: ";
	string a;
	cin>>a;
	size_t size = a.size();
	cout<<"reverse: "<<reverseString(a,0,"",size);
}

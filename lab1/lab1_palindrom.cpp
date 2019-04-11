#include<iostream>
using namespace std;

bool is_palindrome(string s) {
	size_t size = s.size();
	if (size>0) {
		for(int i =0;i<size/2;i++) {
			if (s[i]!=s[size-i-1]) {
				return false;
			}
		}
		return true;
	}

}

int main() {
	string s;
	cout<<"podaj napis: ";
	cin>>s;
	cout<<"czy to jest palindrom?: ";
	if (is_palindrome(s)==true) {
		cout<<"tak";
	}
	else {
		cout<<"nie";
	}
	cout<<endl;
}

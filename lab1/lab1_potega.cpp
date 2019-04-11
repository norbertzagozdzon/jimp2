#include<iostream>
using namespace std;

int pow_r(int a, int b) {
	if (b==0) {
		return 1;
	}
	else {
		return a*pow_r(a,b-1);
	}
}

int pow_i(int a,int b) {
	if (a==0) {
		return 0;
	}
	else {
		int wynik=1;
		for(int i=0;i<b;i++) {
			wynik*=a;
		}
		return wynik;
	}
}

int main() {
	int a,b;
	cout<<"podstawa: ";
	cin>>a;
	cout<<"wykladnik: ";
	cin>>b;
	cout<<"wynik: "<<pow_r(a,b)<<endl;
}

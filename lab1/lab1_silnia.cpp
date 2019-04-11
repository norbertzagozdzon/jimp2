#include<iostream>
using namespace std;

int factorial_r(int n) {
	if (n==0 || n==1) {
		return 1;
	}
	else 
		return n*factorial_r(n-1);	
}
int factorial_i(int n) {
	if (n==0 || n==1) {
		return 1;
	}
	else {
		int wynik = 1;
		for(int i =2;i<=n;i++) wynik*=i;
		return wynik;	
	}
}

int main() {
	int n;
	cout<<"podaj n: ";
	cin>>n;
	cout<<"silnia od "<<n<<" = "<<factorial_i(n)<<endl;
}

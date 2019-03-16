#include<iostream>
using namespace std;

void fill(int **tab,int x,int y) {
        int g = 1;
        for(int i=0;i<x;i++) {
                for(int j=0;j<y;j++) {
                        *(*(tab+i)+j) = g;
                        g++;
                }
        }
}
void read(int **tab,int x,int y) {
        for(int i=0;i<x;i++) {
                for(int j=0;j<y;j++) {
                        cout<<*(*(tab+i)+j)<<" ";
                }
                cout<<endl;
        }
}
void DeleteArray2D(int **tab, int x) {
        for (int i=0;i<x;i++) {
                delete tab[i];
        }
        delete *tab;
}

int main(void) {
        int x,y;
        cout<<"x: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        int **tab = new int*[x];
        for(int i=0;i<x;i++)
                tab[i] = new int[y];
        fill(tab,x,y);
        read(tab,x,y);
        DeleteArray2D(tab,x);
        cout<<"usunieto dane..."<<endl;
}
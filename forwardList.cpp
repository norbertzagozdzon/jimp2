#include<iostream>
using namespace std;

struct ForwardList {
    int value;
    ForwardList *next;
};

ForwardList *CreateNode(int value) {
    ForwardList *node = new ForwardList;
    node->value = value;
    node->next = NULL;
    return node;
}

void DestroyList(ForwardList *listx) {
    ForwardList *curr = listx;
    ForwardList *tmp;
    if (curr!=NULL) {
        do {
            tmp = curr;
            delete curr;
            curr = tmp->next;
        }while(curr!=NULL);
    }
    cout<<"Usunieto zawartosc listy..."<<endl;
}

ForwardList *PushFront(ForwardList *listx, int value) {
    ForwardList *node = CreateNode(value);
    node->next = listx;
    return node;
}

void Append(ForwardList *listx, ForwardList *tail) {
    if(listx==NULL) {
        listx = PushFront(listx, tail->value);
    }
    else {
        while(listx->next){
            listx = listx->next;
        }
        listx->next = tail;
    }
}

int main(void) {

ForwardList *lista1=NULL;
lista1 = PushFront(lista1,5);
lista1 = PushFront(lista1,4);
lista1 = PushFront(lista1,3);
lista1 = PushFront(lista1,2);
lista1 = PushFront(lista1,1);
Append(lista1,CreateNode(6));
Append(lista1,CreateNode(7));
Append(lista1,CreateNode(8));
Append(lista1,CreateNode(9));
Append(lista1,CreateNode(10));
while(lista1->next) {
    cout<<lista1->value<<endl;
    lista1=lista1->next;
}
DestroyList(lista1);
}

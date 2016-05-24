#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct NODE{
    int data;
    struct NODE *next;
}*node;

node addElement(node, int);
node rotate(node, int);
void display(node);

int main(){
    node start = NULL;
    bool opt;
    do{
        int data;
        cout<<"\nEnter the data: ";
        cin>>data;
        start = addElement(start, data);
        cout<<"\nContinue? (1/0)";
        cin>>opt;
    }while(opt == true);
    display(start);
    int pos;
    cout<<"\nEnter the rotating position: ";
    cin>>pos;
    start = rotate(start, pos);
    display(start);
    return 0;
}

node addElement(node start, int data){
    node newnode;
    newnode = (node)malloc(sizeof(struct NODE));
    newnode->data = data;
    if(start == NULL){
        start = newnode;
        start->next = NULL;
        return start;
    }
    newnode->next = start;
    start = newnode;
}

void display(node start){
    node temp = start;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL)
            cout<<", ";
        else
            cout<<". ";
        temp=temp->next;
    }
}

node rotate(node start, int pos){
    if(pos == 0){
        return start;
    }
    int iter = pos-1;
    node temp = start;
    while(iter--){
        temp=temp->next;
    }
    cout<<"\nData is"<<temp->data;
    node storeAdd = temp->next;
    temp->next=NULL;
    node temp2=storeAdd;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=start;
    start=storeAdd;
    return start;


}

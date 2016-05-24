#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct NODE{
    int data;
    struct NODE *next;
}*node;

node inputNum(node);
node insertInto(node, int);
node mergeLinkedList(node, node);
void display(node);

int main(){
    node num1 = NULL;
    node num2 = NULL;
    num1 = inputNum(num1);
    num2 = inputNum(num2);
    cout<<"NUM 1: ";
    display(num1);
    cout<<"\nNUM 2: ";
    display(num2);
    num1 = mergeLinkedList(num1, num2);
    display(num1);
    return 0;
}

node insertInto(node start, int data){
    node newnode;
    newnode = (node)malloc(sizeof(struct NODE));
    newnode->data = data;
    if(start == NULL){
        newnode->next = NULL;
        start = newnode;
    }
    else{
        newnode->next = start;
        start = newnode;
    }
    return start;
}

node inputNum(node start){
    bool opt = true;
    while(opt){
        int data;
        cin>>data;
        start = insertInto(start, data);
        cout<<"\nContinue? (true/false) ";
        cin>>opt;
    }
    return start;
}

void display(node start){
    node temp = start;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<", ";
        temp=temp->next;
    }
}

node mergeLinkedList(node list1, node list2){
    node result = NULL;
    if(list1 == NULL)
        return (list2);
    else if(list2 == NULL)
        return list1;
    if(list1->data <= list2->data){
        result = list1;
        result->next = mergeLinkedList(list1->next, list2);
    }
    else{
        result = list2;
        result->next = mergeLinkedList(list1,list2->next);
    }
    return result;
}

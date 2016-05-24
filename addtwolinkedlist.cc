#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct NODE{
    int data;
    struct NODE *next;
}*node;
node reverse(node start);
node inputNum(node);
node insertInto(node, int);
void display(node);
node addNumber(node, node);
int carry=0;

int main(){
    node num1 = NULL;
    node num2 = NULL;
    num1 = inputNum(num1);
    num2 = inputNum(num2);
    cout<<"NUM 1: ";
    display(num1);
    cout<<"NUM 2: ";
    display(num2);
    node num3 = addNumber(num1, num2);
    cout<<"NUM 3";
    display(num3);
    num1=reverse(num1);
    num2=reverse(num2);
    cout<<"\nThe Sum of ";
    display(num1);
    cout<<" + ";
    display(num2);
    cout<<" is ";
    display(num3);
    return 0;
}

node insertInto(node start, int data){
    node newnode;
    cout<<"\nThe Data is: "<<data;
    newnode = (node)malloc(sizeof(struct NODE));
    if(data >= 10){
        carry=1;
        data = data % 10;
    }
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

node addNumber(node num1, node num2){
    node temp1=num1, temp2=num2;
    node start=NULL;
    int data;
    while(temp1!=NULL&&temp2!=NULL){
        data = temp1->data + temp2->data + carry;
        carry=0;
        cout<<"\nSum: "<<data;
        start=insertInto(start,data);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=NULL){
        while(temp1!=NULL){
            data = temp1->data + carry;
            carry=0;
            start=insertInto(start,data);

            temp1=temp1->next;
        }
    }
    else if(temp2!=NULL){
        while(temp1!=NULL){
            data = temp2->data + carry;
            carry=0;
            start=insertInto(start,data);
            temp2=temp2->next;
        }
    }
    if(carry){
        start=insertInto(start,carry);
    }
    return start;
}
node reverse(node start){
    node prev = NULL;
    node curr = start;
    node next;
    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }
    return prev;

}
void display(node start){
    node temp = start;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

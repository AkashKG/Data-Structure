#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

stack <char> s;

bool isOperator(char c){
    switch(c){
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
        break;
    default:
        return false;
    }
}

bool isParan(char c){
    switch(c){
        case ')':
        case '(':
               return true;
            default:return false;
    }
}
int getPrec(char c){
    switch(c){
    case '+':
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 4;
        break;
    case '(':
    case ')':
        return 0;
        break;
    default:
        return 0;
    }
}



void getPostFix(char arr[]){
    for(int i = 0; arr[i]!='\0';i++){
        if(isalpha(arr[i])) cout<<arr[i];
        else if(isOperator(arr[i]) || isParan(arr[i])){
            if(isOperator(arr[i]) && isOperator(arr[i-1])){
                cout<<"\nError";
                return;
            }
            if(arr[i]=='('){
                s.push('(');
            }
            else if(arr[i]==')'){
                while(s.top()!='('){

                        cout<<s.top();
                        s.pop();
                }
                s.pop();
            }
            else if(s.empty()||getPrec(s.top())<getPrec(arr[i]))
                s.push(arr[i]);
            else{
                while(!s.empty()&&getPrec(s.top())>=getPrec(arr[i])){
                    cout<<s.top();
                    s.pop();
                }
                s.push(arr[i]);
            }
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

int main(){
    char arr[] = "a+b*(c^d-e)^(f+g*h)-i";
    getPostFix(arr);
    return 0;
}

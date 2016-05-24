#include<iostream>
#include<stack>
using namespace std;

stack <int> s;

bool isSparse(int num){
    int prev = 0, pres = 0;
    while(num>0){
        pres = num % 2;
        if(pres == 1 && prev == 1){
            return false;
        }
        num = num/2;
        prev = pres;
    }
    return true;
}

int nextSparse(int num){
    while(!isSparse(num)){
        num++;
    }
    return num;
}

void printBinary(int num){
    cout<<endl;
    int mod;
    while(num>0){
        int mod = num % 2;
        s.push(mod);
        num = num / 2;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    int number;
    cin>>number;
    printBinary(number);
    number = nextSparse(number+1);
    cout<<endl<<number;
    printBinary(number);
}

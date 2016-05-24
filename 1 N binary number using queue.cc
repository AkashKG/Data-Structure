#include<iostream>
#include<queue>
using namespace std;

void printBinary(int num){
    queue <string> q;
    q.push("1");
    string s1, s2;
    while(num--){
        s1 = q.front();
        cout<<s1;
        q.pop();
        s2 = s1;

        q.push(s2.append("0"));
        q.push(s1.append("1"));
        cout<<endl;
    }
    q.
}

int main(){
    int num;
    cin>>num;
    printBinary(num);
    return 0;
}

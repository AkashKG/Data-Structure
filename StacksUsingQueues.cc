#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

queue <int> q1,q2, q3;

int main(){
    int opt;
    int val;
    while(1){
        cout<<"\n[1] Push\n[2] Pop\n[3] Display\n\nOption: ";
        cin>>opt;
        switch(opt){

            case 1:
                cout<<"\nEnter the element: ";
                cin>>val;
                q1.push(val);
                break;
            case 2:
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
                q2.pop();
                while(!q2.empty()){
                    q1.push(q2.front());
                    q2.pop();
                }
                break;
            case 3:
                cout<<endl;
                q3 = q1;
                while(!q3.empty()){
                    cout<<q3.front()<<" ";
                    q3.pop();
                }
                cout<<endl;
            break;
            default:
                opt = 1;
        }
    }
}

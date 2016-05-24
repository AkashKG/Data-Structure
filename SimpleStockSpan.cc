#include<iostream>
using namespace std;

int main(){
    int arr[]={100, 80, 60, 70, 60, 75, 85};
    int span[]={1,   0, 0,  0,  0,  0,  0};

    for(int i=1;i<7;i++){
        int j = i;
        for(int k = i;k>=0;k--){
            if(arr[k]>arr[j]){
                break;
            }
            else
                span[j]++;
        }

    }
    cout<<endl;
    for(int j=0;j<7;j++){
        cout<<span[j]<<" ";
    }
    return 0;
}

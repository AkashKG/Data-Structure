#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10
int arr[MAX];

bool AllZero(int arr[], int len, int day){
    int rem=0;
    for(int i=0;i<len;i++){
        if(arr[i]!=0){
            rem = len-1-i;
            break;
        }
    }
    if(rem>=day){
        return false;
    }
    return true;

}


void decrementDay(int arr[], int day, int len){
    for(int i=len-1;i>len-1-day;i--){
        arr[i]--;
    }
}

void display(int arr[], int len){
    cout<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    int len;
    cin>>len;
    for(int i = 0;i<len;i++)
        cin>>arr[i];
    int day = 0;
    sort(arr+0,arr+len);
    while(!AllZero(arr,len, day)){
        display(arr,len);
        day++;
        decrementDay(arr,day, len);
        cout<<"\nAfter decrementing:\n";
        display(arr,len);
        sort(arr+0,arr+len);
    }
    cout<<endl<<day;
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

void incrementPrevDP(int DP[],int arr[], int pos){
    DP[pos]++;
    int i=pos-1;
    while(arr[i]>arr[i+1]){
        DP[i]++;
        i--;
    }
}

void minHike(int DP[], int arr[], int len){
    DP[0]=1;
    for(int i=1;i<len;i++){
        if(arr[i]>arr[i-1]){
            DP[i]=DP[i-1]+1;
            cout<<"\nIncrementing as "<<arr[i]<<" > "<<arr[i-1];
        }
        if(arr[i]<arr[i-1]){
            if(DP[i-1]==1){
                incrementPrevDP(DP,arr,i-1);
                cout<<"\nDP[i] = "<<DP[i];
                DP[i] = 1;
            }
            else{
                DP[i]=DP[i-1]-1;
                cout<<"\nDecrementing as "<<arr[i]<<" < "<<arr[i-1];
            }
        }
    }

}

int main(){
    int len;
    cin>>len;
    int arr[len];
    for(int i=0;i<len;i++)
        cin>>arr[i];
    int DP[len];
    memset(DP,0,sizeof(DP));
    minHike(DP,arr,len);
    cout<<endl;
    for(int i=0;i<len;i++){
        cout<<DP[i]<<" ";
    }
    return 0;
}

#include<iostream>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high){
    int sum = 0;
    int leftSum=-1;
    for(int i=low;i<=mid;i++){
        sum = sum + arr[i];
        if(sum>leftSum)
            leftSum = sum;
    }
    sum = 0;
    int rightSum=-1;
    for(int i=mid+1;i<=high;i++){
        sum=sum+arr[i];
        if(sum>leftSum){
            rightSum = sum;
        }
    }

    return rightSum + leftSum;
}

int maxSubArraySum(int arr[], int low, int high){
    if(low == high){
        return arr[low];
    }
    int mid = ( low + high )/2;
    return max(maxSubArraySum(arr,low+1,mid), maxSubArraySum(arr, mid+1, high), maxCrossingSum(arr, low, mid, high));
}

int main(){
    int arr[]={-1, -4, -7, 4, 0, -1, 13, -11, 22};
    int len = sizeof(arr)/sizeof(int);
    int maxSum = maxSubArraySum(arr, 0, len-1);
    cout<<"\n"<<maxSum;
    return 0;
}

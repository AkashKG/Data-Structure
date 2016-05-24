#include<iostream>
#include<stack>
using namespace std;

void calculateSpan(int price[], int len, int span[]){
    stack <int> s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<len;i++){
        while(price[s.top()]<price[i] && !s.empty()){
            s.pop();
        }
        span[i] = (s.empty())?i+1:i-s.top();
        s.push(i);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
}

int main(){
    int price[] = {90, 70, 50, 30, 10, 60, 80};
    int days = sizeof(price)/sizeof(price[0]);
    int span[days];
    calculateSpan(price, days, span);
    printArray(span, days);
    return 0;
}

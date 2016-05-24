#include<iostream>
#include<algorithm>
using namespace std;

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int getMin(char str[], int start, int last ){
    int minVal = start;
    int x = start-1;
    for(int i = start+1; i<=last; i++){
        if(str[i]<str[minVal] && str[x]<str[i]){
            minVal = i;
        }
    }
    cout<<"\nMinval: "<<minVal<<" Value: "<<str[minVal];
    return minVal;
}

void getMAX(char str[], int len){
    int i = len-1;
    for(i = len-1;i>=0 ; i--){
        if(str[i-1]<str[i]){
            break;
        }
    }
    if(i==-1){
        return;
    }
    cout<<"\nBreaked at"<<i;
    int number = getMin(str, i, len-1);
    cout<<endl<<str;
    cout<<endl<<number;
    swap(&str[number], &str[i-1]);
    cout<<endl<<str<<endl;
    sort(str+i,str+len);
}

int main(){
    char str[]="7896911";
    getMAX(str, 7);
    cout<<str;
    return 0;
}

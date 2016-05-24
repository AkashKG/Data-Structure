#include<iostream>
using namespace std;

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int low, int high){
    if(low == high){
        cout<<str<<"\n";
        return;
    }
    for(int i=low;i<=high;i++){
        swap(str+low,str+i);
        cout<<"-----------------\n"<<str<<"\n------------------\n";
        permute(str, low+1, high);
        cout<<"-----------------\n"<<str<<"\n------------------\n";
        swap(str+low,str+i);
        cout<<"-----------------\n"<<str<<"\n------------------\n";
    }
}


int main(){
    char str[] = "ABC";
    int len = 3;
    permute(str, 0, 2);
    return 0;
}

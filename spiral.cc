#include<iostream>
using namespace std;

void printSpiral(int [][4], int rowLen, int colLen);

int main(){
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printSpiral(arr,3,3);

    return 0;
}

void printSpiral(int arr[][4], int rowLen, int colLen){
    int currRow = 0, currCol = 0;
    while(currRow<=rowLen && currCol<=colLen){
        for(int i=currCol;i<=colLen;i++){
            cout<<arr[currRow][i]<<" ";
        }
        cout<<endl;
        currRow++;
        for(int i=currRow;i<=rowLen;i++){
            cout<<arr[i][colLen]<<" ";
        }
        colLen--;
        cout<<endl;
        if(colLen>=currCol){
            for(int i=colLen;i>=currCol;i--){
                cout<<arr[rowLen][i]<<" ";
            }
                rowLen--;
        }
        cout<<endl;
        if(rowLen>=currRow){
            for(int i=rowLen;i>=currRow;i--){
                cout<<arr[i][currCol]<<" ";
            }
            currCol++;
            cout<<endl;
        }
    }

}

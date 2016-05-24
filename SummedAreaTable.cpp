#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10
int SAT[MAX][MAX];

int getSum(int arr[]){
    if(arr[0] == 0 && arr[1] == 0){
        return SAT[arr[2]][arr[3]];
    }
    else if(arr[1] == 0){
        return SAT[arr[2]][arr[3]] - SAT[arr[0]-1][arr[3]];
    }
    else if(arr[0] == 0){
        return SAT[arr[2]][arr[3]] - SAT[arr[2]][arr[1]-1];
    }
    else{
        return SAT[arr[2]][arr[3]] - SAT[arr[2]][arr[1]-1] - SAT[arr[0]-1][arr[3]] + SAT[arr[0]-1][arr[1]-1];
    }

}

void input(int arr[10][10], int row, int col){
    memset(SAT,0,sizeof(SAT));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
            if(i>=1 && j >=1)
                SAT[i][j] = arr[i][j] + SAT[i-1][j] + SAT[i][j-1] - SAT[i-1][j-1];
            else if(i==0){
                SAT[i][j] = arr[i][j] + SAT[i][j-1];
            }
            else if(j==0){
                SAT[i][j] = arr[i][j] + SAT[i-1][j];
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<SAT[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int row, col;
    cin>>row>>col;
    if(row > 10 || col > 10){
        cout<<"\nSize should be less than 10. Enter both sizes again: ";
        cin>>row>>col;
    }
    int arr[10][10];
    input(arr,row,col);
    while(1){
    cout<<"\nEnter the vertices : ";
    int vert[4];
    for(int i=0;i<4;i++)
        cin>>vert[i];
    int sum = getSum(vert);
    cout<<"\nThe sum from "<<vert[0]<<", "<<vert[1]<<" -> "<<vert[2]<<", "<<vert[3]<<" = "<<sum;
    }
    return 0;
}

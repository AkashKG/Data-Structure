#include<iostream>
using namespace std;

class MinHeap{
    int *parr;
    int heapSize;
    int capacity;
public:
    MinHeap(int cap);
    void minHeapify(int);
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int extractMin();
    void decreaseKey(int i, int newValue);
    int getMin(){return parr[0];}
    void deleteKey(int i);
    void insertKey(int k);
};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap::MinHeap(int cap){
    capacity = cap;
    parr = new int[cap];
    heapSize = 0;
}

void MinHeap::insertKey(int k){
    if(heapSize == capacity){
        cout<<"\nOverflow.";
    }
    heapSize++;
    int i = heapSize-1;
    parr[i]=k;
    while(i!=0&&parr[parent(i)] > parr[i]){
        swap(&parr[parent(i)], &parr[i]);
        i=parent(i);
    }
}

void MinHeap :: decreaseKey(int i, int newVal){
    parr[i]= newVal;
    while(i!=0&&parr[parent(i)] > parr[i]){
        swap(&parr[parent(i)], &parr[i]);
        i=parent(i);
    }
}

int MinHeap :: extractMin(){
    if(heapSize == 0){
        return 10000;
    }
    if(heapSize == 1){
        heapSize--;
        return parr[0];
    }
    int temp = parr[0];
    parr[0]=parr[heapSize-1];
    heapSize--;
    minHeapify(0);
    return temp;
}

void MinHeap :: minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(parr[left(i)] < parr[i] && l<heapSize){
        smallest = l;
    }
    if(parr[right(i)] < parr[smallest] && r<heapSize){
        smallest = r;
    }
    if(smallest!=i){
        swap(&parr[smallest],&parr[i]);
        minHeapify(smallest);
    }
}


int main(){
    MinHeap m(1);
    return 0;
}

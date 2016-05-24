#include<iostream>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

int getStartPosition(struct petrolPump pump[], int len){
    int start = 0;
    int end = 1;
    int currPetrol = pump[0].petrol-pump[0].distance;
    while(end!=start || currPetrol<0){
        while(start!=end && currPetrol<0){
            currPetrol = currPetrol - pump[start].petrol + pump[start].distance;
            start = (start + 1)%len;
            if(start == 0)
                return -1;
        }
        currPetrol = currPetrol + pump[end].petrol - pump[end].distance;
        end = (end + 1)%len;
    }
    return start;
}

int main(){
    struct petrolPump pump[]={{6, 4}, {3, 6}, {7, 3}};
    int pos = getStartPosition(pump, sizeof(pump)/sizeof(pump[0]));
    cout<<pos;
    return 0;
}

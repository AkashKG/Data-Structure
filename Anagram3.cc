#include<iostream>
#include<cstring>
using namespace std;

int MAP[58];

bool checkIfAnagram(char str1[], char str2[]){
    for(int i = 0; str1[i]!='\0';i++){
        MAP[(int)(str1[i]-'A')]++;
    }
    for(int i = 0;i<58;i++){
        cout<<MAP[i]<<" ";
    }
    for(int i = 0; str2[i]!='\0';i++){
        if(!MAP[(int)(str2[i] - 'A')])
            return false;
        else
            MAP[(int)(str2[i] - 'A')]--;
    }
    return true;
}

int main(){
    memset(MAP,0,sizeof(MAP));
    int len1, len2;
    cin>>len1>>len2;
    char str1[len1], str2[len2];
    cin>>str1>>str2;
    bool isAnagram = checkIfAnagram(str1,str2);
    if(isAnagram)
        cout<<"\nAnagram";
    else
        cout<<"\nNot Anagram";
    return 0;
}

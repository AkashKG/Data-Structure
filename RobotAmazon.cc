#include<iostream>
#include<cstring>
using namespace std;

int x = 0, y = 0;
bool backToOrigin(char str[]){
    char pos = 'N';
    int i=0;
    while(str[i]!='\0'){
        if(pos == 'N'){
            cout<<"I'm Facing NORTH ";
            if(str[i] == 'L'){
                cout<<"but the position is left. Moving WEST \n";
                pos = 'W';
                i++;
            }
            else if(str[i]=='R'){
                cout<<"but the position is left. Moving EAST \n";
                pos = 'E';
                i++;
            }
            else{
                cout<<"and I am waking\n";
                while(str[i]=='G'){
                    y++;
                    i++;
                    cout<<"\n|| ||\n";
                }
                cout<<"\nFinished Walking Now.";
            }
        }
        else if(pos == 'S'){
             cout<<"I'm Facing SOUTH ";
            if(str[i] == 'L'){
                cout<<"but the position is left. Moving EAST \n";
                pos = 'E';
                i++;
            }
            else if(str[i]=='R'){

                cout<<"but the position is right. Moving WEST \n";
                pos = 'W';
                i++;
            }
            else{
                cout<<"and I am waking\n";
                while(str[i]=='G'){
                    y--;
                    i++;
                    cout<<"\n|| ||\n";
                }
                cout<<"\nFinished Walking Now.";
            }
        }
        else if(pos=='E'){
            cout<<"I'm Facing EAST ";
            if(str[i] == 'L'){
                cout<<"but the position is left. Moving NORTH \n";
                pos = 'N';
                i++;
            }
            else if(str[i]=='R'){
                cout<<"but the position is right. Moving SOUTH \n";
                pos = 'S';
                i++;
            }
            else{
                cout<<"and I am waking\n";
                while(str[i]=='G'){
                    x--;
                    i++;
                    cout<<"\n|| ||\n";
                }

                cout<<"\nFinished Walking Now.";
            }
        }
        else if(pos == 'W'){
            cout<<"I'm Facing WEST ";
            if(str[i] == 'L'){
                cout<<"but the position is left. Moving SOUTH \n";
                pos = 'S';
                i++;
            }
            else if(str[i]=='R'){
                cout<<"but the position is right. Moving NORTH \n";
                pos = 'N';
                i++;
            }
            else{
                while(str[i]=='G'){
                    x++;
                    i++;
                    cout<<"\n|| ||\n";
                }

                cout<<"\nFinished Walking Now.";
            }
        }
    }

    if(x==0&&y==0){
        return true;
    }
    return false;
}

int main(){
    char str[]="LGRGGGRGGGRGRGGLGG";
    if(backToOrigin(str)){
        cout<<"\nYES";
    }
    else
        cout<<"\nNO";
    return 0;
}

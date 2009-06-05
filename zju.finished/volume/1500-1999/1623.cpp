#include<iostream>
using namespace std;
enum {
    SIZ = 10008,
    LEN = 256,
};
char text[SIZ][LEN];
int num;

void readIn(){
    cin>>num;
    cin.getline(text[0], LEN);
    for(int i=0;i<num;i++){
        cin.getline(text[i], LEN);
    }
}

void match(int &x, int &y){ // find the */, y in the '/'
    if(text[x][y]=='/'){ // forbit /*/
        y++;
    }
    while(x<num){
        if(text[x][y] == 0){
            x++,y=0; continue;
        }
        if(text[x][y] =='/' && y>0 && text[x][y-1]=='*'){
            return;
        }
        y++;
    }
    x = num;
    y = 0;
}
int fun(){
    int x=0 ,y=0,mx,my;
    int flag = 1;
    int occur = 0;
    while(x<num){
        if(text[x][y]==0){
            x++, y=0;
            continue;
        }
        if(text[x][y] == '/' && y>0 && text[x][y-1]=='/'){ // cpp comments. //
            //cout<<"detected from "<<x<<" "<<y<<endl;
            while(text[x][y]){
                text[x][y] = toupper(text[x][y]);
                y++;
            }
            occur ++;
        } else if(text[x][y]=='*' &&y>0&&text[x][y-1]=='/'){ // c comments /**/
            if(flag ==0){
                y++;
                continue;
            }
            mx = x, my = y + 1;
            match(mx,my);
            if(mx >= num){
                flag = 0;
                continue;
            }
            //cout<<"detected "<<x<<" "<<y<<" to "<< mx <<" "<< my<<endl;
            occur ++;
            while(x<mx || (x==mx&&y<my)){
                if(text[x][y] == 0){
                    x++,y=0;
                    continue;
                }
                text[x][y] = toupper(text[x][y]);
                y++;
            }
            y++;
            if(text[x][y]=='/'){ //forbid a matched */ followed by a /, like *//
                                // or we may mistake it as cpp comment
                y++;
            }
        } else {
            y++;
        }
    }
    cout<<occur<<endl;
    for(x=0;x<num;x++){
        cout<<text[x]<<endl;
    }
    cout<<endl;
}

int main(){
    int tstcase;
    cin>>tstcase;
    while(tstcase--){
        readIn();
        fun();
    }
    return 0;
}

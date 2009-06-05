#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 1008,
    None = 0,
    Miss = 1,
    Next = 2,
    Ladd = 3,
};
int input[SIZ];
int *curVal;
int lad[108];
int pos[6];
int num;
map<int,int> ptr;

int readIn(){
    int i;
    cin>>num;
    if(num==0)
        return 0;
    ptr.clear();
    int t;
    memset(lad, 0, sizeof(lad));
    cin>>i>>t;
    while(i && t){
        lad[i] = Ladd;
        ptr.insert(make_pair(i,t));
        cin>>i>>t;
    }
    memset(pos, 0, sizeof(pos));
    cin>>t;
    while(t!=0){
        if(t > 0){
            lad[t] =  Next;
        } else if(t < 0){
            lad[-t] = Miss;
        }
        cin>>t;
    }
    return num;
}

int fun(){
    int cur = 0;
    int renew;
    while(1){
        while(pos[cur] < 0) { // pos[] == -1 表示出局
            cur = (cur + 1) % num;
        }
        if(pos[cur] + *curVal > 100){
            cur = (cur + 1) % num;
            curVal++;
            continue;
        }
        pos[cur] += *curVal;
        curVal++;
        renew = 0;
        if(pos[cur] == 100){
            return cur+1;
        }
        switch(lad[pos[cur]]){
        case None:
            break;
        case Next:
            renew = 1;
            break;
        case Miss:
            pos[cur] = -1;
            break;
        case Ladd:
            pos[cur] = ptr[pos[cur]];
            break;
        }
        if(renew ==0){
            cur = (cur + 1)%num;
        }
    }
    return 0;
}

void init(){
    curVal = input;
    cin>>*curVal;
    while(*curVal != 0){
        curVal++;
        cin>>*curVal;
    }
    curVal = input;
}

int main(){
    int t;
    init();
    while(readIn() > 0){
        curVal = input;
        t = fun();
        cout<<t<<endl;
    }

    return 0;
}


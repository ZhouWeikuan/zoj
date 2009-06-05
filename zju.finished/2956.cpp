#include<iostream>
#include<algorithm>
using namespace std;
enum {
    SIZ = 8004,
    Enter = 0,
    Exit = 1,
};

struct Event {
    int val;
    int type;
    bool operator <(const Event&e)const {
        if(val != e.val)
            return val < e.val;
        return type < e.type;
    }
};

int num;
Event pnt[SIZ];

void fun(){
    int cur = 0, most = 0;
    for(int i=0; i<num; i++){
        if(pnt[i].type == Enter){
            if(++cur > most)
                most = cur;
        } else {
            --cur;
        }
    }
    printf("%d\n", most);
}

int readIn(){
    num = 0;    
    int n, t, low, high;
    scanf("%d ", &n);
    while(n--){
        scanf("%d%d%d ", &t, &low, &high);
        pnt[num].val = low, pnt[num++].type = Enter;
        pnt[num].val = high, pnt[num++].type = Exit;
    }
    sort(pnt, pnt+num);
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}


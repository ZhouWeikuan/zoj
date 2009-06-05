#include<iostream>
using namespace std;
/*
 * 原来，循环移动的只是正在等的车..
 */
enum {
    SIZ = 21,
};
struct Node {
    int w,p;
};
int num;
Node dat[SIZ];
int lot[SIZ] = {0};

void readIn(){
    int t;
    num = 0;
    cin>>t;
    while(t != 99){
        lot[t] = t;
        dat[num].w = t;
        dat[num].p = -1;
        num++;

        cin>>t;
    }
}
void set(int v, int p){
    int i;
    for(i=0; i<num; i++){
        if(dat[i].w == v)
            break;
    }
    if(i !=num)
        dat[i].p = p;
}

void fun(){
    int t, p;
    int off = num;
    while(cin>>t){
        if(lot[t]){
            set(lot[t], t);
            lot[t] = 0;
            off --;
        } else if( off > 0 ) {
            while(lot[t] == 0){
                int v = lot[20];
                memmove(lot+1, lot, sizeof(lot[0])*20);
                lot[1] = v;
            }
            set(lot[t], t);
            lot[t] = 0;
            off--;
        }
    }
}

int main(){

    readIn();
    fun();
    for(int i=0; i<num; i++){
        printf("Original position %d ", dat[i].w);
        if(dat[i].p > 0){
            printf("parked in %d", dat[i].p);
        } else {
            printf("did not park");
        }
        printf("\n");
    }

    return 0;
}


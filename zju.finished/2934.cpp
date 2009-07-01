#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
enum {
    BIT = 16,
    SIZ = 1<<BIT,
};
bool mark[SIZ];
int pers[BIT];
int S, A, B, C;

inline int getNext(){
    return (A*S+B)%C;
}

void init(){
    memset(mark, false, sizeof(mark));
    for (int i=0, b=1; i<16; ++i,b<<=1){
        pers[i] = ((S&b)!=0);
    }
}

void update(){
    int f;
    for (int i=0, b=1; i<16; ++i, b<<=1){
        if (pers[i]==-1){
            continue;
        }
        f = (S&b)!=0;
        if (f != pers[i]){
            pers[i] = -1;
        }
    }
}

void output(){
    for (int i=15, b=1<<15; i>=0; --i, b>>=1){
        if (pers[i]==-1){
            printf("?");
        } else {
            printf("%d", pers[i]);
        }
    }
    printf("\n");
}


void fun(){
    init();
    do {
        mark[S] = true;
        S = getNext();
        update();
    }while(!mark[S]);
    output();
}

int readIn(){
    scanf("%d ", &A);
    if (A ){
        scanf("%d%d%d ", &B, &C, &S);
    }

    return A;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


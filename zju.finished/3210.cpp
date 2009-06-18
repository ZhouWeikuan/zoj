#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};

int N;
int en[SIZ];
int de[SIZ];

const char *ans[4] = {
    "neither",
    "queue", 
    "stack",
    "both",
};

bool equal(){
    for (int i=0; i<N; i++){
        if (en[i] != de[i])
            return false;
    }
    return true;
}

void fun(){
    int v = 0;
    if (equal())
        v |= 1;
    reverse(de, de+N);
    if (equal())
        v |= 2;
    printf("%s\n", ans[v]); 
}

void readIn(){
    int i;
    scanf("%d ", &N);
    for (i=0; i<N; i++){
        scanf("%d ", &en[i]);
    }
    for (i=0; i<N; i++){
        scanf("%d ", &de[i]);
    }
}

int main(){
    int tst;

    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}


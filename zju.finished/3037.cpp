#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 1004,
};

int num;
int pos[SIZ][SIZ];
int gv[SIZ][SIZ];
int bv[SIZ][SIZ];
int boy[SIZ];
int gir[SIZ];

void fill(int g){
    int p = 0, b;
    while(p<num){
        b = pos[g][p];
        if (boy[b] == -1){
            gir[g] = b;
            boy[b] = g;
            break;
        } else {
            int ng = boy[b];
            if (bv[b][g] < bv[b][ng]){
                boy[b] = g;
                gir[g] = b;
                g = ng;
                p = gv[g][b];
            }
            ++p;
        }
    }
}

void fun(){
    memset(boy, -1, sizeof(boy));
    memset(gir, -1, sizeof(gir));
    int i;
    for (i=0; i<num; ++i){
        fill(i);
    }
    for (i=0; i<num; ++i){
        printf("%d\n", gir[i]+1);
    }
}

void readIn(){
    int i,j,v;
    scanf("%d ", &num);
    for (i=0; i<num; ++i){
        for (j=0; j<num; ++j){
            scanf("%d ", &v);
            --v;
            gv[i][v] = j;
            pos[i][j] = v;
        }
    }
    for (i=0; i<num; ++i){
        for (j=0; j<num; ++j){
            scanf("%d ", &v);
            --v;
            bv[i][v] = j;
        }
    }
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


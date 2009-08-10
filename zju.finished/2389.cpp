#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    unsigned short r, c;
};
int row[5];
int col[5];
int drg[2];
Node pnt[SIZ];
int code[SIZ];

int fun(){
    for (int i=0; i<75; ++i){
        if (pnt[code[i]].r==(unsigned short)-1) continue;
        if (++row[pnt[code[i]].r]>=5){
            return i;
        }
        if (++col[pnt[code[i]].c]>=5){
            return i;
        }
        if (pnt[code[i]].r == pnt[code[i]].c){
            if (++drg[0]>=5){
                return i;
            }
        }
        if (pnt[code[i]].r + pnt[code[i]].c == 4){
            if (++drg[1]>=5){
                return i;
            }
        }
    }
    return -1;
}

void read5(int r){
    int v;
    for (int c=0; c<5; ++c){
        scanf("%d", &v);
        pnt[v].r = r;
        pnt[v].c = c;
    }
}

void read4(){
    int v;
    for (int c=0; c<2; ++c){
        scanf("%d", &v);
        pnt[v].r = 2;
        pnt[v].c = c;
    }
    for (int c=3; c<5; ++c){
        scanf("%d", &v);
        pnt[v].r = 2;
        pnt[v].c = c;
    }
}

void readIn(){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(drg, 0, sizeof(drg));
    memset(pnt, -1, sizeof(pnt));
    row[2] = col[2] = 1;
    drg[0] = drg[1] = 1;
    read5(0);
    read5(1);
    read4();
    read5(3);
    read5(4);
    for (int i=0; i<75; ++i){
        scanf("%d", &code[i]);
    }
}

int main(){
    int tst;
    scanf("%d",&tst);
    while(tst-- > 0){
        readIn();
        int t = fun();
        ++t;
        printf("BINGO after %d numbers announced\n", t);
    }

    return 0;
}


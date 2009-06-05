#include<iostream>
using namespace std;
enum {
    SIZ = 10008,
    A = 0,
    B = 1,
    C = 2,
    D = 3,
};

struct Card {
    int dat[D];
    int use;
};

Card c[SIZ];
int ptr[D][SIZ];
int lim[D], cur[D];
int all, sum, num;

void insertCard(int n)
{
    
}

template<int N>
struct ReverseSort {
    bool operator <(const int&a, const int &b)
    {
        return c[a].dat[N] < c[b].dat[N];
    }
}

void fun(){
    int i;
    while(cur[0] < lim[0] || cur[1] < lim[1] || cur[2] < lim[2]){
        for(i=0; i<D; i++){
            while(cur[i] < lim[i]){
                insertCard(i);
            }
        }
    }
}

int readIn(){
    sum = all = 0;
    memset(cur, 0, sizeof(cur));
    scanf("%d ", &num);
    int i, j;
    for(i=0; i<D; i++){
        scanf("%d ", &lim[i]);
    }
    for(j=0; j<num; j++){
        for(i=0; i<D; i++){
            scanf("%d ", &(c[j].dat[i]));
        }
        ptr[i][j] = j;
    }
    sort(&ptr[0][0], &ptr[0][0]+num, ReverseSort<0>());
    sort(&ptr[1][0], &ptr[1][0]+num, ReverseSort<1>());
    sort(&ptr[2][0], &ptr[2][0]+num, ReverseSort<2>());
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


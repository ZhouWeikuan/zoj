#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
enum {
    SIZ = 3004,
};
int S, N, P;
struct Node {
    int page;
    int pos;
    bool operator<(const Node&o)const{
        if (page != o.page)
            return page < o.page;
        return pos < o.pos;
    }
};
Node book[SIZ];

void fun(){
    sort(book, book+N);
    int div = N / S;
    int mod = N % S;
    int v, dis;
    if (P < mod ){
        v = (div + 1) * P;
        dis = (div + 1);
    } else {
        v = (div + 1) * mod + div * (P-mod);
        dis = div;
    }
    Node *ptr = &book[v];
    for(int i=0; i<dis; ++i, ++ptr){
        if (ptr->pos < book[v].pos){
            v = ptr - book;
        }
    }
    printf("%d\n", book[v].page);
}

int readIn(){
    if (scanf("%d ", &S) < 0)
        return 0;
    scanf("%d%d ", &P, &N);
    for(int i=0; i<N; i++){
        scanf("%d ", &book[i].page);
        book[i].pos = i;
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


#include<iostream>
using namespace std;
enum {
    SIZ = 100004,
};
struct Node {
    int num;
    int val[SIZ];
    void readIn(){
        scanf("%d",&num);
        for (int i=0; i<num; ++i){
            scanf("%d", &val[i]);
        }
    }
    int merge(const Node &o) const {
        int a = 0, b = 0;
        int r = 0;
        while(a<num&&b<o.num){
            if (val[a] == o.val[b]){
                ++r;
                ++a, ++b;
            } else if (val[a] < o.val[b]){
                ++a;
            } else {
                ++b;
            }
        }
        return r;
    }
};

Node tab[2];

void fun(){
    int r = tab[0].merge(tab[1]);
    printf("%d\n", r);
}

void readIn(){
    tab[0].readIn();
    tab[1].readIn();
}

int main(){
    int tst;

    scanf("%d", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}


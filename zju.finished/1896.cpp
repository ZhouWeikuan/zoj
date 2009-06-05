#include<iostream>
using namespace std;
enum {
    SIZ = 60,
};
struct Node {
    unsigned type : 4;
    unsigned val  : 12;
};
int  rule, num;
Node tab[2][SIZ];
int  wash[108][SIZ];

char *typestr[4] = {
    "Clubs", "Diamonds", "Hearts", "Spades"
};
char *valstr[13] = {
    "2", "3", "4", "5", "6", "7", "8", "9",
    "10", "Jack", "Queen", "King", "Ace"
};

void init(Node * p){
    int i,j;
    num = 0;
    for(i=0; i<4; i++){
        for(j=0; j<13; j++){
            p[num].type = i;
            p[num].val = j;
            num++;
        }
    }
}
void output(Node *p){
    for(int i=0; i<num; i++){
        printf("%s of %s\n", 
                valstr[p[i].val], 
                typestr[p[i].type]);
    }
    printf("\n");
}
void fun(){
    int r, i;
    Node *cur, *pre, *tmp;
    cur = tab[1], pre=tab[0];
    while(scanf("%d", &r) > 0){
        r--;
        for(i=0; i<num; i++){
            cur[i] = pre[wash[r][i]];
        }
        output(cur);
        tmp = pre, pre = cur, cur = tmp;
    }
}

void readIn(){
    scanf("%d", &rule);
    int i,j;
    for(i=0; i<rule; i++){
        for(j=0; j<num; j++){
            scanf("%d", &wash[i][j]);
            wash[i][j]--;
        }
    }
}
int main(){
    init(tab[0]);
    readIn();
    fun();
    return 0;
}


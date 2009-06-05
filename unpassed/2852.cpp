#include<iostream>
#include<queue>
// Wrong Answer;
using namespace std;
struct Node{
    unsigned char m[3];
};
int num;
int tab[22][22][22];
bool mark[22][22][22];

int getVal(char ch){
    if(isdigit(ch))
        return ch - '0';
    switch(ch){
    case 'A':
        return 1;
    case 'T':    case 'J':    case 'Q':    case 'K':
        return 10;
    case 'F': 
        return 100;
    }
    return -1;
}
void fun(){
    char v;
    unsigned char t;
    int res=0, nv, ov;
    queue<Node> q[2], *pre,*cur,*tmp;
    pre = &q[0], cur=&q[1];
    Node one = {0}, nex;
    tab[one.m[0]][one.m[1]][one.m[2]] = 0;
    pre->push(one);
    for(int i=0; i<num; i++){
        memset(mark, false, sizeof(mark));
        scanf(" %c", &v);
        v = getVal(v);
        while(!pre->empty()){
            one = pre->front(); pre->pop();
            ov = tab[one.m[0]][one.m[1]][one.m[2]];
            nex = one;
            for(int j=0; j<3; j++){
                if(one.m[j]>=21) continue;
                nv = ov + 50;
                t = one.m[j] + v;
                if(v == 100 || t==21) {
                    t = 0;
                    nv += (j+1)*100;
                }else if(t > 21) t = 21;
                if(res < nv) res = nv;
                swap(t, nex.m[j]);
                if(tab[nex.m[0]][nex.m[1]][nex.m[2]] < nv){
                    tab[nex.m[0]][nex.m[1]][nex.m[2]] = nv;
                    if(!mark[nex.m[0]][nex.m[1]][nex.m[2]]){
                        cur->push(nex);
                        mark[nex.m[0]][nex.m[1]][nex.m[2]] = true;
                    }
                }
                swap(t, nex.m[j]);
            }
        }
        tmp = cur; cur=pre; pre=tmp;
    }
    printf("%d\n", res);
}

int main(){

    scanf("%d", &num);
    while(num > 0){
        memset(tab, -1, sizeof(tab));
        fun();
        scanf("%d", &num);
    }
    return 0;
}


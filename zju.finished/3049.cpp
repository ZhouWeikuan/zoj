#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
enum {
    SIZ = 1004,
    LIM = 99999999,
};

int N, Pi, sum;
struct Node {
    int p1, p2;
    bool operator <(const Node&o)const {
        return p1 < o.p1;
    }
};
Node tree[SIZ];
int tab[SIZ];

int calc(){
    int j, d;
    memset(tab, -1, sizeof(tab)); tab[sum] = 0;
    tab[Pi] = LIM;
    for (j = N-1; j>=0 && tree[j].p1 >= Pi; --j){
        d = tree[j].p2 - tree[j].p1 - Pi;
        if(d < tab[Pi]){
            tab[Pi] = d;
        }
    }
    ++j;
    for(int i=0; i<j; i++){
        d = tree[i].p2 - tree[i].p1 - Pi;
        for(int k=Pi-1; k>=sum; --k){
            if (tab[k] == -1) continue;
            int t = tree[i].p1 + k;
            if (t < Pi){
                if (tab[t]==-1 || tab[t] > d + tab[k]){
                    tab[t] = d + tab[k];
                }
            } else if(tab[k] + d < tab[Pi]){
                tab[Pi] = d + tab[k];
            }
        }
    }
    return (tab[Pi] != LIM);
}

void fun(){
    int i;
    if (sum >= Pi){ // direct add
        for (i=0; i<N; i++){
            sum += tree[i].p2 - Pi;
        }
    } else if (calc() > 0) { //find a bin pack to drop least
        for (i=0; i<N; i++){
            sum += tree[i].p2 - Pi;
        }
        sum -= tab[Pi];
    } else { // can't find a bin pack to drop least, direct add the first
        for (i=0; i<N; i++){
            sum += tree[i].p1;
        }
    }
    printf ("%d\n", sum);
}

int readIn(){
    if (scanf("%d%d ", &N, &Pi) <0)
        return 0;
    char buf[100];
    sum = 0;
    int j = 0;
    for(int i=0; i<N; i++){
        fgets(buf, 100, stdin);
        tree[j].p1 = tree[j].p2 = 0;
        sscanf(buf, "%d%d ", &tree[j].p1, &tree[j].p2);
        if (tree[j].p2 <= tree[j].p1 + Pi)
            tree[j].p2 = tree[j].p1;
        if (tree[j].p2 == tree[j].p1)
            sum += tree[j].p1;
        else 
            j++;
    }
    N = j;
    sort(tree, tree+N);
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 10,
    STAT = 12000,
};
struct Node {
    unsigned pred;
    unsigned step;
    unsigned avail;
};
Node tree[STAT];
int r, d, s;
int dest, source;
char door[SIZ][SIZ];
char light[SIZ][SIZ];
int mask[SIZ];
int RM;
inline unsigned getStat(unsigned a, unsigned l){
    a <<=SIZ;
    a += l;
    return a;
}
void diff(int a, int b){
    // light different
    for(int i=0; i<=r; i++){
        if((a&mask[i])!=(b&mask[i])){
            if(b&mask[i]){ // on
                printf("- Switch on light in room %d.\n", i+1);
            } else { // off
                printf("- Switch off light in room %d.\n", i+1);
            }
            return;
        }
    }
    // door different
    b>>=SIZ;
    printf("- Move to room %d.\n", b+1);
}
void traceback(){
    static int tmp[STAT], pos = 0;
    int t = dest;
    pos = 0;
    while(t!=source){
        tmp[pos++] = t;
        t = tree[t].pred;
    }
    tmp[pos] = t;
    for(pos--; pos>=0; pos--){
        diff(tmp[pos+1], tmp[pos]);
    }
}
void bfs(){
    queue<int> q;
    int cur, nex, i, room;
    tree[source].pred = source;
    tree[source].step = 0;
    tree[source].avail= 0;
    q.push(source);
    while(!q.empty()){
        cur = q.front(); q.pop();
        tree[cur].avail= 1;
        room = cur>>SIZ;
        // door process
        for(i=0; i<=r; i++){
            if(door[room][i] == 0 || room==i) continue;
            if( (mask[i]&cur) == 0) continue; // not lit;
            nex = getStat(i, cur&RM);
            if(tree[nex].step > tree[cur].step + 1){
                tree[nex].step = tree[cur].step + 1;
                tree[nex].pred = cur;
                if(tree[nex].avail){
                    tree[nex].avail = 0;
                    q.push(nex);
                } 
            }
        }
        // light process
        for(i=0; i<=r; i++){
            if(light[room][i] == 0 || room == i) continue;
            nex = cur^mask[i];
            if(tree[nex].step > tree[cur].step + 1){
                tree[nex].step = tree[cur].step + 1;
                tree[nex].pred = cur;
                if(tree[nex].avail){
                    tree[nex].avail = 0;
                    q.push(nex);
                } 
            }
        }

    }
}
void fun(){
    bfs();
    if(tree[dest].pred == -1){
        printf("The problem cannot be solved.\n");
        return;
    }
    printf("The problem can be solved in %u steps:\n", tree[dest].step);
    traceback();
}

void readIn(){
    memset(door, 0, sizeof(door));
    memset(light, 0, sizeof(light));
    memset(tree, -1, sizeof(tree));
    r--;
    int a, b, i;
    for(i=0; i<d; i++){
        scanf("%d%d",&a,&b);
        a--,b--;
        door[a][b] = door[b][a] = 1;
    }
    for(i=0; i<s; i++){
        scanf("%d%d",&a,&b);
        a--,b--;
        light[a][b] = 1;
    }
    dest    =   getStat(r, 1<<r);
    source  =   getStat(0, 1);
}

int main(){
    int villa = 0;
    RM = (1<<SIZ)-1;
    for(int i=0; i<SIZ; i++){
        mask[i] = 1<<i;
    }

    while(scanf("%u%u%u",&r,&d,&s) > 0 && r + d + s){
        readIn();
        printf("Villa #%d\n", ++villa);
        fun();
        printf("\n");
    }
    return 0;
}


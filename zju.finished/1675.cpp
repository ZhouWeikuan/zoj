#include<iostream>
#include<queue>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
enum {
    SIZ = 10,
};
int tab[SIZ][SIZ];
int mask[SIZ][SIZ];
hash_map<int,int> dis;
hash_map<int,int> pred;
typedef hash_map<int,int>::iterator Iter;
int h,w;
int gx,gy;

struct Node {
    int a:8;
    int b:8;
    int x:8;
    int y:8;
};
struct Pos {
    int x:8;
    int y:8;
};
Node cur;

int readIn(){
    scanf("%d%d",&w,&h);
    if(w==0)  return 0;
    int t;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&t);
            tab[i][j] = 0;
            if(t <= 1){
                tab[i][j] = t;
            } else if(t==2){
                cur.x = i; cur.y=j;
            } else if(t==3){
                gx = i; gy=j;
            } else if(t==4){
                cur.a=i; cur.b=j;
            }
        }
    }
    return 1;
}

int getKey(Node o){
    int ret = *((int*)&o);
    return ret;
}
int move[4][2] ={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
int valid(Pos p){
    return p.x>=0&&p.x<h&&p.y>=0&&p.y<w;
}
int reach(Node cur, int x, int y){
    static int update = 0;
    if(tab[x][y] == 1)
        return 0;
    update ++;
    
    tab[cur.x][cur.y] = 1;

    queue<Pos> q;
    Pos a = {cur.a, cur.b}, b;
    q.push(a); mask[a.x][a.y] = update;
    while(!q.empty()){
        a = q.front(); q.pop();
        if(a.x == x && a.y==y){
            tab[cur.x][cur.y] = 0;
            return 1;
        }
        for(int i=0;i<4;i++){
            b.x = a.x + move[i][0];
            b.y = a.y + move[i][1];
            if(!valid(b))
                continue;
            if(tab[b.x][b.y]== 1 || mask[b.x][b.y] == update)
                continue;
            mask[b.x][b.y] = update;
            q.push(b);
        }
    }
    tab[cur.x][cur.y] = 0;
    return 0;
}

void backtrace(int key){
    while(key != -1){
        Node cur = *(Node*)&key;
        printf("%d %d %d %d -> ", cur.a, cur.b, cur.x,cur.y);
        key = pred[key];
    }
    printf("\n");
}
int fun(){
    int key = getKey(cur);
    int d;
    queue<Node> q;
    dis.clear();
    pred.clear();
    q.push(cur);
    dis[key] = 0;
    pred[key] = -1;
    Node next;
    Iter it;
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(cur.x == gx && cur.y == gy){
            //backtrace(getKey(cur));
            return dis[getKey(cur)];
        }
        d = dis[getKey(cur)];
        // up;
        next = cur;
        if(next.x>0 &&  tab[next.x-1][next.y] ==0
                && reach(next, next.x+1,next.y)){
            next.a = next.x; next.b = next.y;
            next.x --;
            key = getKey(next);
            it = dis.find(key);
            if(it==dis.end() || it->second > d + 1){
                q.push(next);
                pred[key] = getKey(cur);
                dis[key] = d + 1;
            }
        }
        // dn;
        next = cur;
        if(next.x <h-1 &&tab[next.x+1][next.y]==0 
                && reach(next, next.x-1, next.y)){
            next.a = next.x; next.b = next.y;
            next.x++;
            key = getKey(next);
            it = dis.find(key);
            if(it==dis.end() || it->second > d + 1){
                q.push(next);
                pred[key] = getKey(cur);
                dis[key] = d + 1;
            }
        }
        // left;
        next = cur;
        if(next.y>0 && tab[next.x][next.y-1] ==0 
                &&reach(next, next.x,next.y+1)){
            next.a = next.x; next.b = next.y;
            next.y--;
            key = getKey(next);
            it = dis.find(key);
            if(it==dis.end() || it->second > d + 1){
                q.push(next);
                pred[key] = getKey(cur);
                dis[key] = d + 1;
            }
        }
        // right;
        next = cur;
        if(next.y<w-1&& tab[next.x][next.y+1]==0&&reach(next,next.x,next.y-1)){
            next.a = next.x; next.b = next.y;
            next.y++;
            key = getKey(next);
            it = dis.find(key);
            if(it==dis.end() || it->second > d + 1){
                q.push(next);
                pred[key] = getKey(cur);
                dis[key] = d + 1;
            }
        }
    }
    return -1;
}
int main(){
    
    while(readIn()){
        cout<<fun()<<endl;
    }
    return 0;
}

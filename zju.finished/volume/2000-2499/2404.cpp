#include<iostream>
#include<queue>

using namespace std;
struct Point {
    int x,y;
};
enum {
    SIZ = 240,
};

int tab[SIZ][SIZ];
int dis[SIZ];
int ptr[SIZ];
int num;
int source;
int sink;
Point home[SIZ];
Point man[SIZ];

int readIn(){
    int a,b;
    cin>>a>>b;
    if(a == 0)
        return 0;
    int h= 0,m = 0;
    char ch;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>ch;
            if(ch == 'H'){
                home[h].x = i;
                home[h].y = j;
                h ++;
            } else if(ch=='m'){
                man[m].x = i;
                man[m].y = j;
                m++;
            }
        }
    }
    memset(tab, 0, sizeof(tab));
    num = h;
    for(h=0;h<num;h++){
        for(m=0;m<num;m++){
            a = abs(home[h].x - man[m].x);
            b = abs(home[h].y - man[m].y);
            tab[h][num+m] = a + b;
        }
    }
    source = num * 2;
    sink = source + 1;
    for(h=0;h<num;h++){
        tab[source][h] = 1;
        tab[num+h][sink] = 1;
    }

    return 1;
}

int minflow(){
    for(int i=0;i<=sink;i++){
        dis[i] = 99999999;
    }
    queue<int> q;

    q.push(source);
    dis[source] = 0;
    ptr[source] = -1;

    int cur,next;
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(cur == sink)
            continue;
        for(int i=0;i<=sink;i++){
            if(tab[cur][i] ==0 || i==source)
                continue;
            if(dis[cur] + tab[cur][i]  < dis[i]){
                dis[i] = dis[cur] + tab[cur][i];
                ptr[i] = cur;
                q.push(i);
            }
        }
    }
    int ret = 0;
    cur = sink; next = ptr[cur];
    while(next!=-1) {
        tab[cur][next] = -tab[next][cur];
        ret += tab[next][cur];
        tab[next][cur]  = 0;
        cur = next; next = ptr[cur];
    }
    return ret -2;
}

void fun(){
    int ans = 0, t;
    while(num){
        num --;
        ans += minflow();
    }
    cout<<ans<<endl;
}

int main(){
    
    while(readIn() > 0){
        fun();
    }

	return 0;
}

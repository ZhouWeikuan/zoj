#include<iostream>
#include<queue>
#include<ext/hash_map>
typedef unsigned long long u64_t;
using namespace std;
using namespace __gnu_cxx;
struct hash_u64_t{
    int operator()(u64_t v) const {
        return (v>>32)|(v&0xffffffff);
    }
};
hash_map<u64_t, int, hash_u64_t> tab;
int pos[4] = {0, 1, 2, 3};
u64_t s = 0x0fll,d;
const u64_t base = 0x01llu;
int mark[8][8];
int direct[4][2] = {
    {-1, 0}, {1,0}, {0,-1}, {0,1}
};
int readIn(){
    int x,y;
    s = d = 0;
    for(int i=0;i<4;i++){
        if(scanf("%d%d",&x,&y)<0)
            return 0;
        x -- , y --;
        s |= base<<(8*x+y);
    }
    for(int i=0;i<4;i++){
        scanf("%d%d",&x,&y);
        x -- , y --;
        d |= base<<(8*x+y);
    }
    return 1;
}
int fun(){
    static int tstcase = 0;
    tstcase++;
    queue<u64_t> q;
    int p;
    tab.clear();
    tab[s] = 0;
    q.push(s);
    int i,j,x,y,nx,ny;
    u64_t next;
    while(!q.empty()){
        s = q.front(); q.pop();
        p = tab[s];
        j = 0;
        for(i=0;i<64;i++){
            if(0== (s&(base<<i)) ){
                mark[i/8][i%8] = 0;
            } else {
                pos[j++] = i;
                mark[i/8][i%8] = 1;
            }
        }
        for(i=0;i<4;i++){
            x = pos[i] / 8;
            y = pos[i] % 8;
            for(j=0;j<4;j++){ // 16 个可选方向
                nx = x + direct[j][0];
                ny = y + direct[j][1];
                if(nx >=8||nx<0||ny>=8||ny<0)
                    continue;
                if(mark[nx][ny] == 0){
                    next= s; next^= base<<pos[i];
                    next |=base<<(nx*8+ny);
                    if(d == next)
                        return 1;
                    else if(tab.find(next) == tab.end() && p < 7){
                        tab[next] = p + 1;
                        q.push(next);
                    }
                } else {
                    nx += direct[j][0];
                    ny += direct[j][1];
                    if(nx >=8||nx<0||ny>=8||ny<0)
                        continue;
                    if(mark[nx][ny] == 0){
                        next = s; next ^= base<<pos[i];
                        next |=(base<<(nx*8+ny));
                        if(d == next)
                            return 1;
                        else if(tab.find(next) == tab.end() && p < 7){
                            tab[next] = p + 1;
                            q.push(next);
                        }
                    }
                }
            }
        } // for
    }// while
    return 0;
}
int main(){
    const char *ans[2] = {"NO","YES"};
    while(readIn()){
        printf("%s\n",ans[fun()]);
    }
	return 0;
}


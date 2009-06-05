#include<iostream>
#include<set>
using namespace std;
enum {
    SIZ = 7,
    UP = 0,
    DN = 1,
    LF = 2,
    RT = 3,
};
int move[4][2] = {
    {-2,0},
    {2,0},
    {0,-2},
    {0,2}
};
int mark[SIZ][SIZ] = {0};
int used[SIZ][SIZ];
set<int> peg;
void init(){
    mark[0][0] = mark[0][1] = mark[1][0] = mark[1][1] = 1;
    mark[0][5] = mark[0][6] = mark[1][5] = mark[1][6] = 1;
    mark[5][0] = mark[5][1] = mark[6][0] = mark[6][1] = 1;
    mark[5][5] = mark[5][6] = mark[6][5] = mark[6][6] = 1;
    int t = 1;
    for(int i=0;i<SIZ;i++){
        for(int j=0;j<SIZ;j++){
            if(mark[i][j]){
                mark[i][j] = 0;
            } else {
                mark[i][j] = t++;
            }
        }
    }
}
void readIn(){
    int t;
    peg.clear();
    cin>>t;
    while(t){
        peg.insert(t);
        cin>>t;
    }
    memset(used,0,sizeof(used));
    for(int i=0;i<SIZ;i++){
        for(int j=0;j<SIZ;j++){
            if(peg.find(mark[i][j]) != peg.end()){
                used[i][j] = 1;
            }
        }
    }
}
int fun(){
    int dst,d,sx,sy;
    int i,j,k;
    int dx,dy;
    while(1){
        dst = 0;  sx = sy = 0; d = 0;
        for(i=0;i<SIZ;i++){
            for(j=0;j<SIZ;j++){
                if(used[i][j] == 0)
                    continue;
                for(k=0;k<4;k++){
                    dx = i + move[k][0];
                    dy = j + move[k][1];
                    if(dx<0||dx>=SIZ||dy<0||dy>=SIZ || mark[dx][dy]==0)
                        continue;
                    if(used[dx][dy]==1 || used[(dx+i)/2][(dy+j)/2] !=1){
                        continue;
                    }
                    if(mark[dx][dy] > dst 
                            || (mark[dx][dy]==dst && mark[sx][sy]<mark[i][j])){
                        dst = mark[dx][dy];
                        sx = i; sy = j;
                        d = k;
                    }
                }
            }
        }
        if(dst <= 0){
            break;
        }
        dx = sx + move[d][0];
        dy = sy + move[d][1];
        used[sx][sy] = 0;
        used[(sx+dx)/2][(sy+dy)/2] =0;
        used[dx][dy] = 1;
    }
    int ret = 0;
    for(i=0;i<SIZ;i++){
        for(j=0;j<SIZ;j++){
            if(used[i][j]){
                ret += mark[i][j];
            }
        }
    }
    return ret;
}
int main(){
    int tstcase;
    init();
    cout<<"HI Q OUTPUT"<<endl;
    cin>>tstcase;
    while(tstcase--){
        readIn();
        cout<<fun()<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}


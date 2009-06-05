#include<iostream>

using namespace std;
enum {
    SIZ = 19,     
};
int move[4][2]={
    {0,1},
    {1,0},
    {1,1},
    {-1,1}
};
int tab[SIZ][SIZ];

inline bool notchecked(int x, int y, int d){
    int ox = x - move[d][0], oy = y-move[d][1];
    if(ox<0||ox>=SIZ || oy<0||oy>=SIZ)
        return true;
    if(tab[ox][oy] != tab[x][y] )
        return true;
    return false;
}
inline int calc(int x, int y, int d){
    int ret = 1;
    int nx = x + move[d][0], ny = y + move[d][1];
    while(nx>=0&&nx<SIZ&&ny>=0&&ny<SIZ
        &&tab[nx][ny] == tab[x][y]){
        ret ++;
        nx += move[d][0], ny += move[d][1];
    }
    return ret;
}

void readIn(){
    int i,j;
    for(i=0;i<SIZ;i++){
        for(j=0;j<SIZ;j++){
            cin>>tab[i][j];
        }
    }
}

void fun(){ 
    int i,j;
    for(i=0;i<SIZ;i++){
        for(j=0;j<SIZ;j++){
            if(tab[i][j] == 0)
                continue;
                
            for(int d=0;d<4;d++){
                if(notchecked(i,j,d)){
                    int val = calc(i,j,d);
                    if(val ==5)
                        goto end;
                }
            }
        }
    }  
    cout<<0<<endl;
    return ;
end:
    cout<<tab[i][j]<<endl;
    cout<<(i+1)<<" "<<(j+1)<<endl;
}

int main(){
    int tstcase;
    cin>>tstcase;
    while(tstcase --){
        readIn();
        fun();
    }
    
    return 0;
}

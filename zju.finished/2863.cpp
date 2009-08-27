#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 16,
};
unsigned short abs(unsigned short a, unsigned short b){
    return max(a,b)-min(a,b);
}
struct Node {
    unsigned short r, c;
    bool near(const Node &o)const{
        return abs(r,o.r)<=1 && abs(c,o.c)<=1;
    }
};

int nOne, nTwo;
Node one[SIZ*SIZ], two[SIZ*SIZ];
int game[SIZ][SIZ];
bool tab[SIZ*SIZ][SIZ*SIZ];
int mat[SIZ*SIZ];
bool vis[SIZ*SIZ];

int dfs(int p){
    int i,t;
    for(i=0; i<nOne; i++)
        if(tab[i][p] && !vis[i]){
            vis[i]=1;
            t=mat[i];
            mat[i]=p;
            if(t==-1 || dfs(t))
                return 1;
            mat[i]=t;
        }
    return 0;
}

int get_match(){
    int i,res=0;
    memset(mat,-1,sizeof(mat));
    for(i=0; i<nTwo;i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i))
            res++;
    }

    return res;
}

void output(){
    for (int i=0; i<15; ++i){
        for (int j=0; j<15; ++j){
            if (j) printf(" ");
            printf("%d", game[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fun(){
    if ((nOne<nTwo||nOne-1>nTwo) || get_match() != nTwo){
        printf("No solution.\n\n");
        return;
    }
    for (int i=0; i<nOne; ++i){
        int m = mat[i];
        if (m == -1){
            game[one[i].r][one[i].c] = 2 * nOne - 1;
        } else {
            game[one[i].r][one[i].c] = game[two[m].r][two[m].c] - 1;
        }
    }
    output();
}

void readIn(){
    nOne = nTwo = 0;
    for (int i=0; i<15; ++i){
        for (int j=0; j<15; ++j){
            scanf("%d", &game[i][j]);
            if (game[i][j] == 0) continue;
            if (game[i][j] % 2 == 0){
                two[nTwo].r = i;
                two[nTwo].c = j;
                ++nTwo;
            } else {
                one[nOne].r = i;
                one[nOne].c = j;
                ++nOne;
            }
        }
    }
    memset(tab, 0, sizeof(tab));
    for (int i=0; i<nOne; ++i){
        for (int j=0; j<nTwo; ++j){
            if (one[i].near(two[j])){
                tab[i][j] = true;
            }
        }
    }
}

int main(){
    int tst, tn = 1;
    scanf("%d", &tst);
    while(tst-- > 0){
        printf("Round #%d:\n", tn++);
        readIn();
        fun();
    }

    return 0;
}


#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 26,
};
bool use[SIZ];
int cnt[SIZ];
int mat[SIZ][SIZ];
char tab[2][SIZ];
int row;

void fun(){
    priority_queue<int, vector<int>, greater<int> > q;
    int a, b, i;
    for(i=0; i<SIZ; i++){
        if(use[i] && cnt[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        a = q.top(); q.pop();
        printf("%c", 'A'+a);
        for(i=0; i<SIZ; i++){
            if(mat[a][i]){
                cnt[i]--;
                if(cnt[i] == 0){
                    q.push(i);
                }
            }
        }
    }
    printf("\n");
}

void readIn(){
    char *pre = tab[0], *cur=tab[1], *tmp;
    int i, a, b;
    memset(use, false, sizeof(use));
    memset(cnt, 0, sizeof(cnt));
    memset(mat, 0, sizeof(mat));
    scanf("%d", &row);
    scanf("%s", pre);
    while(row -- > 1){
        scanf("%s", cur);
        for(i=0; cur[i]; i++){
            if(pre[i] == '.') continue;
            a = pre[i] - 'A';
            use[a] = true;
            if(cur[i] == '.') continue;
            b = cur[i] - 'A';
            if(a!=b && mat[b][a] == 0){
                mat[b][a] = 1;
                cnt[a] ++;
            }
        }
        tmp=cur, cur=pre, pre=tmp;
    }
    for(i=0; pre[i]; i++){
        if(pre[i] == '.') continue;
        a = pre[i] - 'A';
        use[a] = true;
    }
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst --){
        readIn();
        fun();
        if(tst) printf("\n");
    }
    return 0;
}


#include<iostream>

// 欧拉路径的判断，将开头字母到尾字母视为一个通路
using namespace std;
enum {
    SIZ = 26,
};
int in[SIZ];
int out[SIZ];
int tab[SIZ][SIZ];
int mask[SIZ];

void readIn(){
    static char buf[1004];
    int t, len;
    int a, b;
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(tab, 0, sizeof(tab));
    memset(mask, 0, sizeof(mask));
    scanf("%d ",&t);
    while(t--){
        scanf("%s", buf);
        len = strlen(buf) - 1;
        a = buf[0] -'a';
        b = buf[len] - 'a';
        in[b] ++;
        out[a]++;
        tab[a][b] = tab[b][a] = 1;
    }
}
int dfs(int t){
    int ans = 1;
    for(int i=0;i<SIZ;i++){
        if(tab[t][i] && mask[i] == 0){
            mask[i] = 1;
            ans += dfs(i);
        }
    }
    return ans;
}

// 判断图的连通性，是否所有结点都可以从某一结点到达
int check_conn(){
    int num = 0, i, last;
    for(i=0; i<SIZ; i++){
        if(in[i] || out[i]){
            num ++;
            last = i;
        }
    }
    mask[last] = 1;
    last = dfs(last);
    return last == num;
}
int fun(){
    if(check_conn() == 0)
        return 0;
    int l = 0 ,g = 0;
    for(int i=0;i<SIZ;i++){
        if(in[i] == out[i]){
            ;
        } else if(in[i] > out[i]){
            if(in[i] > out[i] + 1)
                return 0;
            g ++;
        } else {
            if(in[i] < out[i] - 1){
                return 0;
            }
            l ++;
        }
    }
    // 欧拉通路
    if(l==0 && g ==0)
        return 1;
    //欧拉路径
    if(l==1 && g==1)
        return 1;
    return 0;
}
int main(){
    int tstcase, t;
    const char *ans[2] = {
        "The door cannot be opened.",
        "Ordering is possible."
    };
    scanf("%d ", &tstcase);
    while(tstcase --){
        readIn();
        t = fun();
        printf("%s\n", ans[t]);
    }
	return 0;
}

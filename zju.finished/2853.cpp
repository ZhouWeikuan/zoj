#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 208,
};
// 这个用的是模拟法，时间刚好能过
// 可以换种方法，先计算出路径，再计算每个路径的长度，转换率
const double eps = 1e-8;
int     num, proc;
char    use[SIZ];
double  tab[2][SIZ];
double  mat[SIZ][SIZ];
queue<int> que[2];

int readIn(){
    scanf("%d%d", &num, &proc);
    if(num == 0) return 0;
    int i, a, b;
    double p;
    memset(use, 0, sizeof(use));
    memset(mat, 0, sizeof(mat));
    for(i=0; i<num; i++){
        scanf("%lf", &tab[0][i]);
    }
    scanf("%d",&i);
    while(i--){
        scanf("%d%d%lf",&a,&b,&p);
        mat[a][b] = p;
    }
    return num;
}
void dfs(int d){
    use[d] = 1;
    queue<int> q;
    q.push(d);
    que[0].push(d);
    int cur, i;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(i=0; i<num; i++){
            if(use[i]) continue;
            if(mat[i][cur] > eps){
                use[i] = 1;
                que[0].push(i);
                q.push(i);
            }
        }
    }
}
void fun(){
    dfs(num - 1);
    int pred = 0, cur = 1, i, t;
    double sum, part;
    while(proc--){
        memset(tab[cur], 0, sizeof(tab[0]));
        while(!que[pred].empty()){
            t = que[pred].front();  que[pred].pop();
            sum = part = 0;
            for(i=0; i<num; i++){
                if(mat[t][i] < eps) continue;
                part = mat[t][i] * tab[pred][t];
                sum += part;
                tab[cur][i] += part;
            }
            tab[cur][t] += tab[pred][t] - sum;
            bool flag = false;
            if(tab[cur][t] < eps){
                for(i=0; i<num;i++){
                    if(!use[i]) continue;
                    if(mat[i][t] > eps){
                        flag = true; 
                        break;
                    }
                }
            } else {
                flag = true;
            }
            if(flag){
                que[cur].push(t);
            } else {
                use[t] = 0;
            }
        }
        pred = 1 - pred;
        cur  = 1 - cur;
        if(que[pred].size() == 1){
            break;
        }
    }
    printf("%.0lf\n", tab[pred][num-1]);
    while(!que[pred].empty()){
        que[pred].pop();
    }
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}


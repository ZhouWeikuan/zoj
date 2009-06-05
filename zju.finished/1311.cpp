#include<iostream>
//求割点
//对于根: 可以扩展成多个子树
//对于其它点:  至少有一个子树无法到达父结点的祖先
using namespace std;
enum {
    SIZ = 108,
};
int tab[SIZ][SIZ];
int mark[SIZ];
int num, ans, ts;

void readIn(){
    int i,a,b;
    char ch;
    memset(tab, 0 , sizeof(tab));
    memset(mark, 0 , sizeof(mark));
    scanf("%d%c", &a, &ch);
    while(a){
        a --;
        while(ch != '\n'){
            scanf("%d%c", &b, &ch);
            b --;
            tab[a][b] = tab[b][a] = 1;
        }
        scanf("%d%c", &a, &ch);
    }
}

int search(int cur){
    int cnt = 0, t;
    int flag = 0;
    int p = mark[cur] = ts++;
    int min = p;
    for(int i=0;i<num;i++){
        if(tab[cur][i] == 0)
            continue;
        t = i;
        if(mark[t]==0){
            t = search(t);
            cnt++;
            if(t >= p){
                flag  = 1;
            }
            if(t < min)
                min = t;
        } else if(mark[t] < min){
            min = mark[t];
        }
    }
    if(cur == 0){
        if(cnt > 1)
            ans++;
    } else {
        ans += flag;
    }
    return min;
}

void fun(){
    ts = 1;
    ans = 0;
    search(0);
    for(int i=0;i<num;i++){
        if(mark[i] == 0){
            ans = 0; break;
        }
    }
    printf("%d\n", ans);
}

int main(){
    
    scanf("%d", &num);
    while(num){
        readIn();
        fun();
        scanf("%d", &num);
    }

	return 0;
}

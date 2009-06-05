#include<iostream>
#include<cmath>
using namespace std;
enum {
	SIZ = 10004,
};
struct Node {
    short cnt;
    short tail;
};
int num;
int pr[1300], pos;
Node tr[SIZ] = {0};

void init(){
    pos = 0; pr[pos++] = 2;
    bool flag;
    int cur, i, j, t;
    tr[2].cnt = 1;
    for(cur=3;cur<10001; cur++){
        flag = true;
        for(i=0; i<pos&&pr[i]*pr[i] <= cur; i++){
            if(cur%pr[i]==0){
                flag = false;
                break;
            }
        }
        if(flag){ // 质数
            pr[pos++] = cur;
            tr[cur].cnt = 1;
            tr[cur+2].cnt = 2;  // 加2后的非质数
            tr[cur+2].tail = cur;
        }
    }
    int lim;
    tr[4].cnt = 2; tr[4].tail = 2;
    i = 0;
    pr[pos++] = SIZ;
    for(cur=6;cur<SIZ;cur++){
        if(tr[cur].cnt != 0) continue;
        lim = cur/3;
        while(pr[i] < lim){
            i++;
        }
        tr[cur].cnt = 3; tr[cur].tail = cur;
        for(j=i; pr[j]<cur; j++){
            if(tr[cur-pr[j]].cnt == 1){ // 两个
                if(tr[cur].cnt != 2){
                    tr[cur].cnt = 2;
                    tr[cur].tail = max(pr[j], cur - pr[j]);
                } else {
                    t = max(pr[j], cur - pr[j]);
                    tr[cur].tail = min((int)tr[cur].tail, t);
                }
            } else if(tr[cur].cnt == 3){ // 三个
                t = max(pr[j], (int)tr[cur-pr[j]].tail);
                tr[cur].tail = min(t, (int)tr[cur].tail);
            }
        }
    }
}

void fun(int n){
    printf("%d\n", tr[n].cnt);
    if(n < 2) return;
    if(tr[n].cnt == 1){
        printf("%d\n", n);
        return;
    } else if(tr[n].cnt == 2){
        printf("%d %d\n", tr[n].tail, n - tr[n].tail);
        return;
    }
    int t = n - tr[n].tail;
    printf("%d %d %d\n", tr[n].tail, tr[t].tail, t - tr[t].tail);
}

int main(){
	int n; 	
	init();

	while( scanf("%d",&n) > 0){
        fun(n);
	}
    
    return 0;
}


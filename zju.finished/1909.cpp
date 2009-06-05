#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
int num, ed;
int d[24];
int sum[24];
char m[24];

// f  :  start index for current sum
// nf :  start index for next sum
// s  :  current sum value
// cnt:  current finished sum
int dfs(int f, int nf, int s, int cnt){
    if(s + sum[f] < ed || f >= num) return 0;
    if(s == ed){
        s = 0, cnt++;
    }
    if(cnt >= 3) return 1;
    if(m[f] == 0){
        m[f] = 1;
        s += d[f];
        int t = (nf == f);
        if(s == ed){
            if(dfs(nf+t, nf+t, 0, cnt+1)) 
                return 1;
            m[f] = 0;
            return 0;
        } else if(s < ed){
            if( dfs(f+1, nf+t, s, cnt)) 
                return 1;
        }
        m[f] = 0;
        s -= d[f];
    }
    if(dfs(f+1, nf, s, cnt)) 
        return 1;
    return 0;
}
int fun(){
    if(ed % 4 ) return 0;
    ed /= 4;
    m[0] = 1;
    return dfs(1, 1, d[0], 0);
}

void readIn(){
    scanf("%d",&num);
    ed = 0;
    for(int i=0; i<num; i++){
        scanf("%d", &d[i]);
        ed += d[i];
        m[i] = 0;
    }
    sort(d, d+num, greater<int>());
    sum[num] = 0;
    for(int i=num-1;i>=0;i--){
        sum[i] = sum[i+1] + d[i];
    }
}
int main(){
    int tst;
    const char *ans[2] = {"no", "yes"};
    scanf("%d",&tst);
    while(tst--){
        readIn();
        printf("%s\n", ans[fun()]);
    }

    return 0;
}


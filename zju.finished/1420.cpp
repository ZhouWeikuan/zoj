#include<iostream>
/* Cashier Employment */
using namespace std;
enum {
    SIZ = 24,
};
int num;
int req[SIZ], app[SIZ], sum[SIZ], use[SIZ];

inline void update(int i, int v){
    app[i] -= v;
    use[i] += v;
    for(int j=0; j<8; j++){
        sum[(i+j)%SIZ] += v;
    }
}

int fun(){
    int cnt;
    int i,j,t;
    cnt = 0;
    for(i=0; cnt < SIZ; i=(i+1)%SIZ){
        cnt++;
        if(sum[i] == req[i]) continue;
        if(sum[i] > req[i] && use[i] > 0){ // self is over used.
            j = (i + 1)%SIZ;
            if(app[j] <=0) continue; // his partner can help him, so cut him.
            t = min(use[i], sum[i] - req[i]);
            update(i, -t);
            cnt = 0;
        } else if(sum[i] < req[i]){ // self is not enough
            j = 0;
            while(sum[i] < req[i] && j < 8){ // use front of him to help him.
                t = min(req[i]-sum[i], app[(i+SIZ-j)%SIZ]);
                update((i+SIZ-j)%SIZ, t);
                j++;
            }
            if(sum[i] < req[i])
                return -1;
            cnt = 0;
        }
    }
    t = 0;
    for(i=0; i<SIZ; i++){
        t += use[i];
    }
    return t;
}

void readIn(){
    int i, t;
    for(i=0; i<SIZ; i++){
        scanf("%d", &req[i]);
    }
    memset(app, 0, sizeof(app));
    memset(sum, 0, sizeof(sum));
    memset(use, 0, sizeof(use));
    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%d", &t);
        app[t]++;
    }
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        int t = fun();
        if(t < 0){
            printf("No Solution\n");
        } else {
            printf("%d\n", t);
        }
    }
    return 0;
}


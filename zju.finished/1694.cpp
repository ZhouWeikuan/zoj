#include<iostream>
using namespace std;
enum {
    SIZ = 8,
    Ok = 0,
    Error = 1,
    Reject = 2,
};
int targ;
int val, len, state;
int save[SIZ];
int mark[SIZ];
char buf[SIZ];
void dfs(int v, int s){
    if(v > targ)
        return;
    if(s == len){
        if(v > val){
            val = v;
            state = Ok;
            for(int i=0;i<len;i++){
                save[i] = mark[i];
            }
        } else if(v == val){
            state = Reject;
        }
        return;
    }
    int t = 0;
    for(int i=s;i<len;i++){
        t *= 10;
        t += buf[i] -'0';
        mark[i] = 1;
        if(v + t > targ)
            break;
        dfs(v + t, i + 1);
        mark[i] = 0;
    }
}
void trace(){
    printf("%d", val);
    int t = 0;
    for(int i=0;i<len;i++){
        t *= 10; 
        t += buf[i] - '0';
        if(save[i] ==1){
            printf(" %d", t);
            t = 0;
        }
    }
    printf("\n");
}
int fun(){
    int v = 0;
    state = Error;
    for(int i=0;i<len;i++){
        v *= 10;
        v += buf[i] - '0';
        if(v > targ)
            break;
        mark[i] = 1;
        dfs(v, i+1);
        mark[i] = 0;
    }
    return state;
}
int main(){
    const char *ans[3] = {
        "","error","rejected",
    };
    int t;
    scanf("%d%s",&targ, buf);
    while(targ!=0 || buf[1]!=0 || buf[0] !='0'){
        val = 0, len = strlen(buf);
        memset(save,0,sizeof(save));
        memset(mark,0,sizeof(mark));
        if( (t=fun())!=Ok){
            printf("%s\n", ans[t]);
        } else {
            trace();
        }
        scanf("%d%s",&targ, buf);
    }

    return 0;
}


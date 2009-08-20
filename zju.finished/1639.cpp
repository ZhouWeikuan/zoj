#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
enum {
    LEN = 16,
    SIZ = 1<<LEN,
};

struct cmp{
    bool operator()(const char*const a, const char*const b)const{
        return strcmp(a, b) < 0;
    }
};

int num;
int val[LEN];
int sum[LEN+1];
char name[LEN][LEN];
vector<int> con[LEN];
int ans;

void dfs(int d, int s, int v){
    if (d >= num){
        ans = max(ans, v);
        return;
    }
    if (v + sum[d] <= ans)
        return;
    s |= (1<<d);
    bool f = true;
    for (int i=0; i<con[d].size(); ++i){
        int t = con[d][i];
        if ((s&t) == t){
            f = false;
            break;
        }
    }
    if (f)
        dfs(d+1, s , v + val[d]);
    s &= ~(1<<d);
    dfs(d+1, s, v);
}

void fun(){
    ans = 0;
    dfs(0, 0, 0);
    static int tst = 1;
    printf("System %d: %d\n", tst++, ans);
}

int getPos(char *s){
    for (int i=0; i<num; ++i){
        if (strcmp(s, name[i])==0)
            return i;
    }
    return -1;
}

void parse(){
    int n;
    static char buf[LEN*LEN];
    const char *del = " \n\t\r";
    scanf("%d ", &n);
    unsigned msk;
    while(n--){
        int pos = 0, t = 0;
        fgets(buf, LEN*LEN, stdin);
        char *p=strtok(buf, del);
        msk = 0;
        while(p!=NULL){
            pos = getPos(p);
            msk |= 1<<pos;
            t = max(t, pos);
            p = strtok(NULL, del);
        }
        con[t].push_back(msk);
    }
}

int readIn(){
    scanf("%d", &num);
    if(num==0) return 0;
    for(int i=0; i<num; i++){
        scanf("%s%d", name[i], &val[i]);
        con[i].clear();
    }
    sum[num] = 0;
    for (int i=num-1; i>=0; --i){
        sum[i] = sum[i+1] + val[i];
    }
    parse();
    return num;
}

int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}


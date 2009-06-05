#include<iostream>
#include<string>
using namespace std;
enum {
    SIZ = 24,
    NUM = 800,
};
int tab[SIZ][SIZ];
int cnt[SIZ];
int mask[SIZ];
int M,N;
char buf[NUM];

void parse(int r, char *s){
    int t;
    while(*s){
        t = 0;
        while(isdigit(*s)){
            t *= 10; t+= *s-'0';
            s++;
        }
        tab[r][t]++;
        tab[t][r]++;
        cnt[r]++;
        cnt[t]++;
        if(*s == ' '){
            s++;
        }
    }
}

int readIn(){
    string s;
    cin>>s;
    if(s=="ENDOFINPUT")
        return 0;
    cin>>M>>N;
    memset(tab,0,sizeof(tab));
    memset(cnt, 0, sizeof(cnt));
    memset(mask,0,sizeof(mask));
    cin.getline(buf, NUM);
    for(int i=0;i<N;i++){
        cin.getline(buf,NUM);
        parse(i, buf);
    }
    cin>>s; // for END
    return 1;
}
int dfs(int m){
    if(mask[m])
        return 0;
    int ret = 1;
    mask[m] = 1;
    for(int i=0;i<N;i++){
        if(tab[m][i]){
            ret += dfs(i);
        }
    }
    return ret;
}
int fun(){
    int d = dfs(M);
    int t = 0, ret = 0;
    int odd = 0, even = 0;
    for(int i=0;i<N;i++){
        if(cnt[i]) {
            t++;
            ret += cnt[i];
            if(cnt[i]%2==0){
                even ++;
            } else {
                odd ++;
            }
        }
    }
    if(M==0&&t ==0) // no door opened
        return 1;
    else if(d!= t) // not connected.
        return 0;
    if(M==0){// circuit
        if(odd)
            return 0;
    } else {// euler path
        if(odd!=2)
            return 0;
        if(cnt[M]%2!=1 || cnt[0]%2!=1)
            return 0;
    }
    return ret/2 + 1;
}

int main(){
    const char *ans[2] = {"NO", "YES"};
    int t;
    while(readIn()){
        t = fun();
        if(t==0){
            cout<<ans[t]<<endl;
        } else {
            cout<<ans[1]<<" "<<(t-1)<<endl;
        }
    }

    return 0;
}

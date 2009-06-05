#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
enum {
    SIZ = 604,
    LEN = 12,
};
struct Node {
    int  tail, head;
    char str[LEN];
};
Node d[SIZ];
int tab[2][SIZ];
int L, num, len, pos;
map<string, int> uni;
map<string, int>::iterator it;

void readIn(){
    int i;
    pos = 0;
    uni.clear();
    for(i=0; i<num; i++){
        scanf("%s", d[i].str);
        if(i == 0) len = strlen(d[0].str);
        string s(d[i].str, d[i].str+len-1);
        it = uni.find(s);
        if(it != uni.end()){
            d[i].head = it->second;
        } else {
            uni.insert(make_pair(s, pos));
            d[i].head = pos++;
        }
    }
    for(i=0; i<num; i++){
        string s(d[i].str+1);
        it = uni.find(s);
        if(it != uni.end()){
            d[i].tail = it->second;
        } else {
            uni.insert(make_pair(s, pos));
            d[i].tail = pos++;
        }
    }
}
int calc(){
    int *cur=tab[0], *pre=tab[1], *tmp;
    int i,j, lim, t;
    memset(pre, 0, sizeof(int)*pos);
    for(i=0; i<num; i++){
        pre[d[i].tail] ++;
    }
    lim = L - len;
    while(lim--){
        memset(cur, 0, sizeof(int)*pos);
        for(i=0; i<num; i++){
            cur[d[i].tail] += pre[d[i].head];
        }
        tmp=pre; pre=cur; cur=tmp;
        t = 0;
        for(i=0; i<pos;i++){
            t += pre[i];
        }
        if(t == 0){
            break;
        }
    }
    return t;
}
int fun(){
    int ret;
    if(len == 1){ // 多种情况判断
        ret = 1;
        for(int i=0; i<L; i++){
            ret *= num;
        }
        return ret;
    } else if(len > L){ // 防止TLE
        return 0;
    } else if(len == L){
        return num;
    }
    return calc();
}
int main(){
    int t;
    scanf("%d%d%d",&t,&L,&num);
    while(t + L + num){
        readIn();
        printf("%d\n",fun());
        scanf("%d%d%d",&t,&L,&num);
    }

    return 0;
}


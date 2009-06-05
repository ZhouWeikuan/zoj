#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 20,
};
int r[8];
map<int, int> tab;
int num, val, cur, cnt;
char buf[SIZ];

int inline right_shift(int v){
    return ((v&0x01)<<(num-1))|(v>>1);
}
int getleast(int v){
    int i, ret =v;
    for(i=0; i<num; i++){
        v = right_shift(v);
        if(v < ret) ret = v;
    }
    return ret;
}
int combine(char *s, char a = 0){
    int v = 0;
    for(int i=0; i<num; i++){
        v <<= 1;
        v += (s[i]-a);
    }
    return v;
}
int inline lol(int p){
    if(p >= num){
        p -= num;
    }
    return (p>=0?p:(num+p));
}
void unpack(int v){
    for(int i=0; i<num; i++){
        buf[i] = (v>>(num-i-1)) & 0x01;
    }
}
int build(int p){
    int t = 0;
    t = (t<<1) + buf[lol(p-2)];
    t = (t<<1) + buf[p];
    t = (t<<1) + buf[lol(p+1)];
    return t;
}
int subs(int v){
    int i,j;
    static char vt[SIZ];
    unpack(v);
    for(j=0; j<num; j++){
        vt[j] = r[build(j)];
    }
    return getleast(combine(vt));
}
void output(int v){
    unpack(v);
    for(int i=0; i<num;i++){
        buf[i] +='a';
    }
    buf[num] = 0;
    printf("%s\n", buf);
}
void fun(){
    tab.clear();
    cur = 0;
    while(tab.find(val) == tab.end() && cur < cnt){
        tab.insert(make_pair(val, cur++));
        val = subs(val);
    }
    if(cur == cnt){
        output(val);
    } else {
        map<int,int>::iterator it = tab.find(val);
        int t = it->second;
        cnt = (cnt - t)%(cur - t) + t;
        for(it=tab.begin(); it!=tab.end() && it->second!=cnt; ++it)
            ;
        output(it->first);
    }
}
int readIn(){
    if(scanf("%d",&num) < 0) return 0; 
    scanf("%s", buf);
    val = combine(buf, 'a');
    int t;
    for(int i=0; i<8; i++){
        scanf("%s", buf);
        t = 0;
        t = (t<<1) + (buf[0]-'a');
        t = (t<<1) + (buf[1]-'a');
        t = (t<<1) + (buf[2]-'a');
        r[t] = buf[3] - 'a';
    }
    scanf("%d ", &cnt);
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}


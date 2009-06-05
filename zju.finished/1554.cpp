#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    int cnt;
    int len;
    int ptr; // the first place it split
    int update;
};
Node tree[SIZ][SIZ];
int tstcase = 0, num;
char buf[SIZ];
char temp[SIZ];

int num2len(int d){
    int r = 0;
    do {
        r++;
        d /= 10;
    }while(d > 0);
    return r;
}
void calc(int s, int e){
    if(e <= s|| tree[s][e].update >= tstcase)
        return;
    tree[s][e].update = tstcase;
    //设置初始情况
    tree[s][e].cnt = 1;
    tree[s][e].len = e - s;
    tree[s][e].ptr = s + 1;
    for(int i=s+1; i<e;i++){
        calc(s,i); calc(i,e);
        if(tree[s][i].len + tree[i][e].len < tree[s][e].len){
            tree[s][e].ptr = i;
            tree[s][e].len = tree[s][i].len + tree[i][e].len;
        }
        //测试是否可以合并
        if((e-s)%(i-s) == 0){
            int j;
            for(j=i;j<e;j+=i-s){
                if(strncmp(&buf[s], &buf[j], i-s)!=0)
                    break;
            }
            if(j==e){ // 考虑合并长度
                int c = (e-s)/(i-s);
                int l = num2len(c) + 2;
                l += tree[s][i].len;
                if(l < tree[s][e].len){
                    tree[s][e].len = l;
                    tree[s][e].cnt = c;
                    tree[s][e].ptr = i;
                }
            }
        }
    }
}

void trace(int s, int e){
    if(e - s == 1){
        printf("%c", buf[s]);
        return;
    }
    if(tree[s][e].cnt > 1){
        printf("%d(", tree[s][e].cnt);
        trace(s, tree[s][e].ptr);
        printf(")");
    } else {
        trace(s, tree[s][e].ptr);
        trace(tree[s][e].ptr, e);
    }
}
int main(){

    while(scanf("%s",buf) > 0){
        ++tstcase;
        num = strlen(buf);
        calc(0,num);
        trace(0, num);
        printf("\n");
    }

    return 0;
}

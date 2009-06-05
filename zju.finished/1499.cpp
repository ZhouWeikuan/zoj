#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 84,
};
int len;
char dat[SIZ];
int ptr[SIZ][SIZ];
int sl, sp[SIZ];
int pl, pp[SIZ];

// [a,b) <=> [c,d)
int cmp(int a, int b, int c, int d){
    for(;a<b&&dat[a]=='0';a++);
    for(;c<d&&dat[c]=='0';c++);
    if(b-a!=d-c) return (b-a+c-d);
    for( ;a<b; a++,c++){
        if(dat[a]!=dat[c]) return dat[a]-dat[c];
    }
    return 0;
}
void output(){
    int p = sl-2, i=0;
    while(p>=0){
        while(i<sp[p]){
            printf("%c", dat[i]);
            i++;
        }
        if(sp[p] != len){
            printf(",");
        }
        p--;
    }
    printf("\n");
}

bool expand(int *pt, int&l, int t, int i){
    l = 0;
    pt[l++] = i;
    int v;
    while(t!=0){
        v = ptr[t][i];
        if(v == len) return false;
        i = t;
        t = v;
        pt[l++] = i;
    }
    pt[l++] = t;
    return true;
}

int sp_vs_pp(){
    int v = 0;
    for(int m=sl-1, n=pl-1; v==0 ; m--,n--){
        v = cmp(sp[m], sp[m-1], pp[n], pp[n-1]);
    }
    return v;
}

bool dp(int i, int j){
    if(ptr[i][j] >= len) return false;
    if(i==0){
        ptr[i][j] = 0;
        return true;
    } else if(ptr[i][j] != -1){
        return expand(sp, sl, ptr[i][j], i);
    }
    for(int t=i-1; t>=0 && cmp(t,i,i,j)<0; t--){
        if( dp(t, i) == false)
            continue;
        if(ptr[i][j] == -1) ptr[i][j] = t;
        else if(expand(sp, sl, t, i)){
            expand(pp, pl, ptr[i][j], i);
            if(sp_vs_pp() > 0){
                ptr[i][j] = t;
            }
        }
    }
    pl--;
    if(ptr[i][j] == -1){
        ptr[i][j] = len;
        return false;
    }
    return true;
}
void fun(){
    int i, v;
    ptr[0][len] = 0;
    for(i=1; i<len; i++){
        if(dp(i, len)){
            v = cmp(i,len, ptr[0][len], len);
            if(v < 0){
                ptr[0][len] = i;
            } else if(v==0){
                expand(sp, sl, i, len);
                expand(pp, pl, ptr[0][len], len);
                if(sp_vs_pp() > 0){
                    ptr[0][len] = i;
                }
            }
        }
    }
    expand(sp, sl, ptr[0][len], len);
    output();
}
int main(){
    scanf("%s", dat);
    while((len=strlen(dat))!=1||dat[0] !='0'){
        memset(ptr, -1, sizeof(ptr));
        fun();
        scanf("%s", dat);
    }
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 128,
};
extern void output_array(int =0);

int tab[2][SIZ];
int sa[SIZ];
vector<int> pre[SIZ];
vector<int> cur[SIZ];
const char str[] = "dadsdssadsdadaddsdasd";
int len, N;
int *preRank, *curRank;

int cmp(int a, int b){
    if(preRank[a] != preRank[b]){
        return preRank[a] - preRank[b];
    }
    return preRank[a+N] - preRank[b+N];
}
void array_sort(){
    int i, t, j, p;
    for(i=0; i<len; i++){
        t = sa[i] + N;
        if(t < len){            
            pre[preRank[t]].push_back(sa[i]);
        } else {            
            pre[0].push_back(sa[i]);
        }
    }    
    for(i=0; i<=len; i++){
        for(j=0; j < pre[i].size(); j++){
            t = pre[i][j];
            cur[preRank[t]].push_back(t);
        }
        pre[i].clear();
    }    
    p = 0;
    for(i=0;i<=len;i++){    
        for(j=0; j < cur[i].size(); ++j){            
            sa[p++] = cur[i][j];
        }
        cur[i].clear();
    }
    p = 1;
    curRank[sa[0]] = 1;
    for(i=1; i<len; i++){
        if(cmp(sa[i], sa[i-1]) != 0){
            ++p;
        }
        curRank[sa[i]] = p;
    }
    int *tmp = preRank;
    preRank = curRank;
    curRank = tmp;
}

void init_array(){
    int i,t;
    memset(curRank, 0, sizeof(tab[0]));
    for(i=0; i<len; i++){
        curRank[str[i]] = 1;
    }
    for(i=1; i<SIZ; i++){
        curRank[i] += curRank[i-1];
    }
    for(i=0; i<len; i++){
        preRank[sa[i]] = curRank[str[sa[i]]];
    }
}
void build_array(){    
    for(len=0; str[len]; len++){
        sa[len] = len;        
    }
    N = 1;
    init_array();
    output_array();
    
    while(N < len){
        array_sort();
        output_array();
        
        N *= 2;
    }
}

void output_array(int flag){
    if(flag == 0)
        return ;
    static int cnt = 0;
    for(int i=0; i<len; i++){
        printf("%s\n", &str[sa[i]]);
    }    
    printf("\n");
}

int main(){
    preRank = tab[0]; curRank = tab[1];
    build_array();
    output_array(1);
    
    return 0;
}


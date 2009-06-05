#include<iostream>
// Runtime error
using namespace std;
struct Team {
    int  cnt;
    char name[12];
    char st[12][20];
};
int tn, pn;
int pro[12];
int idx[308];
Team trp[308];

int cmp(int a, int b){
    if(trp[a].cnt != trp[b].cnt) return -trp[a].cnt + trp[b].cnt;
    return strcmp(trp[a].st[pn],trp[b].st[pn]);
}
struct lessThan {
    bool operator()(const int &a, const int&b)const{
        int v = cmp(a,b);
        if(v == 0 ){
            return strcmp(trp[a].name, trp[b].name) < 0;
        }
        return v < 0;
    }
};

void fun(){
    int i, r = 1, j;
    for(i=0; i<tn; i++){
        if(i && cmp(idx[i], idx[i-1])!=0){
            r++;
        }
        pro[trp[idx[i]].cnt] ++;
        printf("%d %s %d", r, trp[idx[i]].name, trp[idx[i]].cnt);
        for(j=0; j<=pn; j++){
            printf(" %s", trp[idx[i]].st[j]);
        }
        printf("\n");
    }
    printf("Total Teams: %d", tn);
    for(i=pn; i>0; i--){
        if(pro[i]==0) continue;
        printf("; Solved %d: %d", i, pro[i]);
    }
    printf(".\n");
}

int proInfo(char *s){
    scanf("%s", s);
    if(s[0]=='-') return -1;
    if(strcmp(s,"0")==0) return -1;
    s[8] = ' ';
    s += 9;
    scanf("%s", s);
    return 1;
}

int readIn(){
    int sec; 
    if(scanf("%d%d",&sec,&pn)<0)
        return 0;
    memset(pro, 0, sizeof(pro));
    int i,n,r,p;
    tn = 0;
    while(sec--){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            idx[tn+i] = tn + i;
            scanf("%d%s%d", &r, &trp[tn+i].name,&trp[tn+i].cnt);
            for(p=0; p<pn; p++){
                r = proInfo(trp[tn+i].st[p]);
            }
            scanf("%s", trp[tn+i].st[pn]);
        }
        tn += n;
    }
    sort(idx, idx+tn, lessThan());
    return 1;
}

int main(){
    bool f = true;
    while(readIn() > 0){
        if(!f) printf("\n");
        fun();
        f = false;
    }
    return 0;
}


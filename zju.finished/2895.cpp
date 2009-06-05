#include<iostream>
#include<vector>
using namespace std;
// 1. 两数不可共居一槽当且仅当 s[a],e[a]与s[b],e[b]有共同区间
// 2. a,b区间相交时，能让a,b同余的数为abs(b-a)的除数
enum {
    SIZ = 1001,
};
int num, pos;
unsigned s[SIZ], e[SIZ];
unsigned ptr[SIZ];
bool mark[SIZ];
vector<int> fac[SIZ];

void init(){
    int i, j;
    for(i=1;i<SIZ; i++){
        for(j=i; j<SIZ; j+=i){
            fac[j].push_back(i);
        }
    }
}
void erase(const vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        mark[vec[i]] = false;
    }
}
inline bool intersect(int a, int b){
    if(s[b]>e[a] || e[b]<s[a])
        return false;
    return true;
}
void fun(){
    if(num == 0) {
        printf("0\n");
        return;
    }
    memset(s, -1, sizeof(s));
    memset(e, -1, sizeof(e));
    int v,i,j;
    pos = 0;
    for(i=0; i<num; i++){
        scanf("%d", &v);
        if(e[v] == -1){
            s[v] = e[v] = i; 
            ptr[pos++] = v;
        } else {
            e[v] = i;
        }
    }
    sort(ptr, ptr+pos);
    memset(mark, true, sizeof(mark));
    mark[0] = false;
    for(i=0; i<pos; i++){
        for(j=i+1; j<pos; j++){
            if(!intersect(ptr[i], ptr[j]))
                continue;
            erase(fac[ptr[j] - ptr[i]]);
        }
    }
    for(i=0; i<SIZ; i++){
        if(mark[i]) break;
    }
    printf("%d\n", i);
}

int main(){
    init();
    while(scanf("%d", &num) > 0){
        fun();
    }
    return 0;
}


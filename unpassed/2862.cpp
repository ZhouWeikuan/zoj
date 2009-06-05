#include<iostream>
#include<map>
using namespace std;
// Wrong Answer
enum {
    SIZ = 30008,
};
struct Node{
    int ptr;
    int val;
};
Node tree[SIZ];
char cls[SIZ][256];
char buf[256];
struct _cmp{
    bool operator()(const char *a, const char *b)const {
        return strcmp(a,b)<0;
    }
}cmp;
map<const char *, int, _cmp> tab;
map<const char *, int, _cmp>::iterator it;
int pos;

int query(char *s){
    it = tab.find(s);
    if(it != tab.end()){
        return it->second;
    }
    strcpy(cls[pos], s);
    tab.insert(make_pair(cls[pos], pos));
    tree[pos].ptr =  0;
    tree[pos].val = -1;
    return pos++;
}

int dfs(int s){
    if(tree[s].val==-1){
        tree[s].val = dfs(tree[s].ptr);
    }
    return tree[s].val;
}

void fun(){
    int i, n;
    for(i=1; i<pos; i++){
        dfs(i);
    }
    scanf("%d",&n);
    while(n--){
        scanf("%s", buf);
        i = query(buf);
        i = tree[i].val;
        if(i<=0){
            printf("Exception\n");
        } else {
            printf("%s\n", cls[i]);
        }
    }
}

int readIn(){
    int n, a, b;
    if(scanf("%s%d",&buf,&n)<0)
        return 0;
    pos = 0;
    tab.clear();
    query(buf);
    tree[0].val = 0;
    for(; n>0; n--){
        scanf("%s", buf);
        a = query(buf);
        scanf("%s", buf);
        b = query(buf);
        tree[a].ptr = b;
    }
    scanf("%d",&n);
    while(n--){
        scanf("%s", buf);
        a = query(buf);
        tree[a].val = a;
    }
    return 1;
}
int main(){
    int tst=0;
    while(readIn() > 0){
        if(tst) printf("\n");
        printf("Function %d\n", ++tst);
        fun();
    }
    return 0;
}


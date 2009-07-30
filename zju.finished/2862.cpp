#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
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
char buf[256];
string cls[SIZ];
map<string, int> tab;
int pos;

int query(char *s){
    string str(s);
    map<string, int>::iterator it = tab.find(str);
    if(it != tab.end()){
        return it->second;
    }
    cls[pos] = str;
    tab.insert(make_pair(str, pos));
    tree[pos].ptr = -1;
    tree[pos].val = -1;
    return pos++;
}

int dfs(int s){
    if (s < 0) return -2;
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
        if(i<0){
            printf("Exception\n");
        } else {
            printf("%s\n", cls[i].c_str());
        }
    }
}

int readIn(){
    int n, a, b;
    if(scanf("%s%d",&buf,&n)<0)
        return 0;
    pos = 0;
    tab.clear();
    memset(tree, -1, sizeof(tree));
    query(buf);
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


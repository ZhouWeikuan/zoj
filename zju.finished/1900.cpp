#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
enum {
    SIZ = 104,
};
string p[SIZ];
set<int> lis[SIZ];
int n,m;
char buf[40];
struct cmp{
    bool operator()(const int &a, const int &b){
        return p[a] < p[b];
    }
};

void readIn(){
    int i,a,b;
    for(i=1;i<=n;i++){
        lis[i].clear();
    }
    while(fgets(buf, 40, stdin)!=NULL && isdigit(buf[0])){
        sscanf(buf, "%d%d",&a,&b);
        lis[a].insert(b);
    }
}

int fun(){
    set<int, cmp> tab;
    for(int i=1;i<=n;i++){
        p[i] = "";
        for(set<int>::iterator it=lis[i].begin();
                it!=lis[i].end(); it++){
            p[i] += (*it);
        }
        tab.insert(i);
    }
    return tab.size();
}

int main(){
    while(fgets(buf,40, stdin) != NULL){
        if(!isdigit(buf[0]))
            continue;
        sscanf(buf, "%d%d", &n, &m);
        readIn();
        printf("%d\n", fun());
    }

	return 0;
}

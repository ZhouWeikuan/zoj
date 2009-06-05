#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 10008,
};
char tree[SIZ][32];
struct cmp{
    bool operator()(const char*l,const char*r)const{
        return strcmp(l,r)<0;
    }
};
map<const char *, int, cmp> tab;
map<const char *, int, cmp>::iterator it;
char buf[32];
double sum;
int num;

void add(const char *s){
    it = tab.find(s);
    if(it!=tab.end()){
        it->second++;
        return;
    }
    strcpy(tree[num],s);
    tab.insert(make_pair(tree[num],1));
    num++;
}
void output(){
    for(it=tab.begin();it!=tab.end();++it){
        printf("%s %.4lf\n", it->first, 100*it->second/sum);
    }
}
int main(){
    int tstcase = 0;
    while(fgets(buf, 32, stdin) !=NULL && !feof(stdin)){
        if(tstcase++)
            printf("\n");
        tab.clear();
        sum = 0;
        num = 0;
        while(buf[0]!='\n') {
            int t = strlen(buf);
            buf[--t] = 0;
            sum++;
            add(buf);
            if(fgets(buf, 32, stdin)==NULL){
                break;
            }
        }
        output();
    }
    return 0;
}

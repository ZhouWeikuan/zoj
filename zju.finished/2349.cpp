#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 10008,
    ALP = 26,
};
struct Node{
    string w;
    int c, p;
};
Node tree[SIZ];
int pos[SIZ];
struct Cmp {
    bool operator()(const int& a, const int& b) const{
        return tree[a].w.length() < tree[b].w.length();
    }
}cmp;
char alp[ALP+1];
map<string, int> tab;
int top, save, num;

void getKey(const string &s, string&k){
    memset(alp, 0, sizeof(alp));
    int i;
    for(i=0; s[i]; i++){
        alp[s[i]-'a']++;
    }
    for(i=0; i<ALP; i++){
        alp[i] += 'a';
    }
    k = alp;
}
void traceback(int s){
    vector<int> v;
    while(s!= -1){
        v.push_back(s);
        s = tree[s].p;
    }
    for(int i=v.size()-1; i>=0; i--){
        printf("%s\n", tree[v[i]].w.c_str());
    }
}
void fun(){
    int i,j, t;
    string key;
    map<string, int>::iterator it;
    top = save = -1;
    for(i=0; i<num; i++){
        t = pos[i];
        getKey(tree[t].w, key);
        it = tab.find(key);
        if(it != tab.end()) continue;
        for(j=0; key[j]; j++){
            if(key[j] == 'a') continue;
            key[j]--;
            it = tab.find(key);
            if(it!=tab.end() && tree[t].c <= tree[it->second].c){
                tree[t].c = tree[it->second].c + 1;
                tree[t].p = it->second;
            }
            key[j]++;
        }
        tab.insert(make_pair(key, t));
        if(top < tree[t].c){
            top = tree[t].c;
            save = t;
        }
    }
    traceback(save);
}
void readIn(){
    static char buf[24];
    tab.clear();
    num=0;
    while(gets(buf) && buf[0]!=0){
        tree[num].w = buf;
        tree[num].c = 0;
        tree[num].p = -1;
        pos[num] = num;
        num++;
    }
    sort(pos, pos+num, cmp);
}
int main(){
    int tst;
    scanf("%d ", &tst);

    while(tst--){
        readIn();
        fun();
        if(tst) printf("\n");
    }
    return 0;
}


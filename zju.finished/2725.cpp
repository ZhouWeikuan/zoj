#include<iostream>
//不会找其中的规律，只好用trie树来实现了...
using namespace std;
enum {
    SIZ = 8,
    LEN = 160000,
};
struct Node {
    int u;
    Node *next[10];
};
char buf[SIZ];
Node lose = {1};
Node tree[LEN];
int next = 0, top = 0;

bool search_tree(char *s){ // true, in the tree
    Node *cur = &lose;
    while(*s){
        cur = cur->next[*s-'0'];
        if(cur==0)
            return false;
        s++;
    }
    return cur->u;
}
void insert_tree(char *s){
    Node *cur=&lose;
    int t;
    while(*s){
        t = *s -'0';
        if(cur->next[t] == 0){
            cur->next[t] = &tree[next++];
        }
        cur = cur->next[t];
        s++;
    }
    cur->u = 1;
}
inline bool search(char *s){
    if(search_tree(s) == true)
        return false;
    return true;
}
bool calc(char *s){
    bool ret;
    for(int i=0; s[i]; i++){
        if(s[i] == '0'){
            s[i] = 0;
            ret = search(s);
            s[i] = '0';
            if(ret == false)
                goto good_end;
        } else {
            char o = s[i];
            for(char t ='0'; t<o; t++){
                s[i] = t;
                ret = search(s);
                s[i] = o;
                if(ret == false)
                    goto good_end;
            }
        }
    }
bad_end:
    insert_tree(s);
    return false;
good_end:
    return true;
}

inline void inc(){
    int t=6;
    buf[t]++;
    while(buf[t] >'9'){
        buf[t] = '0';
        --t;
        buf[t]++;
    }
    if(t < top)
        top = t;
}
int main(){
    memset(buf,'0',sizeof(buf));
    top = 6; buf[6] = '1'; buf[7] = 0;
    while(top > 0){
        calc(buf+top);
        inc();
    }
    while(cin>>buf){
        if(search_tree(buf)==true){
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }
    }

    return 0;
}

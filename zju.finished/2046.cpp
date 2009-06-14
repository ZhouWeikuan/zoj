#include<iostream>
#include<set>
#include<map>
using namespace std;
/*
 * Your task is simple: locks, once granted, are never released or changed in any way.
 * This description from zoj is wrong, locks once granted, can be upgraded in this case:
 *  1) it is occupied by only one tid
 *  2) its previous lock type is set as S
 *  3) its current lock type is set as X
 * This lock should be upgraded from S to X. We have to guess this case out.
 */
enum {
    SIZ = 104,
};
struct Node {
    set<int> tid;
    char type;
};

map<int, Node> tab; 
map<int, Node>::iterator it;
set<int> none;

bool sameId(set<int> &s, int t){
    return (s.empty() || (s.size()==1&&s.find(t)!=s.end()));
}

bool conflict(Node &o, int tid, char type){
    if (sameId(o.tid, tid)){
        return false;
    } else if (type=='S'&&o.type=='S'){
        return false;
    }
    return true;
}

void fun(){
    char type;
    int id, tid;

    tab.clear(); none.clear();

    scanf("%c%d%d ", &type, &tid, &id);
    while(type!= '#'){
        if (none.find(tid) != none.end()){
            // ignored;
            printf("IGNORED\n");
        } else {
            it = tab.find(id);
            if (it==tab.end()){
                Node one;
                one.tid.insert(tid);
                one.type = type;
                tab.insert(make_pair(id, one));
                printf("GRANTED\n");
            } else if(conflict(it->second, tid, type)){
                none.insert(tid);
                printf("DENIED\n");
            } else {
                if (sameId(it->second.tid, tid) && it->second.type=='S')
                    it->second.type = type;
                it->second.tid.insert(tid);
                printf("GRANTED\n");
            }
        }
        scanf("%c%d%d ", &type, &tid, &id);
    }
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst-- > 0){
        fun();
        if (tst)
            printf("\n");
    }

    return 0;
}


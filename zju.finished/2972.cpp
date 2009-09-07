#include<iostream>
#include<map>
using namespace std;

int N, M;
int T[3], F[3];
map<int, int> tf[2], *cur, *nex, *tmp;
map<int, int>::iterator iter;

void fun(){
    tf[0].clear(); tf[1].clear();
    cur = &tf[0], nex = &tf[1];
    tf[0].insert(make_pair(0, M));
    int t, f;
    for (int i=0; i<N; ++i){
        scanf("%d%d%d%d%d", &T[0], &T[1], &T[2],
                &F[0], &F[2]);
        F[0] = -F[0];
        F[1] = 0;
        nex->clear();
        for(map<int,int>::iterator it=cur->begin();
                it!=cur->end(); ++it){
            for (int j=0; j<3; ++j){
                t = it->first + T[j];
                f = it->second + F[j];
                if (f < 0) continue;
                if (f > M) f = M;
                iter = nex->find(t);
                if (iter==nex->end()){
                    nex->insert(make_pair(t, f));
                }else if(iter->second < f){
                    iter->second = f;
                }
            }
        }
        tmp = cur, cur = nex, nex = tmp;
    }
    iter = cur->begin();
    printf("%d\n", iter->first);
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        scanf("%d%d", &N, &M);
        fun();
    }

    return 0;
}


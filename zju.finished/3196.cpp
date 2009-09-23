#include<iostream>
#include<set>
using namespace std;
int num, dig;
int dat[20];
set<long long> tab[2];

bool test(long long v){
    if (v==0) return dig!=0;
    while(v > 0){
        int t = v % 10; v /= 10;
        if (t == dig) return false;
    }
    return true;
}

void fun(){
    set<long long> *cur=&tab[0], *nex=&tab[1], *tmp; 
    cur->clear();
    cur->insert(dat[0]);
    for (int i=1; i<num; ++i){
        nex->clear();
        for (set<long long>::iterator it=cur->begin(); it!=cur->end(); ++it){
            long long t = *it + dat[i];
            nex->insert(t);

            t = *it - dat[i];
            if (t < 0) t = -t;
            nex->insert(t);

            t = *it * dat[i];
            nex->insert(t);

            if (dat[i]!=0){
                t = *it / dat[i];
                nex->insert(t);
            }
        }

        tmp = cur, cur = nex, nex = tmp;
    }
    long long ans = -1;
    for (set<long long>::reverse_iterator rit = cur->rbegin(); rit!=cur->rend(); ++rit){
        if (test(*rit)){
            ans = *rit;
            break;
        }
    }
    if (ans >= 0){
        printf("%lld\n", ans);
    } else {
        printf("No result\n");
    }
}

void readIn(){
    scanf("%d%d", &num, &dig);
    for (int i=0; i<num; ++i){
        scanf("%d", &dat[i]);
    }
}

int main(){
    int tn;

    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
    }

    return 0;
}


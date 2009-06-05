#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 41,
};
struct Rect{
    int h,l;
    bool operator<(const Rect &r)const{
        if(h != r.h) return h<r.h;
        return l<r.l;
    }
};
vector<Rect> tab[SIZ];
int num, S, side[SIZ];

bool fun(){
    int i, t;
    Rect one,cur;
    for(i=0; i<SIZ; i++){
        tab[i].clear();
    }
    one.h = one.l = S;
    tab[S].push_back(one);
    for(i=num-1; i>=0; i--){
        for(t=side[i]; t<=S ; t++){
            if(tab[t].size() == 0) continue;
            one = tab[t].back();
            tab[t].pop_back();
            if(side[i] == one.l){
                one.h -= side[i];
                if(one.h < one.l){
                    swap(one.h, one.l);
                }
                if(one.l > 0){
                    tab[one.l].push_back(one);
                }
            } else {
                cur.h = side[i], cur.l = one.l - side[i];
                one.h -= side[i]; 
                if(one.h<one.l) swap(one.h, one.l);
                if(cur.h<cur.l) swap(cur.h, cur.l);
                tab[one.l].push_back(one);
                tab[cur.l].push_back(cur);
            }
            break;
        }
        if(t > S) return false;
    }
    return true;
}

bool readIn(){
    int t = 0;
    scanf("%d%d",&S, &num);
    for(int i=0; i<num; i++){
        scanf("%d", &side[i]);
        t += side[i]*side[i];
    }
    sort(side, side+num);
    return S*S==t;
}
int main(){
    int tst;
    bool t;
    const char *ans[2] = {"HUTUTU!", "KHOOOOB!"};
    scanf("%d", &tst);
    while(tst--){
        t = readIn();
        if(t){
            t = fun();
        }
        printf("%s\n", ans[t]);
    }

    return 0;
}


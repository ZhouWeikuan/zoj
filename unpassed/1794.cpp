#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
enum {
    SIZ = 104,
    LIM = 999999999,
};

struct Node;
struct Object {
    int hs, sum;
    Node *par;
    bool operator < (const Object &o) const {
        if (hs == 0) return true;
        else if (o.hs == 0) return false;
        if (sum != o.sum) return sum < o.sum;
        if (sum < hs) return true;
        else if (o.sum <o.hs) return false;
        return hs < o.hs;
    }
};

struct Node {
    int num, p;
    Object obj;
    int dat[SIZ];
    int gen(){
        if (p >= num) return 0;
        obj.hs = obj.sum = 0;
        if (dat[p] > 0){
            while(p < num && dat[p] >= 0){
                obj.sum += dat[p];
                ++p;
            }
        }
        obj.hs = obj.sum;
        while (p < num && dat[p] <= 0){
            obj.sum += dat[p];
            ++p;
        }
        return 1;
    }
    int readIn() {
        num = p = 0;
        obj.par = this;
        scanf("%d", &dat[num]);
        while(dat[num]!=9999 && dat[num]!=-9999){
            ++num;
            scanf("%d", &dat[num]);
        }
        return dat[num] == 9999;
    }
};

int sn;
Node tree[6];

int grade(Object &o){
    if (o.hs == 0 && o.sum < 0)
        return 10;
    if (o.sum < 0)
        return 9;
    if (o.sum < o.hs)
        return 8;
    return 0;
}

int fetch(vector<Object> &v){
    int sel = -1, sg = -1;
    for (int i=0; i<v.size(); ++i){
        int t = grade(v[i]);
        if (sg < t){
            sg = t;
            sel = i;
        } else if (sg == t){
            if (v[sel].hs > v[i].hs){
                sel = i;
            }
        }
    }
    return sel;
}

void fun(){
    int hs = 0, sum = 0;
    vector<Object> tab;
    for (int i=0; i<sn; ++i){
        tree[i].gen();
        tab.push_back(tree[i].obj);
    }
    while(!tab.empty()){
        int sel = fetch(tab);
        // printf("hs=%d, sum=%d\n", tab[sel].hs, tab[sel].sum);
        int t = sum + tab[sel].hs;
        if (hs < t){
            hs = t;
        }
        sum += tab[sel].sum;
        if(!tab[sel].par->gen()){
            swap(tab[sel], tab.back());
            tab.pop_back();
        } else {
            tab[sel] = tab[sel].par->obj;
        }
    }
    printf("%d\n", hs);
}

void readIn(){
    sn = 0;
    while(tree[sn].readIn()){
        ++sn;
    }
    ++sn;
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


#include<iostream>
#include<string>
#include<set>
#include<cstdio>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
    LIM = 999999999,
};
int dat[SIZ];

struct Node;
struct Object {
    int hs, sum;
    int no;
    Node *ptr;
    bool operator < (const Object &o) const {
        return max(hs, sum + o.hs) < max(o.hs, o.sum + hs);
    }
};

Object sys;

struct Node {
    int num;
    Object obj[SIZ];
    void gen(){
        int pos = 0, i=0;
        memset(obj, 0, sizeof(obj));
        while(i < num && dat[i] <= 0){
            sys.sum += dat[i];
            ++i;
        }
        while(i < num){
            while(i<num&&dat[i]>=0){
                obj[pos].hs += dat[i];
                obj[pos].sum += dat[i];
                ++i;
            }
            while(i<num&&dat[i]<=0){
                obj[pos].sum += dat[i];
                ++i;
            }
            obj[pos].ptr = this;
            obj[pos].no = pos;
            ++pos;
        }
        num = pos;
    }
    int readIn() {
        num = 0;
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

void fun(){
    set<Object> os;
    for (int i=0; i<sn; ++i){
        if (tree[i].num){
            os.insert(tree[i].obj[0]);
        }
    }

    while(!os.empty()){
        Object cur = *os.begin();
        os.erase(os.begin());
        int hs = sys.sum + cur.hs;
        if (hs > sys.hs){
            sys.hs = hs;
        }
        sys.sum += cur.sum;
        int no = cur.no + 1;
        if (no < cur.ptr->num){
            os.insert(cur.ptr->obj[no]);
        }
    }
    printf("%d\n", sys.hs);
}

void readIn(){
    memset(&sys, 0, sizeof(sys));
    sn = 0;
    while(tree[sn].readIn()){
        tree[sn].gen();
        ++sn;
    }
    tree[sn].gen();
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


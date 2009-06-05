#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<set>

/* 使用离散化方法计算此类问题  */
using namespace std;
enum {
    SIZ = 104,
};
const double eps = 1e-6;
struct Rect {
    double lo_x;
    double lo_y;
    double hi_x;
    double hi_y;
};
struct Node {
    int no;     // the sequence in the tree
    int flag;   // Enter(0) or Exit(1)
    double bound;
    struct cmp{
        bool operator()(const Node&a, const Node&b){
            if(fabs(a.bound - b.bound) < eps){
                return a.flag < b.flag;
            }
            return a.bound < b.bound;
        }
    };
};

Rect tree[SIZ];
Node point[SIZ * 2];
int num;

void readIn(){
    int t;
    for(int i=0; i < num; i++){
        cin >> tree[i].lo_x >> tree[i].lo_y
            >> tree[i].hi_x >> tree[i].hi_y;
        t = 2 * i;
        point[t].no     = i;
        point[t].flag   = 0;
        point[t].bound  = tree[i].lo_x;
        
        t++;
        point[t].no     = i;
        point[t].flag   = 1;
        point[t].bound  = tree[i].hi_x;
    }
}

double calc( set<int> &cur){
    vector<Node> v;
    Node one;
    int t;
    for(set<int>::iterator it = cur.begin();
            it!=cur.end();
            it++){
        t       = *it;
        one.no  = t ;
        one.flag = 0;
        one.bound = tree[t].lo_y;
        v.push_back(one);

        one.flag = 1;
        one.bound = tree[t].hi_y;
        v.push_back(one);
    }
    sort(v.begin(), v.end(), Node::cmp());
    double ret = 0, low = 0;
    t = 0;
    for(vector<Node>::iterator it = v.begin();
            it != v.end();
            it ++){
        if( it->flag == 0){
            if(t == 0){
                low = it->bound;
            }
            t ++;
        } else {
            if(-- t == 0){
                ret += it->bound - low;
            }
        }
    }
    return ret;
}

double fun(){
    double ret = 0.0;
    sort(point, point + 2*num, Node::cmp());
    double low_bound = point[0].bound;
    double t;
    set<int> cur;
    cur.clear();
    cur.insert(point[0].no);
    for(int i=1; i< 2*num; i++){
        if(point[i].flag == 0){ // Enter
            t = calc(cur);
            ret += t * (point[i].bound - low_bound);
            cur.insert(point[i].no);
        } else { // Exit
            t = calc(cur);
            ret += t * (point[i].bound - low_bound);
            cur.erase( point[i].no);
        }
        low_bound = point[i].bound;
    }

    return ret;
}

int main(){
    int tstcase = 0;
    cin>>num;
    while(num){
        cout<< "Test case #" << ++tstcase << endl;
        readIn();
        cout<< "Total explored area: "
            << setiosflags(ios::fixed)
            << setprecision(2)
            << fun()
            << endl 
            << endl;

        cin>>num;
    }

	return 0;
}

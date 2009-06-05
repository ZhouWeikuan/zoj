#include<iostream>
#include<cmath>
#include<set>
// 使用离散化？
//  在pku上WA了，可能是数据的处理有问题！
using namespace std;
enum {
    SIZ = 1004,
};
typedef int(*cmp_t)(const void*, const void*);
struct Point {
    double x,y;
    int mark;
};
struct Node {
    double val;
    int no;
    int flag; // 0, enter, 1, exit;
};
int n,d;
Point tree[SIZ];
Node  bound[SIZ*2];
const double eps = 1e-7;

int cmp(const Point *a, const Point *b){
    if(fabs(a->x - b->x) <= eps){
        return 0;
    }
    if(a->x < b->x){
        return -1;
    }
    return 1;
}
int boundcmp(const Node *a, const Node *b){
    if( fabs(a->val - b->val) <= eps){
        return (a->flag - b->flag);
    }
    if(a->val < b->val)
        return -1;
    return 1;
}

int fun(){
    int i, val;
    int bnum = 0;
    for(i=0;i<n;i++){
        scanf("%lf%lf ", &tree[i].x, &tree[i].y);
        tree[i].mark = 0;
    }
    double t;
    for(i=0;i<n;i++){
        t = d * d - tree[i].y * tree[i].y;
        if(t < 0)
            return -1;
        t = sqrt(t);
        tree[i].y = tree[i].x + t;
        tree[i].x = tree[i].x - t;
        bound[bnum].val = tree[i].x; bound[bnum].flag = 0; 
        bound[bnum].no  = i; bnum++;
        bound[bnum].val = tree[i].y; bound[bnum].flag = 1;
        bound[bnum].no  = i; bnum++;
    }
    qsort(tree, n, sizeof(tree[0]), (cmp_t)cmp);
    qsort(bound, bnum, sizeof(bound[0]), (cmp_t) boundcmp);

    set<int> tab;
    val = 0;
    for(i=0;i<bnum;i++){
        if(tree[bound[i].no].mark == 1)
            continue;
        if(bound[i].flag ==0){
            tab.insert(bound[i].no);
            continue;
        }
        // flag == 1
        val ++;
        for(set<int>::iterator it=tab.begin();
                it!= tab.end(); it++){
            tree[*it].mark = 1;
        }
        tab.clear();
    }
    return val;
}

int main(){
    int tstcase = 0;

    scanf("%d%d ",&n,&d);
    while(n + d){
        printf("Case %d: %d\n",++tstcase, fun());
        scanf("%d%d ",&n,&d);
    }

	return 0;
}


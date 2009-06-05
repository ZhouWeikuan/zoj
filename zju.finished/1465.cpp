#include<iostream>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<cmath>

enum {
    SIZ = 1008,
};

double eps = 1e-8;
const double PI = 2 * asin(1.0);

using namespace std;
struct Node {
    int x;
    int y;
    double ang;
};
int N, L;
Node tree[SIZ];
int num;
int save[SIZ], top;

struct cmp{
    bool operator()(const Node &a, const Node &b){
        if(fabs(a.ang - b.ang)< eps){
            return a.x < b.x;
        }
        return a.ang < b.ang;
    }
};

int readIn(){
    int least = 0,i;
    scanf("%d%d ", &N, &L);
    for(i=0;i<N;i++){	
        scanf("%d%d ", &tree[i].x, &tree[i].y);
        //取最左下值
        if(tree[i].x < tree[least].x){
            least = i;
        }else if(tree[i].x == tree[least].x 
                && tree[i].y < tree[least].y ){
            least = i;
        }
    }
    int t;
    //交换最左下值到第0个元素
    t = tree[least].x; tree[least].x = tree[0].x; tree[0].x = t;
    t = tree[least].y; tree[least].y = tree[0].y; tree[0].y = t;
    tree[0].ang = 0;
    for(i=1;i<N;i++){
        //确定相对于第0元素的位置与角度
        tree[i].x -= tree[0].x;
        tree[i].y -= tree[0].y;
        if(tree[i].x ==0){
            if(tree[i].y > 0){
                tree[i].ang = 1/eps;
            } else {
                tree[i].ang = -1/eps;
            }
        } else {
            tree[i].ang = tree[i].y;
            tree[i].ang /= tree[i].x;
        }
    }
    tree[0].x = tree[0].y = 0;
    //将后面的元素排序
    sort(tree+1, tree+N,cmp());
    return N;
}

//确定a->b, a->c之间的夹角大小，>0表示左侧转，b应该删除
    int direct(int a,int b,int c){
        return (tree[b].x - tree[a].x)*(tree[c].y - tree[a].y) 
            -(tree[c].x - tree[a].x)*(tree[b].y - tree[a].y);
    }

//计算距离
double dis(int a, int b){
    double x,y;
    x = tree[a].x - tree[b].x;
    y = tree[a].y - tree[b].y;
    x *= x;
    y *= y;
    x += y;
    return sqrt(x);
}

double calcArc(int o, int a, int b) {
    double da = dis(o, a);
    double db = dis(a, b);
    double dc = dis(o, b);
    double s = -dc*dc + da*da + db*db;
    s /= 2;
    s /= da;
    s /= db;
    s = acos(s);
    if (fabs(s) < eps)
        s = PI;
    s = PI - s;
    s *= L;
    return s;
}

void fun(){
    top = 0;
    save[top++] = 0;
    save[top++] = 1;
    for(int i=2;i<N;i++){
        while(top>=2 && direct(save[top-2],save[top-1],i) <= 0){
            top--;
        }
        save[top++] = i;
    }
    double ret = 0;
    for(int i=1;i<top;i++){
        ret += dis(save[i-1],save[i]);
    }
    ret += dis(save[0],save[top-1]);
    for(int i=0; i<top; i++){
        ret += calcArc(save[i], save[(i+1)%top], save[(i+2)%top]);
    }
    printf("%.0lf\n", ret);
}

int main(){
    int tst = 1;
    scanf("%d ", &tst);

    while(tst--){
        readIn();
        fun();
        if(tst)
            printf("\n");
    }

    return 0;
}

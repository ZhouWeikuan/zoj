#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;
enum {
    SIZ = 12,
};
struct Node {
    double x;
    double y;
};
typedef int(*cmp_t)(const void*,const void*);
Node pred[SIZ];
Node temp[SIZ];
int mycmp(const Node *a, const Node *b){
    return int(a->x - b->x);
}
int num;
int readIn(){
    scanf("%d", &num);
    for(int i=0;i< num;i++){
        scanf("%lf", &pred[i].x);
        pred[i].y = 1.0;
    }
    qsort(pred, num, sizeof(pred[0]), (cmp_t)mycmp);
    return num;
}
//先计算向量，均一化，再偏转，伸长后与旋转点相加即可
void compute(Node &r, Node &a, Node &b){
    double x = b.x - a.x;
    double y = b.y - a.y;
    double t = x*x + y*y;
    t = sqrt(t);
    double ang = acos(t/4);
    x /= t;
    y /= t;
    x *= 2;
    y *= 2;
    r.x = x*cos(ang) - y*sin(ang);
    r.y = x*sin(ang) + y*cos(ang);
    r.x += a.x;
    r.y += a.y;
}
void calc(Node *cur, Node *next){
    num --;
    for(int i=0;i<num;i++){
        compute(next[i], cur[i], cur[i+1]);
    }
}

void fun(){
    Node *now=pred, *next=temp, *midtmp;
    while(num > 1){
        calc(now, next);
        midtmp = now; now=next; next=midtmp;
    }
    printf("%.4lf %.4lf\n", now[0].x, now[0].y);
}

int main(){
    
    while(readIn()){
        fun();
    }
	return 0;
}

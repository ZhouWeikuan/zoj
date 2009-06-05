#include<iostream>

using namespace std;
enum {
    SIZ = 100008,
};
struct Point
{
    double x;
    double y;
};
struct Line
{
    int no;
    Line *next;
    Point s;
    Point e;
};
Line lin[SIZ];
Line *head;
Line *save[SIZ];
int top,num;
void init(){
    int i;
    for(i=0;i<SIZ-1;i++){
        lin[i].next = &lin[i+1];
    }
    lin[i].next = 0;
    head = &lin[0];
}
Line* get(){
    Line *p = head; head=head->next;
    return p;
}
void put(Line *p){
    p->next = head; head = p;
}

double multiply(Point &s, Point &e, Point &o)
{
    return (s.x - o.x)*(e.y - o.y) - (s.y-o.y)*(e.x-o.x);
}
bool online(Line &l, Point &p)
{
    return multiply(l.e, p, l.s)==0
           &&(p.x -l.s.x)*(p.x -l.e.x)<=0
           &&(p.y -l.s.y)*(p.y-l.e.y)<=0;
}

bool interseg(Line &u, Line &v)
{
    return
        //排斥实验
        (    (max(u.s.x,u.e.x)>=min(v.s.x,v.e.x))&&                          
             (max(v.s.x,v.e.x)>=min(u.s.x,u.e.x))&&
             (max(u.s.y,u.e.y)>=min(v.s.y,v.e.y))&&
             (max(v.s.y,v.e.y)>=min(u.s.y,u.e.y))&&
        //跨立实验
             (multiply(v.s,u.e,u.s)*multiply(u.e,v.e,u.s)>=0)&&                 
             (multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>=0));
}

bool check(Line &a, Line &b){
     return interseg(a, b) 
            && !online(a, b.s)
            && !online(a, b.e)
            && !online(b, a.s)
            && !online(b, a.e);
}

int fun(){
    int i,j,k;
    Line *p;
    top = 0;
    for(i=1;i<=num;i++){
        p = get();
        p->no = i;
        scanf("%lf%lf%lf%lf", &p->s.x,&p->s.y,&p->e.x,&p->e.y);
        k = 0;
        for(j=0;j<top;j++){
            if(!check(*p, *save[j])){
                save[k++] = save[j];
            } else {
                put(save[j]);
            }
        }
        save[k++] = p;
        top = k;
    }
    printf("Top sticks:");
    for(i=0;i<top-1;i++){
        printf(" %d,",(save[i])->no);
        put(save[i]);
    }
    printf(" %d.\n",(save[i])->no);
    put(save[i]);
    return 0;
}

int main()
{
    init();
    while(scanf("%d",&num) && num > 0){
        fun();
    }
    return 0;
}

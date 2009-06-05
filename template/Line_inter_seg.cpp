#include<iostream>

using namespace std;
struct Point
{
    double x;
    double y;
};
struct Line
{
    Point s;
    Point e;
};
Line lin[2004];
int num;

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

void readIn(){
    int i;
    for(i=0;i<num;i++){
        cin>>lin[i].s.x
            >>lin[i].s.y
            >>lin[i].e.x
            >>lin[i].e.y;
    }
}

int fun(){
    int i,j;
    for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if( interseg(lin[i], lin[j]) 
                        && !online(lin[i], lin[j].s)
                        && !online(lin[i], lin[j].e)
                        && !online(lin[j], lin[i].s)
                        && !online(lin[j], lin[i].e))
                return 1;
        }
    }
    return 0;
}

int main()
{
    
    while(cin>>num){
        readIn();
        if( fun() == 0){
            cout<<"ok!"<<endl;
        } else {
            cout<<"burned!"<<endl;
        }
    }

    return 0;
}

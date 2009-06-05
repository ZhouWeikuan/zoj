#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 1008,
};
struct Node {
    double x,y;
};
Node g, d;
Node h[SIZ];
int n;
char buf[80];
const double eps = 1e-5;

int readIn(){
    if(NULL==fgets(buf, 80, stdin))
        return 0;
    sscanf(buf, "%lf%lf%lf%lf ", &g.x, &g.y, &d.x, &d.y);
    n = 0;
    while(NULL != fgets(buf, 80, stdin) && buf[0] != '\n'){
        sscanf(buf, "%lf%lf ", &h[n].x, &h[n].y);
        n++;
    }

    return 1;
}

int test(const Node &o){
    double dis, t;
    dis = (o.x - g.x)*(o.x - g.x) + (o.y-g.y)*(o.y-g.y);
    dis = sqrt(dis);
    t = (o.x - d.x)*(o.x - d.x) + (o.y-d.y)*(o.y-d.y);
    t = sqrt(t);
    t /= 2;
    if(dis >= t + eps)
        return 0;
    return 1;
}

void fun(){
    for(int i=0;i<n;i++){
        if(test(h[i])){
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n"
                    ,h[i].x, h[i].y);
            return;
        }
    }
    printf("The gopher cannot escape.\n");
}

int main(){

    while(readIn()){
        fun();
    }
	return 0;
}

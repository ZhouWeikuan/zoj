#include<iostream>
using namespace std;
enum {
    SIZ = 1000000000,
};
int w[2],d;
int c[2];
int num, weight;
void testOne(int one){
    if(d % w[one] !=0)
        return;
    int t = d / w[one];
    if(t < num || (t==num) && d < weight){
        c[one] = t, c[1-one]=0;
        num = t, weight = d;
    }
}
void testSum(){
    int x,y;
    for(y = 0; d>=y*w[1] && (d-y*w[1])%w[0]!=0;y++)
        ;
    if(d>=y*w[1]){
        x = (d-y*w[1])/w[0];
        int t = x + y;
        if(t < num || (t==num) && d < weight){
            c[0] = x, c[1]=y;
            num = t, weight = d;
        }
    }
    for(x=0; d>=x*w[0] && (d-x*w[0])%w[1]!=0;x++) 
        ;
    if(d>=x*w[0]){
        y = (d-x*w[0])/w[1];
        int t = x + y;
        if(t < num || (t==num) && d< weight){
            c[0] = x, c[1]=y;
            num = t, weight = d;
        }
    }
}
void testSub(int one){
    int q[2];
    q[1-one] = 0;
    q[one] = d / w[one];
    while( q[one]*w[one] != d + q[1-one] *w[1-one]){
        if(q[one]*w[one]<d+q[1-one]*w[1-one]){
            q[one]++;
        } else {
            q[1-one]++;
        }
    }
    int t = q[one] + q[1-one];
    int s = q[one]*w[one] + q[1-one]*w[1-one];
    if(t < num || (t==num) && s < weight){
        c[one] = q[one]; c[1-one] = q[1-one];
        num = t, weight = s;
    }
}

void fun(){
    num = weight = SIZ;
    testOne(0);
    testOne(1);
    testSum();
    testSub(0);
    testSub(1);
    cout<<c[0]<<" "<<c[1]<<endl;
}

int main(){

    while(cin>>w[0]>>w[1]>>d && w[0]+w[1]+d){
        fun();
    }

    return 0;
}

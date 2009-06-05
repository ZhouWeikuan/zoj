#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int f[3],r[9],tar;
const double PI = 3.14159;
double d, diff;
int a,b;

void fun(){
    diff = tar;
    d *= PI;
    double t;
    for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            t = f[i] * d / r[j];
            t = fabs(t - tar);
            if(t < diff){
                diff = t;
                a = i, b = j;
            }
        }
    }
    t = d * f[a] / r[b];
    printf("A gear selection of %d/%d produces a gear size of %.3lf.\n",
          f[a], r[b], t);
}

int main(){
    int tstcase;
    cin>>tstcase;
    while(tstcase --){
        for(int i=0;i<3;i++){
            cin>>f[i];
        }
        for(int i=0;i<9;i++){
            cin>>r[i];
        }
        cin>>d>>tar;
        fun();
        if(tstcase)
            printf("\n");
    }

    return 0;
}

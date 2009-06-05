#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<double> a;
vector<double> b;
int N;
vector<double> x;
vector<double> y;
const double eps = 1e-7;

void readIn(){
    a.reserve(N);
    b.reserve(N);
    x.reserve(N+1);
    y.reserve(N+1);
    double t1,t2;
    for(int i=0;i<N;i++){
        cin>>t1>>t2;
        a[i] = t1;
        b[i] = t2;
    }
}

void iterate(vector<double> &in, vector<double> & out){
    int i;
    out[0] = 0;
    for(;;){
        for(i=0;i<N;i++){
            out[i+1] = 2 * in[i] - out[i];
        }
        if(fabs(out[N]- out[0]) < eps)
            break;
        out[0] += out[N];
        out[0] /= 2;
    }
}

int fun(){
    iterate(a, x);
    iterate(b, y);
    printf("%d", N);
    for(int i=0;i<N;i++){
        printf(" %.6lf %.6lf", x[i], y[i]);
    }
    printf("\n");
    return 0;
}

int main(){

    while(cin>>N){
        readIn();
        fun();
    }

	return 0;
}

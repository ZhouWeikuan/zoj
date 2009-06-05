#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	double p,v;

	while( scanf("%lf%lf", &p, &v) > 0){
		p = pow(v, 1/p);
        printf("%.0lf\n", p);
	}

	return 0;
}

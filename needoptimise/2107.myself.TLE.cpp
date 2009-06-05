#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;
struct Point {
	float x;
	float y;
};
enum {
	Size = 100008,
};
Point pnt[Size];
int X[Size],Y[Size];
int T[Size];
int num;
int xcmp(int *a, int *b){
	return (int)(pnt[*a].x - pnt[*b].x);
}
int ycmp(int *a, int *b){
	return (int)(pnt[*a].y - pnt[*b].y);
}

float Dc,Dp;
float getDis(int a, int b){
	Dc = pnt[a].x - pnt[b].x;
	Dp = pnt[a].y - pnt[b].y;
	Dc *= Dc;
	Dp *= Dp;
	Dc += Dp;
	return sqrt(Dc);
}

float calc(int s,int e){
	float c=100000.0,p;
	int i,j;
	if(e - s < 4){
		for(i=s;i<e-1;i++){
			for(j=i+1;j<e;j++){
				p = getDis(i,j);
				if(c > p){
					c = p;
				}
			}
		}
		return c;
	}
	int t = (s+e)/2;
	c = calc(s, t);
	p = calc(t, e);
	if(c > p){
		c = p;
	}
	int k = 0;
	for(i=0;i<num;i++){
		if(fabs(pnt[ Y[i] ].x - pnt[t].x) < c){
			T[k++] = Y[i];
		}
	}
	for(i=0;i<k-1;i++){
		for(j=i+1;j<i+8&&j<k;j++){
			p = getDis(T[i], T[j]);
			if(c > p)
				c = p;
		}
	}
	return c;
}

int main(){
	int i;
	scanf("%d ", &num);
	while(num){
		for(i=0;i<num;i++){
			scanf("%f%f ", &pnt[i].x, &pnt[i].y);
			X[i] = i;
			Y[i] = i;
		}
		qsort(X,num,sizeof(int), (int(*)(const void*, const void*))xcmp);
		qsort(Y,num,sizeof(int), (int(*)(const void*, const void*))ycmp);
		printf("%.2f\n", calc(0,num)/2);
		scanf("%d ", &num);
	}

	return 0;
}

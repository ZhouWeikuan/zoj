#include<cstdio>
#include<cmath>
#include<queue>

using namespace std;
enum {
	Size = 108,
};
typedef struct {
	double x, y;
}Point;

Point dot[Size];
int num;
double matrix[Size][Size];

double getdis(int a, int b){
	double x,y;
	x = dot[a].x - dot[b].x;
	y = dot[a].y - dot[b].y;
	x *= x;
	y *= y;
	x += y;
	return sqrt(x);
}

struct MyComp {
	int operator()(const int &a, const int &b){
		return matrix[a>>16][a&0xffff] > matrix[b>>16][b&0xffff];
	}
};
int set[Size];

int getparent(int n){
	int p = set[n];
	while(p != n){
		n = p;
		p = set[n];
	}
	return p;
}

void fun(){
	double result = 0;
	int i,j;
	int a,b;
	priority_queue<int, vector<int>, MyComp > q;
	for(i=0;i<num;i++){
		set[i] = i;
		for(j=i+1;j<num;j++){
			matrix[i][j]= getdis(i,j);
			q.push((i<<16) + j);
		}
	}
	while(!q.empty()){
		i = q.top(); q.pop();
		j = i&0xffff; i>>=16;
		a = getparent(i); b = getparent(j);
		if(a != b){	
			if(a < b){
				set[b] = a;
				set[j] = a;
				set[i] = a;
			} else {
				set[a] = b;
				set[i] = b;
				set[j] = b;
			}
			result += matrix[i][j];
		}
	}
	printf("%.2lf\n", result);
}

int main(){
	int i;
	
	scanf("%d", &num);
	while(!feof(stdin)){
		for(i=0;i<num;i++){
			scanf("%lf %lf", &dot[i].x, &dot[i].y);
		}
		
		fun();
		
		scanf("%d", &num);
	}

	return 0;
}

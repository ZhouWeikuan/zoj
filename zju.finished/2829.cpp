#include<cstdio>

using namespace std;
enum {
	Base = 7,
};

int save[Base] = {0, 3, 5, 6, 9, 10, 12};
int pos;

int main(){
	int a, b, t;
	while(scanf("%d", &pos) > 0){
		a = pos / Base;
		b = pos % Base;
		t = a * 15 + save[b];
		printf("%d\n", t);
	}
    
    return 0;
}

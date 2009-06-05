#include<iostream>
using namespace std;
enum {
    SIZ = 100008,
};
struct Point{
    int x,y;
    bool operator<(const Point&r)const{
        if(x!=r.x) return x<r.x;
        return y<r.y;
    }
};
int num;
Point dot[SIZ];
int ptr[SIZ], pos;

// find the first place i that v>=ptr[i]
int find(int v){
    int l=0, h=pos, m;
	while(l < h){
        m = (l + h)/2;
		if(ptr[m] < v){ 
            h = m;
		} else if(ptr[m] > v){
            l = m+1;
		} else {
            l = m;
            break;
        }
	}
    if(l==pos) pos++;
	return l;
}

void fun(){
	int i,t;
    pos = 0;
	for(i=0;i<num;i++){
        t = find(dot[i].y);
        ptr[t] = dot[i].y;
	}
}

int readIn(){
    int a,b;
    if(scanf("%d%d%d",&a,&b,&num)<0)
        return 0;
    for(a=0;a<num;a++){
        scanf("%d%d",&dot[a].x,&dot[a].y);
    }
    sort(dot, dot+num);
    return 1;
}

int main(){

    while(readIn()>0){
        fun();
        printf("%d\n", pos);
    }
    return 0;
}


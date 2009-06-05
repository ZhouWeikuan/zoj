#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
enum {
    SIZ = 30008,
};
const double MaxAng = 1e20;
struct Node {
	int x;
	int y;
	double ang;
    bool operator<(const Node&rhs)const{
        if( fabs(ang - rhs.ang)<1e-9){
            return x < rhs.x;
        }
        return ang < rhs.ang;
    }
};
Node tree[SIZ];
int num, top;
int save[SIZ];

int readIn(){
	int least = 0,i;
    if(scanf("%d",&num) < 0) return 0;
	for(i=0;i<num;i++){	
        scanf("%d%d", &tree[i].x, &tree[i].y);
		//取最左下值
		if(tree[i].x < tree[least].x){
			least = i;
		}else if(tree[i].x == tree[least].x 
			&& tree[i].y < tree[least].y ){
			least = i;
		}
	}
	int t;
	//交换最左下值到第0个元素
	t = tree[least].x; tree[least].x = tree[0].x; tree[0].x = t;
	t = tree[least].y; tree[least].y = tree[0].y; tree[0].y = t;
	tree[0].ang = 0;
	for(i=1;i<num;i++){
		//确定相对于第0元素的位置与角度
		tree[i].x -= tree[0].x;
		tree[i].y -= tree[0].y;
		if(tree[i].x ==0){
			if(tree[i].y > 0){
				tree[i].ang = MaxAng;
			} else {
				tree[i].ang = -MaxAng;
			}
		} else {
			tree[i].ang = tree[i].y;
			tree[i].ang /= tree[i].x;
		}
	}
	tree[0].x = tree[0].y = 0;
	//将后面的元素排序
	sort(tree+1, tree+num);
	return num;
}
//确定a->b, a->c之间的夹角大小，>0表示左侧转，b应该删除
int direct(int a,int b,int c){
	return (tree[b].x - tree[a].x)*(tree[c].y - tree[a].y) 
			-(tree[c].x - tree[a].x)*(tree[b].y - tree[a].y);
}

//计算距离
double dis(int a, int b){
	double x,y;
	x = tree[a].x - tree[b].x;
	y = tree[a].y - tree[b].y;
	x *= x;
	y *= y;
	x += y;
	return sqrt(x);
}

void fun(){
	if(num==1){
		printf("0.00\n");
		return;
	}
	top = 0;
	save[top++] = 0;
	save[top++] = 1;
	for(int i=2;i<num;i++){
		while(direct(save[top-2],save[top-1],i) < 0){
			top--;
		}
		save[top++] = i;
	}
    for(int i=1; i<top; i++){
        tree[save[i]].x += tree[0].x;
        tree[save[i]].y += tree[0].y;
    }
	double ret = 0, t, o;
    int a=0, b=0;
    for(;a < top; a++){
        o = dis(save[a], save[b]);
        if(ret < o) ret = o;

        t = dis(save[a], save[(b+1)%top]);
        while(t > o){
            o = t;
            if(ret < t) ret = t;
            b = (b+1)%top;
            t = dis(save[a], save[(b+1)%top]);
        }
    }
	printf("%.2lf\n", ret);
}
int main(){
	while(readIn() > 0){
		fun();
	}
	return 0;
}


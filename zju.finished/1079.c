#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 508,
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
};
typedef struct {
	int conn[4];
	int direct;
	int x,y;
}Node;

Node tree[Size];
int  point[Size];
int  num;

int get_up(int i){
	return tree[i].conn[tree[i].direct];
}
int get_down(int i){
	return tree[i].conn[ (tree[i].direct+2)%4 ];
}
int get_left(int i){
	return tree[i].conn[ (tree[i].direct +1)%4 ];
}
int get_right(int i){
	return tree[i].conn[ (tree[i].direct +3)%4 ];
}

void init_direct(int root){
	int i,nb = get_up(root);
	if(nb != -1 && tree[nb].direct ==-1){
		for(i=0;tree[nb].conn[i] != root;i++)
			;
		tree[nb].direct = (i+2)%4;
		tree[nb].x = tree[root].x-1;
		tree[nb].y = tree[root].y;
		init_direct(nb);
	}

	nb = get_down(root);
	if(nb != -1 && tree[nb].direct ==-1){
		for(i=0;tree[nb].conn[i] != root;i++)
			;
		tree[nb].direct = i;
		tree[nb].x = tree[root].x+1;
		tree[nb].y = tree[root].y;
		init_direct(nb);
	}

	nb = get_left(root);
	if(nb != -1 && tree[nb].direct ==-1){
		for(i=0;tree[nb].conn[i] != root;i++)
			;
		tree[nb].direct = (i+1)%4;
		tree[nb].x = tree[root].x;
		tree[nb].y = tree[root].y-1;
		init_direct(nb);
	}

	nb = get_right(root);
	if(nb != -1 && tree[nb].direct ==-1){
		for(i=0;tree[nb].conn[i] != root;i++)
			;
		tree[nb].direct = (i+3)%4;
		tree[nb].x = tree[root].x;
		tree[nb].y = tree[root].y+1;
		init_direct(nb);
	}

}

int MyComp(const int *a, const int *b){
	if(tree[*a].x != tree[*b].x)
		return tree[*a].x - tree[*b].x;
	return tree[*a].y - tree[*b].y;
}

void fun(){
	static	int tstcase = 1;
	int i,t;
	int minx,miny;
	printf("Instance %d:\n", tstcase ++);
	
	tree[0].direct = DOWN;
	tree[0].x = tree[0].y = 0;
	init_direct(0);
	for(i=0;i<num;i++)
		point[i] = i;
	qsort(point,num,sizeof(int), MyComp);
	minx = tree[point[0]].x;
	miny = tree[point[0]].y;
	for(i=0;i<num;i++){
		t = point[i];
		tree[t].x -= minx;
		tree[t].y -= miny;
		printf("%5d%5d%6d %d\n", tree[t].x, tree[t].y, t, (tree[t].direct+2)%4 );
	}
}

int main(){
	int i;
	int first, fd;
	int second, sd;
	
	scanf("%d", &num);
	while(num){
		memset(tree, -1, sizeof(Node)*num);
		scanf("%d",&i);
		while(i--){
			scanf("%d %d %d %d", &first, &fd, &second, &sd);
			tree[first].conn[fd] = second;
			tree[second].conn[sd] = first;
		}
		fun();

		scanf("%d", &num);
	}

	return 0;
}

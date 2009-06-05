#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 5,
};

typedef struct {
	int up;
	int right;
	int down;
	int left;
	int conn;
}Box;

int visit[28];
Box box[28];
int mat[Size][Size];
int  num, edgenum;

int preprocess(){
	int one , two, three, four;
	one = two = three = four = 0;
	int up, down, left,right;
	int i,j,value;
	for(i=0;i<num;i++){
		up = down = left = right =0;
		for(j=0;j<num;j++){
			if(i==j)
				continue;
			if(up && down && left && right){
				break;
			}
			up   += box[i].up == box[j].down;
			down += box[i].down == box[j].up;
			left += box[i].left == box[j].right;
			right+= box[i].right == box[j].left;
			up = up>0; down = down>0; left = left>0; right = right > 0;
		}
		box[i].conn = value = up + left + right + down;
		if(value == 4){
			four ++;
		} else if(value == 3){
			three ++;
		} else if(value == 2){
			if(up + down ==2){
				return 0;
			} else if(left + right ==2){
				return 0;
			} else {
				two ++;
			}
		} else {
			return 0;
		}
	}
	if(two > 4|| two+three > 4*edgenum-2){
		return 0;
	}
	return 1;
}
int set(int node, int x, int y){
	int pred;
	mat[x][y] = node;
	if(x>0 && x<edgenum-1 && y>0 && y<edgenum-1){
		if(box[node].conn <4)
			return 0;
	}else if( (x==0||x==edgenum-1) && y!=0 && y!= edgenum-1 ){
		if(box[node].conn < 3)
			return 0;
	}else if( (y==0||y==edgenum-1) && x!=0 && x!=edgenum-1){
		if(box[node].conn <3)
			return 0;
	}
	
	if(x >0){
		pred = mat[x-1][y];
		if(box[pred].down != box[node].up)
			return 0;
	}
	if(y > 0){
		pred = mat[x][y-1];
		if(box[pred].right != box[node].left)
			return 0;
	}
	if(x== edgenum-1 && y== edgenum-1){
		return 1;
	}
	int nx, ny;
	if(y == edgenum-1){
		nx = x+1, ny= 0;
	} else {
		nx = x; ny = y+1;
	}
	for(pred = 0; pred<num;pred++){
		if(visit[pred] == 0){
			visit[pred] = 1;
			if(set(pred,nx,ny)){
				return 1;
			}
			visit[pred] = 0;
		}
	}
	return 0;
}

int fun(){
	memset(visit,0,sizeof(visit));
	int i;
	for(i=0;i<num;i++){
		visit[i] = 1;
		if(set(i,0,0)){
			return 1;
		}
		visit[i] = 0;
	}
	return 0;
}

int main(){
	int tstcase = 0,i;
	
	scanf("%d", &num);
	while(num){
		edgenum = num;
		num *= num;
		for(i=0;i<num;i++){
			scanf("%d %d %d %d", &box[i].up, &box[i].right,
					&box[i].down, &box[i].left);
		}
		if(tstcase ++){
			printf("\n");
		}
		printf("Game %d: ",tstcase);
		if(num ==1 || (preprocess()  && fun())){
			printf("Possible\n");
		} else {
			printf("Impossible\n");
		}
		scanf("%d", &num);
	}

	return 0;
}

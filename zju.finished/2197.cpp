#include<string>
#include<cstdio>

using namespace std;
struct Node {
	char type;
	char buf[259];
	int a;
	int b;
};

Node tree[108];
int num;
int bitmask[108];

void getInput(int i){
	Node &cur = tree[i];
	scanf("%c ",&cur.type);
	i = -1;
	scanf("%c",&cur.buf[0]);
	do{
		i++;
		scanf("%c",&cur.buf[i]);
	}while(cur.buf[i]!='"');
	cur.buf[i] = 0;
	if(cur.type == 'C'){
		scanf("%d%d ", &cur.a, &cur.b);
	}else {
		static char s[16];
		scanf("%s ",s);
		if(strcmp(s,"HAPPY")==0){
			cur.a = 0; cur.b = -1;
		} else{
			cur.a=cur.b =-1;
		}
	}
}
int go(int i){
	if(bitmask[i] ==1)
		return -1;
	Node &cur = tree[i];
	if(cur.type =='E')
		return cur.a;

	bitmask[i] = 1;	
	if(go(cur.a)==-1){
		cur.a = -1;
	} else {
		bitmask[i] = 0;
		return 0;
	}
	if(go(cur.b) == -1){
		bitmask[i] = 0;
		return cur.b = -1;
	}
	bitmask[i] = 0;
	return 0;
}
void output(){
	int i = 1;
	while(tree[i].type != 'E'){
		printf("%s\n",tree[i].buf);
		if(tree[i].a !=-1){
			i = tree[i].a;
		} else {
			i = tree[i].b;
		}
	}
	printf("%s\n",tree[i].buf);
}

int main(){
	int tstnum,tstcase = 0,i;
	scanf("%d ",&tstnum);
	while(tstcase ++ < tstnum){
		printf("STORY %d\n",tstcase);
		scanf("%d ",&num);
		for(i=1;i<=num;i++){
			getInput(i);
		}
		memset(bitmask,0,sizeof(bitmask));
		go(1);
		output();
	}

	return 0;
}

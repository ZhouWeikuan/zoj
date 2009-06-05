#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

/* + * ^ () */
// 注意 ^的情况, 因为 a^b^c只能分成两部分, a b^c, 而不能分成三个部分
enum {
	Size = 1008,
};

char buffer[Size];

typedef struct {
	int childnum;
	int child[100];
	int start;
	int end;
}Node;

Node tree[Size];
int  num;
int stack[100];
int pos;

void parse(int,int,int);
//如果中间有+号，则进行加法处理分割
int checkfor_add(int node){
	int deep = 0;
	int i, last = tree[node].start;
	for(i=tree[node].start; i<tree[node].end;i++){
		if(buffer[i] =='('){ // 左括号
			deep ++;
		} else if(buffer[i] ==')'){ // 右括号
			deep --;
		} else if(buffer[i] =='+' && deep == 0){
			if(i == last ){
				last = i+1;
				continue;
			}
            tree[node].child[ tree[node].childnum ++ ] = num;
            parse(num++,last,i);
            last = i+1;
		} 
	}

	if(last != tree[node].start){
		tree[node].child[tree[node].childnum++] = num;
		parse(num++,last,tree[node].end);
		return 1;
	}
    return 0;
}

// mult 处理 包括*和两括号相乘()()
int checkfor_mult(int node){
	int deep = 0;
	int i, last = tree[node].start;
	for(i=tree[node].start; i<tree[node].end;i++){
		if(buffer[i] =='('){ // 左括号
			deep ++;
		} else if(buffer[i] ==')'){ // 右括号
			deep --;
		} else if(buffer[i] == '*' && deep==0){
			if(i == last ){
				last = i+1;
				continue;
			}

            tree[node].child[ tree[node].childnum ++ ] = num;
            parse(num++,last,i);
            last = i+1;
		} 
	}

	if(last != tree[node].start){
		tree[node].child[tree[node].childnum++] = num;
		parse(num++,last,tree[node].end);
		return 1;
	}
	return 0;
}

int checkfor_pow(int node){
	int deep = 0;
	int i, last = tree[node].start;
	for(i=tree[node].start; i<tree[node].end;i++){
		if(buffer[i] =='('){ // 左括号
			deep ++;
		} else if(buffer[i] ==')'){ // 右括号
			deep --;
		} else if(deep ==0 && buffer[i] == '^'){
			if(i == last ){
				last = i+1;
				continue;
			}

            tree[node].child[ tree[node].childnum ++ ] = num;
            parse(num++,last,i);
            last = i+1;
            break;
		} 
	}

	if(last != tree[node].start){
		tree[node].child[tree[node].childnum++] = num;
		parse(num++,last,tree[node].end);
		return 1;
	}
    return 0;
}

// 分析一段表达式，将缓冲区中的[s,e)认为是parent结点所包括的范围，
// 再在其内进行分解。
void parse(int parent, int s, int e){
	int i;

	tree[parent].start = s;
	tree[parent].end = e;
	tree[parent].childnum = 0;

	if(e-s ==1){
		tree[parent].childnum = 1;
		tree[parent].child[0] = parent;
		return ;
	}
	if(checkfor_add(parent) ){
		return;
	}
	if(checkfor_mult(parent)){
		return;
	}
	if(checkfor_pow(parent)){
		return;
	}
	/* () 包括了里面的语句 */
	if(buffer[s] =='(' && buffer[e-1]==')'){
		tree[parent].childnum=1;
		tree[parent].child[0] = num++;
		parse(num-1,s+1,e-1);
	}
}

void travel(){
	int i,t;
	int node = 0;
	
	for(i=0;i<pos;i++){
		t= stack[i];
        if(t < tree[node].childnum){
		    node = tree[node].child[t];
        }
	}
	for(i=tree[node].start;i<tree[node].end;i++)
		printf("%c",buffer[i]);
}

void fun(){
	int tstnum,t;
	char c;
	scanf("%d", &tstnum);
	while(tstnum --){
		pos = 0;
		do {
			scanf("%d%c",&t,&c);
			stack[pos++] = t;
		} while(c!='\n');
		for(t=pos-1;t>=0;t--){
			printf("op(%d,",stack[t]);
			stack[t] --;
		}
		printf("%c",buffer[0]);
		for(t=0;t<pos;t++)
			printf(")");
		printf("=");
		travel();
		printf("\n");
	}
}

int main(){
	int tstcase = 0;
	scanf("%s",buffer);
	while(buffer[0]!= '*'){
		if(tstcase ++){
			printf("\n");
		}
		num = 1;
		printf("Expression %c:\n",buffer[0]);
		parse(0, 3, strlen(buffer));

		fun();
		
		scanf("%s",buffer);
	}

	return 0;
}

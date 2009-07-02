#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

/* + * ^ () */
// Care for ^, for we can only split a^b^c into two different parts, a b^c, instead of three parts.
enum {
	SIZ = 1008,
};

char buffer[SIZ];

typedef struct {
	int childnum;
	int child[100];
	int start;
	int end;
}Node;

Node tree[SIZ];
int  num;
int stack[100];
int pos;

void parse(int,int,int);
// If there is +, then we split it with +
int checkfor_add(int node){
	int deep = 0;
	int i, last = tree[node].start;
	for(i=tree[node].start; i<tree[node].end;i++){
		if(buffer[i] =='('){ 
			deep ++;
		} else if(buffer[i] ==')'){
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

// Process for multiply, including * and ()()
int checkfor_mult(int node){
	int deep = 0;
	int i, last = tree[node].start;
	for(i=tree[node].start; i<tree[node].end;i++){
		if(buffer[i] =='('){ 
			deep ++;
		} else if(buffer[i] ==')'){
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
		if(buffer[i] =='('){ 
			deep ++;
		} else if(buffer[i] ==')'){ 
			deep --;
		} else if(deep ==0 && buffer[i] == '^'){
			if(i == last ){
				last = i+1;
				continue;
			}

            tree[node].child[ tree[node].childnum ++ ] = num;
            parse(num++,last,i);
            last = i+1;
            //break;
		} 
	}

	if(last != tree[node].start){
		tree[node].child[tree[node].childnum++] = num;
		parse(num++,last,tree[node].end);
		return 1;
	}
    return 0;
}

// Analyze an expression, treat the range [s,e) as the range included by parent node
// and then split it inside
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
	/* () includes expression in it */
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
		t = stack[i];
        if ( t >= tree[node].childnum)
            t = tree[node].childnum - 1;
		node = tree[node].child[t];
	}
	for(i=tree[node].start;i<tree[node].end;i++)
		printf("%c",buffer[i]);
}

void fun(){
    char tmp[SIZ], *s;
	int tstnum,t;
	char c;
	scanf("%d ", &tstnum);
	while(tstnum --){
		pos = 0;
        fgets(tmp, SIZ, stdin);
        s = strtok(tmp, " \n\t");
		while(s!=NULL) {
			stack[pos++] = atoi(s);
            s = strtok(NULL, " \n\t");
		}
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
	scanf("%s ",buffer);
	while(buffer[0]!= '*'){
		if(tstcase ++){
			printf("\n");
		}
		num = 1;
		printf("Expression %c:\n",buffer[0]);
		parse(0, 3, strlen(buffer));

		fun();
		
		scanf("%s ",buffer);
	}

	return 0;
}

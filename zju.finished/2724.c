#include<stdio.h>

typedef struct {
	char  name[80];
	int parameter;
	int priority;
	int seq;
}Node ;

Node msg[60008];
int timer = 0;
int stack[60008];
int top , last, num;

int MyComp(int a, int b){
	if(msg[a].priority != msg[b].priority){
		return msg[a].priority < msg[b].priority;
	}
	return msg[a].seq < msg[b].seq;
}

void push(int n){
	int child, root;
	child = top;
	stack[top++] = n;
	int t;
	while(child !=0){
		root = (child-1)/2;
		if(MyComp(stack[child],stack[root])){
			t =stack[root],stack[root]=stack[child],stack[child]=t;
		} else {
			break;
		}
		child = root;
	}
}

int pop(void){
	int ret = stack[0];
	stack[0] = stack[--top];
	int root = 0, child;
	child = root*2 + 1;
	int t;
	while(child < top){
		if(child+1 < top && MyComp(stack[child+1],stack[child]))
			child++;
		if(MyComp(stack[child],stack[root])){
			t = stack[root], stack[root] = stack[child], stack[child] = t;
		} else {
			break;
		}
		root = child;
		child = root*2 + 1;
	}
	return ret;
}

void get_msg(){
	for(; last < num;last++){
		push(last);
	}
	if(top ==0){
		printf("EMPTY QUEUE!\n");
		return;
	}
	
	int t = pop();
	printf("%s %d\n",msg[t].name,msg[t].parameter);
}

void put_msg(){
	Node *n = &msg[num];
	scanf("%s %d %d",n->name,&n->parameter,&n->priority);
	n->seq = timer++;
	num ++;
}

int main(){
    char buf[8];

	last = num = top = 0; 
	scanf("%s", buf);
    while(!feof(stdin)){
		if(buf[0]=='G'){
			get_msg();
		} else {
			put_msg();
		}
		scanf("%s", buf);
	}
    
    return 0;
}

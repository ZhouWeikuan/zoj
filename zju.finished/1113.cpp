#include<cstdio>

/**
	本程序通不过，原因未知 
**/
using namespace std;
enum {
	Size = 16,
};

typedef struct {
	int num;
	char data[Size];
}Node ;

Node initvalue={1,{1,0}};
Node divalue= initvalue;

void div(Node &v, int n){
	int i=0;
	int carry = 0;
	do{
		carry = 10 * carry +v.data[i];
		v.data[i] = carry / n;
		carry = carry % n;
		i ++;
		if(i >= 16)
			break;
	}while(i<v.num || carry);
	v.num = i;
}

void add(Node &v, Node &n){
	int i;
	int carry = 0;
	v.num = n.num;
	i = v.num -1;
	while(i>=0){
		carry = carry + n.data[i] + v.data[i];
		v.data[i] = carry % 10;
		carry /= 10;
		i--;
	}
}

void printvalue(int value, Node &old){
	Node node = old;	
	int carry;
	if(node.num >10){
		if(node.data[10] > 4){
			carry = 1;
		}
		int i= 9;
		while(carry){
			carry = carry + node.data[i];
			node.data[i] = carry % 10;
			carry /= 10;
			i--;
		}
		node.num = 10;
	}
	printf("%d ", value);
	if(node.num >1){
		printf("%d.",node.data[0]);
		int i = 1;
		for(i=1;i<node.num ;i++){
			printf("%d",node.data[i]);
		}
		printf("\n");
	}else {
		printf("%d\n",node.data[0]);
	}
}

int main(){
    int i;
    
    printf("n e\n");
	printf("- -----------\n");
    printvalue(0,initvalue);
    for(i=1;i<10;i++){
		div(divalue,i);
		add(initvalue,divalue);
		printvalue(i,initvalue);
	}
    
    return 0;
}

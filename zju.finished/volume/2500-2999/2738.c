#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int tree[20];
int left[24];
int right[24];

void init(){
	int i,sum,j;
	tree[0] = 1;
	
	for(i = 1; i< 20;i++){
		sum = 0;
		for(j=0;j<=i-1;j++){
			sum += tree[j] * tree[i-1-j];
		}
		tree[i] = sum;
		/*printf("%d -- %d\n", i, sum);*/
	}	
}

int fun(int * p,int n, int m, int start, int incr){
    int i,sum = 0,t,root;    
    
    for(i=0;i<=n-1;i++){
		t = tree[i] * tree[n-i-1] * incr;
		if(m <= t){
			break;
		}
		m -= t;
		sum += t;
	}
	*p = start + i;
	if(i){		
		t = fun(&root, i,m, start, incr * tree[n-i-1]);		
		m -= t;
		sum += t;
		left[start +i ] = root;
	} else {
		left[start + i]  = -1;
	}
	right[start + i] = -1;
	
	start += i + 1;
	i = n - 1 - i;
    if(i > 0){
		t = fun(&root,i,m,start,incr);
		m -= t;
		sum += t;
		right[start -1] = root;
	}
	return sum;
}

void preorder(int r){
	if(r == -1)
		return;
	printf("%c", r+'a');
	preorder(left[r]);
	preorder(right[r]);
}

void midorder(int r){
	if(r == -1)
		return;
	midorder(left[r]);
	printf("%c %c %c\n", r+'a', left[r]==-1?'*':left[r] +'a', right[r]==-1?'*':right[r]+'a');		
	midorder(right[r]);
}

int main(){
    init();
    int n,m;
    int tstcase = 0;    
    int root;    
    
    scanf("%d %d", &n, &m);
    while(!feof(stdin)){				
		if(tstcase)
			printf("\n");
		tstcase ++;
		memset(left, -1 ,sizeof(int)*n);
		memset(right, -1 ,sizeof(int)*n);
    	fun(&root,n,m,0,1);
    	preorder(root);
    	printf("\n");
    	midorder(root);
    	
    	scanf("%d %d", &n, &m);
	}
    
    return 0;
}

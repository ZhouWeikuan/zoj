#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<cstdio>

using namespace std;
enum {
	Size = 52,	
};

int freq[Size];
int node[Size];
int pos;
priority_queue<int, vector<int>, greater<int> > leaf;
multimap<int,int> edge;
int root;

void traceback(int key){
	multimap<int,int>::iterator first,last;
	printf("%d", key);
	
	first = edge.lower_bound(key);
	last = edge.upper_bound(key);
			
	for(;first != last; first++){
		printf(" (");
		traceback(first->second);
		printf(")");
	}
		
}

int fun(){
    int i;
    for(i=1;i<root;i++){
		if(freq[i] ==0 ){
			leaf.push(i);
		}
	}
	
	int f, p;
	i = 0;
	while(! leaf.empty() ){
		f = leaf.top(); leaf.pop();
		p = node[i];
		edge.insert( make_pair(p, f) );
		if(--freq[p] == 0 && p < root-1){
			leaf.push(p);
		}
		i++;
	}
	edge.erase(0);
	
	printf("(");
	traceback(root-1);
	printf(")\n");
	edge.clear();
}

int main(){
    int num;
    char c;
        
    c = fgetc(stdin);
    while(!feof(stdin)){
		if( c == '\n'){
			printf("(1)\n");
			goto loop;
		}
		ungetc(c, stdin);
		scanf("%d%c", &num,&c);
		pos = 0;
		while(c!= '\n'){
			freq[num]++;
			node[pos++] = num;
			scanf("%d%c", &num,&c);
		}
		freq[num]++;
		node[pos++] = num;
		node[pos ] = 0;
		root = num + 1;
		fun();
		
		memset(freq,0,sizeof(freq));
		
loop:	c = fgetc(stdin);
	}    
    
    return 0;
}

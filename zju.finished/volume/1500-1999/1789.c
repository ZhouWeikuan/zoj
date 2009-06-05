#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 30008,
};

int stud[Size];
int related[Size];
int rpos;

int parent(int n){
	int p = stud[n];
	int t = stud[p];
	while(t != p){
		p = t;
		t = stud[p];
	}
	if(stud[n] != t)
		stud[n] = t;
	return t;
}

int join(int a, int b){
	int pa= parent(a);
	int pb= parent(b);
	if(pa < pb){
		stud[pb] = pa;
		stud[a] = pa;
		stud[b] = pa;
		return pa;
	}else {
		stud[pa] = pb;
		stud[a] = pb;
		stud[b] = pb;
		return pb;
	}
}

int main(){
	int n,m;
	int i,j,t;
	int first,un;

	scanf("%d %d", &n, &m);
	while(n > 0){
		stud[0] = rpos = 0;
		related[rpos++] = 0;
		for(i=1;i<n;i++){
			stud[i] = -1;
		}
		for(i=0; i<m;i++){
			scanf("%d", &un);
			if(un <= 0)
				continue;
			scanf("%d", &first);
			if(stud[first] ==-1) {
				stud[first] = first;
				related[rpos ++] = first;
			} else {
				first = parent(first);
			}
			j = 1;
			while(j < un){
				scanf("%d", &t);
				if(stud[t] ==-1){
					related[rpos++] = t;
					if(t > first)
						stud[t] = first;
					else {
						stud[t] = stud[first] = t;
						first = t;
					}
				} else {
					first = join(t, first);
				}
				j++;
			}
		}
		int result = 0;
		for(i=0;i<rpos;i++){
			t = related[i];
			if(parent(t) == 0){
				result ++;
			}
		}
		printf("%d\n", result);
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>

using namespace std;

map<int,int> tree;

int main(){
	int max;
	int mid, mark;
	char c;

	scanf("%c ", &c);
	while( !feof(stdin) ){
		tree.clear();
		max = mark = 0;
loop:	scanf("%c ", &c);
		mid = 0;
		while(c!=')'){
			mid ++;
			if(c <='9' && c>='0'){
				int t;
				int pos = 0;
				ungetc(c,stdin);
				scanf("%d, ", &t);
				scanf("%c ", &c);
				while(c!=')'){
					if(c=='L'){
						pos = pos*2 + 1;
					}else {
						pos = pos*2 + 2;
					}
					scanf("%c ", &c);
				}
				if(tree.find(pos) == tree.end() ) {
					tree[pos] = t;
					if(max < pos)
						max = pos;
				}
				else
					mark = 1;
			}
		}
		if(mid ==0 ){
			if(mark == 0){
				int i;
				map<int,int>::iterator iter = tree.begin();
				if(tree.size() ==0){
					;
				}else if(tree.find(0) == tree.end() )
					mark = 1;
				else 
				for(iter++;iter!= tree.end();iter++){
					int pos = iter->first;
					pos = (pos-1)/2;
					if(tree.find(pos) == tree.end() ){
						mark = 1;
						break;
					}
				}
				
			}
			if(mark ==1){
				printf("not complete\n");
			} else if(tree.size() == 0){
				printf("\n");
			}else {
				int i;
				map<int,int>::iterator iter = tree.begin();
				printf("%d", iter->second);
				for(iter++ ; iter!= tree.end() ;iter++){
					printf(" %d",iter->second);
				}
				printf("\n");
			}
		}else {
			scanf("%c ", &c);
			goto loop;
		}
		
		scanf("%c ", &c);
	}

	return 0;
}

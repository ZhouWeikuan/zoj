#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
int num, total;
char buf[120];
map<unsigned,int> table;

void Input(){
	int t;
	char pre,cur;
	scanf("%c",&pre);
	while(1){
		scanf("%c",&cur);
		if(cur == '\n'){
			if(--num == 0)
				break;
		} else {
			t = ((int)pre<<8) + cur;
			table[t] ++;
			pre = cur;
			total ++;
		}
	}
}
struct Node {
	int a;
	int f;
	struct cmp {
		int operator()(const Node&a,const Node&b){
			if(a.f != b.f)
				return a.f > b.f;
			return a.a < b.a;
		}
	};
};
void Output(){
	vector<Node> v;
	Node one;
	for(map<unsigned,int>::iterator it = table.begin();
		it!= table.end();
		it++){
		one.a = it->first;
		one.f = it->second;
		v.push_back(one);
	}
	table.clear();
	sort(v.begin(),v.end(),Node::cmp());
	char c[3]= {0};
	double t;
	for(int i=0;i<5;i++){
		Node &cur = v[i];
		c[0] = cur.a>>8; c[1] = cur.a &0x0ff;
		t = cur.f; t /= total;
		printf("%s %d %.6lf\n",c,cur.f,t);
	}
}

int main(){
	
	scanf("%d ",&num);
	while(num){
		total = 0;
		Input();
		Output();	
		printf("\n");
		scanf("%d ",&num);
	}
	return 0;
}

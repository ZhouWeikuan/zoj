#include<iostream>
#include<deque>
#include<queue>
#include<list>

using namespace std;
int turn;

void get_input(queue<int>& q){
	int d;	
	scanf("%d",&d);
	while(d){
		q.push(d);
		scanf("%d",&d);
	}	
}
void print_q(queue<int>& q){
	int d = q.front(); q.pop();
	printf("%d", d);
	while(!q.empty()){
		d = q.front(); q.pop();
		printf(" %d", d);
	}
	printf("\n");
}

void print_list(deque<int> & q){
	if(q.size()==0){
		printf("NULL\n");
		return;
	}
	deque<int>::iterator first = q.begin();
	printf("%d", *first);
	for(++first; first!=q.end(); ++first){
		printf(" %d", *first);
	}
	printf("\n");
}

int fun(){
	int d = 0;
	queue<int> player[2];
	get_input(player[0]);
	get_input(player[1]);
	
  	deque<int> table;  	
  	deque<int>::iterator first, endbound;
    while(turn -- && !player[0].empty() && !player[1].empty()){
		queue<int> &cur = player[d]; d= 1-d;
		int n = cur.front(); cur.pop();
		table.push_back(n);
		endbound = table.end();
		-- endbound;
		for(first=table.begin(); first != endbound; ++first){
			if(*first != n){
				continue;
			}
			n = table.back(); table.pop_back();
			cur.push(n);
			n = table.back(); 
			while(n != *first){
				cur.push(n);
				table.pop_back();
				n = table.back();				
			}
			cur.push(n);
			table.pop_back();						
			break;
		}
	}
	if(player[0].empty() || player[1].empty()){
		if(player[0].empty()){
			printf("B\n");
		} else {
			printf("A\n");
		}
	} else {
		print_q(player[0]);
		print_q(player[1]);
		print_list(table);
	}
}

int main(){
  	int tstcase = 0;
  	
	scanf("%d",&turn);
  	while(turn){
		printf("Case %d:\n", ++tstcase);		
		fun();
				
		cin>>turn;
	}
    
    return 0;
}

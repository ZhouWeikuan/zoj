#include<iostream>
#include<queue>

using namespace std;

int visit[208];
int divor;
int num;
struct Node {
	int pred;
	int value;
	int remind;	
};

Node tree[1000];

void traceback(int n){
	if(n < 0)
		return;
	traceback(tree[n].pred);
	cout<<tree[n].value;
}

void fun(){    
	if(num == 1){
		cout<<num<<endl;
		return ;
	}  
    divor = num; num = 0;
    memset(visit,0,sizeof(visit));
    tree[num].value = 1;
    tree[num].pred = -1;
    tree[num].remind = 0;    
    queue<int> q;
    q.push(num); num++;
    int cur;
    Node *one;
    while(1){
		cur = q.front(); q.pop();
		one = &tree[cur];
		one->remind *= 10; one->remind += one->value; one->remind %= divor;
		if(one->remind ==0){
			traceback(cur);
			cout<<endl;
			return;
		}
		if(visit[one->remind] == 1){
			continue;
		}
		visit[one->remind] = 1;
		
		tree[num].pred = cur;
		tree[num].value = 0;
		tree[num].remind = one->remind;
		q.push(num); 
		num ++;
		
		tree[num].pred = cur;
		tree[num].value = 1;
		tree[num].remind = one->remind;
		q.push(num); 
		num ++;
	}
}

int main(){
	
	cin>>num;
	while(num){
		fun();
		cin>>num;
	}  
    
    return 0;
}

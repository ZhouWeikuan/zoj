#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

enum {
	Size = 5842,
};

long long humble[Size];
int pos;

void init(){
	long long n;
	long long value;
	set<long long> table;
	priority_queue<long long, vector<long long>, greater<long long> > que;
	pos = 0;
	que.push(1ll);
	table.insert(1ll);
	
	while(pos < Size){
		n = que.top();
		que.pop();
		humble[pos ++] = n;
		
		value = n*2;
		if(value > 0 && table.find(value) == table.end()){
			que.push(value);
			table.insert(value);
		}
		
		value = n*3;
		if(value > 0 && table.find(value) == table.end()){
			que.push(value);
			table.insert(value);
		}
		
		value = n*5;
		if(value > 0 && table.find(value) == table.end()){
			que.push(value);
			table.insert(value);
		}
		
		value = n*7;
		if(value>0 && table.find(value) == table.end()){
			que.push(value);
			table.insert(value);
		}
	}
	
}

void printnumber(int n){
	int suff;
	int oct;
	suff = n %10;
	oct = n %100;
	if(suff ==0 || suff>3 ||  (oct >10 && oct <14) ){
		printf("%dth", n);
		return;
	}
	
	if(suff ==1){
		printf("%dst", n);
	} else if(suff==2){
		printf("%dnd", n);
	} else {
		printf("%drd", n);
	}
	
}

int main(){
    int num;    
    int index;
    init();
    
    scanf("%d", &index);
    while(index ){
		num = humble[index-1];
		
		printf("The ");
		printnumber(index);
		printf(" humble number is %d.\n", num);
		
		scanf("%d", &index);
	}
    
    return 0;
}

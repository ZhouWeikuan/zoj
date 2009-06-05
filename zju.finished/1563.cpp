#include<iostream>
#include<vector>
#include<map>

using namespace std;
int price[120];
int num;
map<unsigned,int> table;

struct Node {
	int cate;
	int count;
};
Node pearl[120];

int canmove(Node &a, Node &b){
	int p = price[a.cate] * (a.count+10) + price[b.cate] *(b.count+10);
	int q = price[b.cate] *(a.count + b.count + 10);
	if(p < q){
		return 0;
	}
	return q - p;
}
int fun(int s){
	int ret=0,i,t;
	unsigned key = (pearl[s].count<<8) + (s);
	if(table.find(key)!= table.end())
		return table[key];
	
	for(i=s;i<num;i++){
		ret += (pearl[i].count + 10) * price[pearl[i].cate];
	}
	if(s >= num -1)
		return table[key]=ret;
	t = (pearl[s].count+10)*price[pearl[s].cate] + fun(s+1);
	if(t < ret)
		ret = t;
	if(!canmove(pearl[s], pearl[s+1])){
		return table[key] = ret;
	}
	pearl[s+1].count += pearl[s].count;
	t = fun(s + 1);
	pearl[s+1].count -= pearl[s].count;
	if(t < ret)
		ret = t;
	return table[key] = ret;
}

int main(){
	int tstcase;
	Node one;
	cin>>tstcase;
	while(tstcase --){
		cin>>num;
		table.clear();
		for(int i=0;i<num;i++){
			cin>>pearl[i].count;
			pearl[i].cate = i;
			cin>>price[i];
		}
		cout<<fun(0)<<endl;
	}

	return 0;
}

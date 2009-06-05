#include<iostream>
#include<map>
#include<queue>

using namespace std;

int move[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
int lim[] = {	1,
				10,
				100,
				1000,
				10000,
				100000,
				1000000,
				10000000,
				100000000
			};

struct Node {
	int step;
	int next[4];
	int i,j;
};

map<int,Node> table;

void expand(){
	int key = 123456780;
	int nk,ni,nj,pos,npos,v;
	queue<int> q;

	Node & one = table[key];
	one.step = 0;
	one.i = 2, one.j = 2;
	q.push(key);
	while(!q.empty()){
		key = q.front(); q.pop();
		Node &o = table[key];
		pos =(2- o.i) *3 + (2-o.j);
		for(int i=0;i<4;i++){	// up
			ni = o.i + move[i][0];
			nj = o.j + move[i][1];
			if(ni>2 || ni<0 || nj>2 || nj <0){
				o.next[i] = -1;
				continue;
			}
			npos = (2-ni)*3 + (2-nj);
			v = key / lim[npos] ;
			v %= 10;
			nk = key - v * lim[npos] + v * lim[pos];
			o.next[i] = nk;
			if(table.find(nk)== table.end()){
				q.push(nk);
				Node &n = table[nk];
				n.step = o.step + 1;
				n.i = ni; n.j = nj;
			}
		}
	}
}
const char ans[4] = {'u','r','d','l'};
void find(int key){
	int step ;
	if(table.find(key) == table.end()){
		cout<<"unsolvable";
		return;
	}
	while(key != 123456780){
		Node &o = table[key];
		step = o.step;
		for(int i=0;i<4;i++){
			if(o.next[i] >0 && table[o.next[i]].step < step){
				cout<<ans[i];
				key = o.next[i];
				break;
			}
		}
	}
}

int main(){
	char d;
	int key;
	expand();

	while(cin>>d){
		if(d == 'x'){
			d = '0';
		}
		d -= '0';
		key = d;
		for(int i=0;i<8;i++){
			cin>> d;
			if(d == 'x')
				d = '0';
			d -= '0';
			key *= 10;
			key += d;
		}
		find(key);
		cout<<endl;
	}

	return 0;
}

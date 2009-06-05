#include<iostream>
#include<queue>

using namespace std;

unsigned save[0x10000];

void revert(unsigned &v, int p){
	unsigned m = 1<<p;
	if(v &m){
		v &= ~m;
	} else {
		v |= m;
	}
}

unsigned flip(unsigned v, int p){
	unsigned ret = v;
	int i = p/4, j =p%4;
	revert(ret,p);
	if(i>0){
		revert(ret, (i-1)*4+j);
	}
	if(j>0){
		revert(ret, i*4 + j-1);
	}
	if(i<3){
		revert(ret, (i+1)*4 + j);
	}
	if(j<3){
		revert(ret, i*4 + j+1);
	}
	return ret&0x0ffff;
}

void init(){
	int i;
	for(i=0;i<=0x10000;i++){
		save[i] = -1;
	}
	queue<unsigned> q;
	q.push(0);
	q.push(0x0ffff);
	save[0]=0; save[0x0ffff]=0;
	unsigned cur,one;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(i=0;i<16;i++){
			one = flip(cur,i);
			if(save[one] > save[cur]+1){
				save[one] = save[cur] + 1;
				q.push(one);
			}
		}
	}
	
}

int main(){
	unsigned val;
	int i,j,tstcase;
	char ch;
	
	init();
	cin>>tstcase;
	while(tstcase --){
		val = 0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				cin>>ch;
				if(ch =='b'){
					val |= 1<<(i*4+j);
				}
			}
		}
		if(save[val]==-1){
			cout<<"Impossible"<<endl;
		} else {
			cout<<save[val]<<endl;
		}
		if(tstcase)
			cout<<endl;
	}

	return 0;
}

#include<iostream>
#include<map>
#include<cstdlib>
#include<string>

using namespace std;

enum {
	InitValue = 0x00ffff,	
};

int heromask[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

typedef struct {
	int num;
	int degree;
	int nextnode[16];
} Node ;

Node matrix[20];
int heronum;
map<int,int> table;
map<string, int> heroname;

int fetch(string &s){
	int ret;	
	
	if(heroname.find(s) == heroname.end()){
		ret = heronum ++;
		heroname[s] = ret;
	} else {
		ret = heroname[s];
	}
	return ret;
}

int init(){	
	heronum = 0;
	int compnum;
	
	if(!( cin>>compnum) ){
		return 0;
	}
	table.clear();
	heroname.clear();
	
	int first, second;
	string sf,sn;
	memset(matrix,0,sizeof(Node) * 20);
	
	while(compnum--){
		cin>> sf >> sn;		
		first = fetch(sf);
		second = fetch(sn);
		matrix[first].nextnode[matrix[first].num ++] = second;
		matrix[second].degree ++;
	}
	
	return 1;
}

int fun(int bitmask, int num){		
    if(num == 1){
		return 1;
	}
	if(table.find(bitmask) != table.end()){
		return table[bitmask];
	}
	
	int i,j,t;
	int sum = 0;	
	for(i=0;i<heronum;i++){
		if(matrix[i].degree == 0){			
			for(j=0;j<matrix[i].num;j++){
				t = matrix[i].nextnode[j];
				matrix[t].degree--;				
			}
			matrix[i].degree = -1;
			sum += fun(bitmask - heromask[i],num-1);
			matrix[i].degree = 0;
			for(j=0;j<matrix[i].num;j++){
				t = matrix[i].nextnode[j];
				matrix[t].degree++;
			}
		}
	}
	table[bitmask] = sum;
	return sum;
}

int main(){   
   	
   	while(init()){
		cout<<fun(InitValue,heronum)<<endl;
	}
    
    return 0;
}

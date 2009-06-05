#include<iostream>
#include<map>
using namespace std;

map<int,int> table;
char firststr[204];
char secondstr[204];
char compound[408];

int fun(int i, int j , int k){
    if(compound[k] ==0)
    	return 1;
    int key = (i<<16) + (j<<8) + k;
    if(table.find(key) != table.end())
    	return table[key];
    int t = 0;
    if(firststr[i] == compound[k]){
		if(secondstr[j] == compound[k]) {
			t = fun(i,j+1,k+1);
			if(t)
				goto end;
		}
		t = fun(i+1,j,k+1);
		goto end;
	}
	if(secondstr[j] == compound[k]){
		t = fun(i,j+1,k+1);
		goto end;
	}
end:
	table[key] = t;
	return t;
}

char *ans[2] = {
	"no",
	"yes"
};

int main(){
    int tstnum;
    int i = 0;
    int t;
    
    cin>>tstnum;
    while(i< tstnum){
		i++;
		table.clear();
		cin>>firststr>>secondstr>>compound;
		t = fun(0,0,0);
		cout<<"Data set " << i <<": " << ans[t] << endl;
	}
    
    return 0;
}

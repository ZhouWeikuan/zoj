#include<iostream>
#include<queue>
using namespace std;
enum {
	Size = 108,
	MAXVALUE = 1000000,
};
int num;
int matrix[Size][Size];

int calc(int s){
	int i;
	
	int ret = 0;
	for(i=0;i<num;i++){
		if(i==s)
			continue;
		if(matrix[s][i] > ret)
			ret = matrix[s][i];
	}
	return ret;
}

void fun(){
	int i,t,s;
	int savei,savet = MAXVALUE;
	
	for(i=0;i<num;i++){
		for(s=0;s<num;s++){
			if(matrix[s][i] < MAXVALUE){
				for(t=0;t<num;t++){
					if(matrix[s][t] > matrix[s][i] + matrix[i][t]) {
						matrix[s][t] = matrix[s][i] + matrix[i][t];
						savei = 1;
					}
				}
			}
		}
	}
	
	for(i=0;i<num;i++){
		t = calc(i);
		
		if(savet > t){
			savei = i;
			savet = t;
		}

	}
	if(num ==1){
		cout<<"1 0\n";
	}else if(savet ==MAXVALUE){
		cout<<"disjoint\n";
	} else {
		cout<<savei+1<<" "<<savet<<"\n";
	}
}

int main(){
	int i,j,n,t;

	cin>>num;
	while(num > 0){
		for(i=0;i<num;i++)
			for(j=0;j<num;j++)
				matrix[i][j] = MAXVALUE;
		for(i=0;i<num;i++){
			cin>>n;
			while(n--){
				cin>>j>>t;
				j--;
				matrix[i][j] = t;
			}
		}
		fun();
		
		cin>>num;
	}
	
	return 0;
}

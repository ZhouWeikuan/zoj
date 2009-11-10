#include<iostream>

using namespace std;

int card[2008];
int num, diff;

void fun(){
	int cur = 1;
	int k = 0,i,pos,j;
	memset(card,0,sizeof(int)*num);
	for(i=0;i<num;i++){
		k = (k + diff) %(num-i);
		j = 0; pos = 0;
		while(j<= k){
			if(card[pos]==0){
				j ++;
			}
			pos ++;
		}
		card[pos-1] = cur++;
	}
	cout<<card[0];
	for(i=1;i<num;i++)
		cout<<" "<<card[i];
	cout<<endl;
}

int main(){
	
	while(cin>>num>>diff){
		fun();		
	}

	return 0;
}

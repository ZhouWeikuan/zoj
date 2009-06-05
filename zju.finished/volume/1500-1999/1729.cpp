#include<iostream>
// 求串的最小表达
// 以及求两个串是否同构一样！
//
using namespace std;
int pos;
char buf[200008];

int fun(int i,int j){
	int k = 0;
	while(i<pos && j<pos&& k<pos){
		if(buf[i+k]==buf[j+k]){
			k++;
		} else if(buf[i+k] < buf[j+k]){
			j = j+k+1;
			if(j==i)
				j++;
			k =0;
		} else {
			i = i+k + 1;
			if(i==j)
				i++;
			k=0;
		}
	}
	return (i<j)?i:j;
}

int main(){
	int tstcase;
	cin>>tstcase;
	while(tstcase --){
		cin>>pos>>buf;
		strncpy(buf+pos,buf,pos);
		buf[pos*2]=0;
		cout<<fun(0,1)<<endl;
	}

	return 0;
}

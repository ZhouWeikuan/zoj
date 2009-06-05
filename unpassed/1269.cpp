#include<iostream>

using namespace std;
int num;

int getvalue(int n, int k, int *f){
	*f = 0;
	int loop = n;
	int ret = n * k;
	while(loop --){
		ret *= n;
		if(ret %(n-1)!=0){
			*f = 1;
		}
		ret /=(n-1);
		ret += 1;
	}
	return ret;
}

void fun(){
	int n = 2, k=1;
	int print = 0;
	int value,flag;
	while(1){
		k = 0;
		value = getvalue(n,k, &flag);
		if(value > num){
			break;
		}
		while(value < num){
			k++;
			value = getvalue(n,k,&flag);
		}
		if(value == num && flag ==0){
			print = 1;
			break;
		}

		n++;
	}
	cout<<num<<" coconuts, ";
	if(print){
		cout<<n<<" people and 1 monkey"<<endl;
	} else {
		cout<<"no solution"<<endl;
	}
}

int main(){
	
	cin>>num;
	while(num >= 0){
		fun();
		cin>>num;
	}

	return 0;
}

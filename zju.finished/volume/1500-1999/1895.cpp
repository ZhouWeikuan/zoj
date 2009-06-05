#include<iostream>
#include<set>

using namespace std;

int N,S;
int result[50];
int part[12];

void fun(){
	int i,j,k,flag,t;
    multiset<int> sum;
    multiset<int>::iterator iter;
    for(i=2;i<S;i++){
		sum.insert(result[i]);
	}
	for(i=2;i<S;i++){		
		part[0] = (result[0] + result[1] - result[i])/2;
		part[1] = result[0] - part[0];
		part[2] = result[i] - part[1];
		if(part[0] > part[1] || part[1] > part[2])
			continue;
		
		multiset<int> s = sum;
		iter = s.find(result[i]);
		s.erase(iter);
		j = 3;
		flag = 0;
		while(j < N){
			iter = s.begin();
			part[j] = *iter - part[0];
			for(k=0;k<j;k++){
				if(part[j] < part[k]){
					flag = 1;
					break;
				}
				t = part[j] + part[k];
				iter = s.find(t);
				if(iter == s.end()){
					flag = 1;
					break;
				} else {
					s.erase(iter);
				}
			}
			j ++;
		}
		if(flag ==0 && s.size() ==0){
			cout<<part[0];
			for(i=1;i<N;i++){
				cout<<" "<<part[i];
			}
			cout<<endl;
			return ;
		}
	}
	cout<<"Impossible"<<endl;
}

int main(){
    int i;   
    
    while(cin>>N){
		S = N * (N-1) /2;
		for(i=0;i<S;i++){
			cin>>result[i];
		}
		sort(result, result + S);
		fun();		
	}
    
    return 0;
}

#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

priority_queue<double, vector<double>, less<double> > heap;

double fun(){
    double a,b;
    a = heap.top();
    heap.pop();
    while( ! heap.empty() ){
		b = heap.top();
		heap.pop();
		a *= b;
		a = 2 * sqrt(a);
		heap.push(a);
		
		a = heap.top();
    	heap.pop();
	}
	
	return a;
}

int main(){    
    int i;
    double t;
    int num;
    
    while(cin>>num ){		
		for(i=0;i<num;i++){
			cin>>t;
			heap.push(t);
		}
		t = fun();
		cout.precision(3);
		cout<<fixed<< t<<endl;
	}
    
    return 0;
}

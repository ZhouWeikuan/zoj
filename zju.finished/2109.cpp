#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	int javabeans;
	int catfood;
	double 	 ratio;
};

struct compare {
	int operator ()(const Node &a, const Node &b){
		return a.ratio >= b.ratio;
	}	
};

vector<Node> table;
int M;
int num;

double fun(){
	int i;
	int food = M;
	double ret = 0;
    sort(table.begin(), table.end(), compare());
    
    for(i=0;i<num;i++){
		if(food >= table[i].catfood){
			ret += table[i].javabeans;
			food -= table[i].catfood;
		} else {
			ret += table[i].ratio * food;
			break;
		}
	}
	return ret;
}

int main(){
    int i;    
    double t;
    Node n;
    
    cin>>M>>num;
    while(M >= 0){
		table.clear();
		for(i=0;i<num;i++){
			cin>>n.javabeans >> n.catfood;
			n.ratio = n.javabeans *1.0/n.catfood;
			table.push_back(n);
		}
		
		t = fun();
		cout.precision(3);
		cout<<fixed << t<<endl;
		cin>>M>>num;
	}
    
    
    return 0;
}

#include<iostream>
#include<set>
#include<string>
using namespace std;
enum {
	NO = 9,
};
struct Node {
	int submit;
	set<string> aclist;
	int total;	// total time;
};

Node prob[NO];
void init(){
	int i;
	for(i=0; i<NO; i++){
		prob[i].submit = 0;
		prob[i].total  = 0;
		prob[i].aclist.clear();
	}
}

void print(Node &n){
	double rate;
	int ac = n.aclist.size();
	cout<<" "<<ac;
	if(ac ==0) 
		goto end;
	rate = n.submit;
	rate /= ac;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<" "<<rate;

	rate = n.total;
	rate /= ac;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<" "<<rate;

end:
	cout<<endl;
}

void fun(int n){
	init();
	string name;
	int time ;
	char p,s;

	while(n--){
		cin>>time>>name>>p>>s;
		p -= 'A';
		if(prob[p].aclist.find(name)!= prob[p].aclist.end()){
			continue;
		}
		prob[p].submit ++;
		if(s=='A'){
			prob[p].aclist.insert(name);
			prob[p].total += time;
		}
	}
	for(int i=0; i<NO; i++){
		cout<< char(i+'A');
		print(prob[i]);
	}
}

int main(){
	int num;
	int tstcase = 0;

	while(cin>>num){
		if(tstcase++)
			cout<<endl;

		fun(num);

	}

	return 0;
}

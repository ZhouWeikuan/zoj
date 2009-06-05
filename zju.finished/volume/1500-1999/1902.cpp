#include<iostream>
#include<string>
#include<map>

using namespace std;
map<string,double> table;

int main(){
	int m,n;
	string keyword;
	double salary;
	map<string,double>::iterator iter;
	
	cin>>m>>n;
	while(m--){
		cin>>keyword>>salary;
		table[keyword] = salary;
	}

	while(n--){
		salary = 0;
		cin>>keyword;
		while(keyword !="."){
			iter = table.find(keyword);
			if(iter!= table.end()){
				salary += iter->second;
			}
			cin>>keyword;
		}
		cout<<salary<<endl;
	}

	return 0;
}

#include<iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
set<int> table;

int main(){
    int num;
    int t;	
	
	cin>>num;
	while(num){
        table.clear();
        while(num--){
            cin>>t;
            table.insert(t);
        }
        set<int>::iterator i=table.begin();
        cout<< *i;
        i++;
        
        for(; i!= table.end(); i++){
            cout<<" "<< *i;
        }
        cout<<endl;
        
        cin>>num;
    }
	
	return 0;
}

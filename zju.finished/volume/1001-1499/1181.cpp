#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

set<string> table;
string str;

int fun(){
	int found = 0;
	int t;
	sort(str.begin(), str.end());
	do {
        t= table.find(str) != table.end();
        if(t){
            cout<<str<<endl;
        }   
        found += t;     
    } while( next_permutation(str.begin(),str.end()) );
    if(found ==0){
        cout<<"NOT A VALID WORD"<<endl;
    }
	cout<<"******"<<endl;
}

int main(){
    
	cin>>str;
	while(str != "XXXXXX"){
        table.insert(str);
        cin>>str;
    }
	
	cin>>str;
	while(str != "XXXXXX"){
        fun();
        cin>>str;
    }
	
	return 0;
}

#include<iostream>
#include<map>
using namespace std;
/* Wrong Answer */
map<char,char> table;
char buffer[100];
char input[100];

int main(){
	int i;
	map<char,char>::iterator iter;
    cin.getline(input,100);
    cin.getline(buffer,100);
    for(i=0;input[i];i++){
		table[input[i]] = buffer[i];
	}
	cout<<buffer<<endl;
	cout<<input<<endl;
	
	while(cin.getline(input,100)){
		for(i=0;input[i];i++){
			iter = table.find(input[i]);
			if(iter != table.end()){
				input[i] = iter->second;
			}
		}
		cout<<input<<endl;
	}
    
    
    return 0;
}

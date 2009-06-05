#include<iostream>
#include<map>
#include<cctype>
#include<cmath>

using namespace std;
map<string,int> pattern;
map<string,int> document;
char buffer[260];

void fun(){
	double result = 0.0, t;
	map<string,int>::iterator iter,iter2;
	for(iter=document.begin(); iter!=document.end();iter++){
		iter2 = pattern.find(iter->first);
		if(iter2 != pattern.end()){
			t = iter->second * iter2->second;
			result += sqrt(t);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<result<<endl;
}

int mytrim(char *s){
	int i,pos = 0;
	for(i=0; s[i]; i++){
		if(isalnum(s[i])){
			s[pos++] = tolower(s[i]);
		}
	}
	buffer[pos] = 0;
	return pos;
}

int main(){
	int tstcase;
	cin>>tstcase;

	while(tstcase --){
		pattern.clear();
		cin>>buffer;
		while(strcmp(buffer,"----------")!=0){
			if(mytrim(buffer)){
				string s(buffer);
				pattern[s] ++;
			}
			cin>>buffer;
		}
		
		cin>>buffer;
		while(strcmp(buffer,"----------")!=0){
			document.clear();
			do {
				if(mytrim(buffer)){
					string s(buffer);
					if(pattern.find(s) != pattern.end()){
						document[s] ++;
					}
				}
				cin>>buffer;
			}while(strcmp(buffer,"----------")!=0);
			fun();
			cin>>buffer;
		}
		if(tstcase)
			cout<<endl;
	}

	return 0;
}

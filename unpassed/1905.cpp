#include<iostream>
#include<cstring>

using namespace std;

enum {
	Size = 1000008,	
};

char buffer[Size];
int pos;

int fun(){
    pos = strlen(buffer);
  	if(pos ==0)
  		return 0;
  	int ret = 1, mult = 2;
  	int slice = ret * mult;
  	
	while(){
	}   
    
}

int main(){
  
	cin>>buffer;
	while(buffer[0] != '.'){
		cout<<fun()<<endl;
		cin>>buffer;		
	}    
    return 0;
}

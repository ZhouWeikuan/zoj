#include<iostream>

using namespace std;

int key;
int pos;
char plaintext[80];
char plaincode[80];
char cypercode[80];
char cypertext[80];

char alpha2code(char c){
	if(c == '_')
		return 0;
	if(c == '.')
		return 27;
	return c-'a' + 1;
}

char code2alpha(char code){
	if(code ==0)
		return '_';
	if(code == 27)
		return '.';
	return code -1 + 'a';
}

int fun(){
	int i;
	int t;
	for(i=0; cypertext[i] ; i++){
		cypercode[i] = alpha2code( cypertext[i] );		
	}
	pos = i;
    for(i=0;i<pos;i++){
		plaincode[key * i % pos] = (cypercode[i] + i) % 28;
	}
    for(i=0; i<pos;i++){
		plaintext[i] = code2alpha( plaincode[i] );
	}
    plaintext[pos] = 0;
    cout<<plaintext<<endl;
}

int main(){
    
    cin>>key;
    while(key ){
		cin>>cypertext;
		fun();
		cin>>key;
	}
    
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int fbase;
int tbase;
char from[1024];
char targ[1024];
int frompos, tpos;

void char2num(char *str, int pos){
	int i;
	
	for(i=0;i<pos;i++){
		if(str[i] >='0' && str[i] <='9'){
			str[i] -= '0';
		} else if(str[i] >='A' && str[i] <='Z'){
			str[i] -= 'A';
			str[i] += 10;
		} else if(str[i] >='a' && str[i] <='z'){
			str[i] -= 'a';
			str[i] += 36;
		}
	}
}

void num2char(char *str, int pos){
	int i;
	
	for(i=0;i<pos;i++){
		if(str[i] <= 9){
			str[i] += '0';
		} else if(str[i] < 36){
			str[i] -= 10;
			str[i] += 'A';
		} else if(str[i] < 62){
			str[i] -= 36;
			str[i] += 'a';
		}
	}
}



void fun(){
	int start = 0;
	int i,j;
	int carry;
    tpos = 0;
    char2num(from, frompos);
    
    while(start < frompos){
		carry = 0;
		for(i=start; i< frompos;i++){
			carry = (from[i]  + carry * fbase);			 
			from[i] = carry / tbase;
			carry %= tbase;
		}
		targ[tpos ++] = carry;
		
		while(start < frompos && from[start] == 0 ){
			start ++;
		}
		
	}
    
    targ[tpos] = 0;
    num2char(targ, tpos);
    reverse(targ, targ+tpos);
    
}

int main(){
	int tstnum;
	
    cin>>tstnum;
    while(tstnum --){
		cin>>fbase>>tbase>>from;
		frompos = strlen(from);
		cout<<fbase<<" "<<from<<endl;
		fun();
		cout<<tbase<<" "<<targ<<endl;		
		
		cout<<endl;
	}
    
    return 0;
}

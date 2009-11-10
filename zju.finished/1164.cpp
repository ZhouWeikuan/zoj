#include<iostream>

using namespace std;

char buffer[1028];
const int divor = 34943;
void fun(){
	int i;
	unsigned key = 0;
	for(i=0;buffer[i];i++){
		key <<=8;
		key += buffer[i];
		key %= divor;
	}
	key <<= 16;
	key %= divor;
	if(key){
		key = divor - key;
	}
	unsigned char a,b;
	b = key&0x0ff;
	a = (key>>8);
	printf("%02X %02X\n",a,b);
}

int main(){
	
	cin.getline(buffer,1028);
	while(buffer[0] != '#'){
		fun();		
		cin.getline(buffer,1028);
	}

	return 0;
}

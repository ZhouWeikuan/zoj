#include<iostream>
#include<map>
using namespace std;

map<char,char> table;

void init(){
	table['A'] = 'A'; 	table['E'] = '3';
	table['I'] = 'I'; 	table['H'] = 'H';
	table['J'] = 'L'; 	table['L'] = 'J';
	table['M'] = 'M'; 	table['O'] = 'O';
	table['S'] = '2'; 	table['T'] = 'T';
	table['U'] = 'U';	table['V'] = 'V';
	table['W'] = 'W';	table['X'] = 'X';
	table['Y'] = 'Y';	table['Z'] = '5';
	table['1'] = '1';	table['2'] = 'S';
	table['3'] = 'E';	table['5'] = 'Z';
	table['8'] = '8';
}
char buffer[40];
int  pos;

const char * ans[4] = {
	"is not a palindrome.",
	"is a regular palindrome.",
	"is a mirrored string.",
	"is a mirrored palindrome."
};

int is_P(){
	int i =0,j = pos-1;
	while(j > i){
		if(buffer[i] != buffer[j])
			return 0;
		j--,i++;
	}
	return 1;
}
int is_M(){
	int i=0,j=pos-1;
	map<char,char>::iterator iter;
	while(j>=i){
		iter = table.find(buffer[j]);
		if(iter==table.end() || iter->second != buffer[i])
			return 0;
		i++,j--;
	}
	return 1;
}

int main(){
	int p,m,k;
	init();

	scanf("%s", buffer);
	while(!feof(stdin)){
		pos = strlen(buffer);
		p = is_P();
		m = is_M();
		k = (m<<1) + p;
		printf("%s -- %s\n\n", buffer, ans[k]);
		scanf("%s", buffer);
	}
	return 0;
}

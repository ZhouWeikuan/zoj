#include<iostream>
#include<map>
using namespace std;

map<char,char> table;
char buffer[1024];

void init(){
	table['1']	= '`';	table['2']	= '1';
	table['3']	= '2';	table['4']	= '3';
	table['5']	= '4';	table['6']	= '5';
	table['7']	= '6';	table['8']	= '7';
	table['9']	= '8';	table['0']	= '9';
	table['-']	= '0';	table['=']	= '-';
	table['W']	= 'Q';	table['E']	= 'W';
	table['R']	= 'E';	table['T']	= 'R';
	table['Y']	= 'T';	table['U']	= 'Y';
	table['I']	= 'U';	table['O']	= 'I';
	table['P']	= 'O';	table['[']	= 'P';
	table[']']	= '[';	table['\\']	= ']';
	table['S']	= 'A';	table['D']	= 'S';
	table['F']	= 'D';	table['G']	= 'F';
	table['H']	= 'G';	table['J']	= 'H';
	table['K']	= 'J';	table['L']	= 'K';
	table[';']	= 'L';	table['\'']	= ';';
	table['X']	= 'Z';	table['C']	= 'X';
	table['V']	= 'C';	table['B']	= 'V';
	table['N']	= 'B';	table['M']	= 'N';
	table[',']	= 'M';	table['.']	= ',';
	table['/']	= '.';	
}

int fun(){
    int i;
    for(i=0; buffer[i];i++){
		if(buffer[i] == ' '){
			continue;
		}
		
		buffer[i] = table[buffer[i]];
		
	}
	cout<<buffer <<endl;
}

int main(){
    init();
    
    while( cin.getline(buffer, 1024)){
		fun();
	}    
    return 0;
}

#include<iostream>
#include<map>
#include<string>

using namespace std;
map<string,string> table;
map<string,string> rev;

int stack[120], pos,len;
char buffer[500];
char input[120];

void fun(){
	int i = 0,t;
	pos = len = 0;
	while(input[i]){
		string s; s +=(input[i]);
		s = table[s];
		t = s.length();
		strcpy(buffer+len,s.c_str());
		len += t;
		stack[pos ++] = t;

		i++;
	}
	buffer[len] = 0;
	reverse(stack,stack+pos);
	i = 0,t = 0;
	while(i < len){
		string s(buffer+i, buffer+i+stack[t]);
		i += stack[t];
		s = rev[s];
		input[t] = s[0];
		t ++;
	}
	input[t] = 0;	
}

void init(){
	table["A"] = ".-"; 	table["B"] = "-..."; 	table["C"] = "-.-.";
	table["D"] = "-..";	table["E"] = "."; 	table["F"] = "..-.";
	table["G"] = "--.";	table["H"] = "...."; 	table["I"] = "..";
	table["J"] = ".---";	table["K"] = "-.-"; 	table["L"] = ".-..";
	table["M"] = "--";	table["N"] = "-.";	table["O"] = "---";
	table["P"] = ".--.";	table["Q"] = "--.-";	table["R"] = ".-.";
	table["S"] = "...";	table["T"] = "-";	table["U"] = "..-";
	table["V"] = "...-";	table["W"] = ".--";	table["X"] = "-..-";
	table["Y"] = "-.--";	table["Z"] = "--..";	table["_"] = "..--";
	table[","] = ".-.-";	table["."] = "---.";	table["?"] = "----";
	map<string,string>::iterator iter;
	for(iter = table.begin(); iter!= table.end(); iter++){
		rev[iter->second] = iter->first;
	}
}

int main(){
	int tstcase,tstnum = 0;
	init();
	
	cin>>tstcase;
	while(tstnum++ < tstcase){
		cin>>input;
		fun();
		cout<<tstnum<<": "<< input<<endl;
	}

	return 0;
}

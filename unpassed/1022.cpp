#include<cstring>
#include<cctype>
#include<iostream>
#include<string>
#include<map>

using namespace std;
enum {
	Size = 108,
};

char buffer[Size];

struct Command {
	int cmdno;		//0-mov, 1-add 2-sub;
	int from;		//0, into the register 1, from the register 2,into and const
	int regno;		//0 or 1
	int varno;		// address of variable;
};

struct Status {
	int reg[2];
	int varno;
};

int variable[20];
double res[20];
int num, kind ;
Command com[2][200];
int pos[2];
int reg[2][2];

map<string,int> table;

int getvariable(int s, int e, int&t){
	string str;
	char c,first ;
	t = 0;
	first = (buffer[s]);
	if(isdigit(first)){
		t=2;
		e = s+ 1;
		while(isdigit(buffer[e]))
			e++;
		c = buffer[e];
		buffer[e] = 0;
		int value = atoi(&buffer[s]);
		buffer[e] = c;
		return value;
	}
	while(s < e){
		c = tolower(buffer[s]);
		str += c;
		s++;
	}
	map<string,int>::iterator iter = table.find(str);
	if(iter != table.end()){
		return iter->second;
	}
	table[str] = num;
	return num++;
}
void unexecute(int prog, int cmdno, Status &s){
	Command &n = com[prog][cmdno];
	if(n.cmdno == 1){// add
		reg[prog][0] -= reg[prog][1];
	} else if(n.cmdno==2){// sub
		reg[prog][0] += reg[prog][1];
	} else {
		if(n.from == 1){
			variable[n.varno] = s.varno;
		}
		reg[prog][0] = s.reg[0];
		reg[prog][1] = s.reg[1];
	}
}
void execute(int prog, int cmdno, Status &s){
	Command &n = com[prog][cmdno];
	s.reg[0] = reg[prog][0];
	s.reg[1] = reg[prog][1];
	
	if(n.cmdno==0){ // mov
		if(n.from == 0){ // from var to reg
			reg[prog][n.regno] = variable[n.varno];
		} else if(n.from == 1){ // from reg to var
			s.varno = variable[n.varno];
			variable[n.varno] = reg[prog][n.regno];
		} else {  // from const to reg
			reg[prog][n.regno] = n.varno;
		}
	} else if(n.cmdno == 1){ // add
		reg[prog][0] += reg[prog][1];
	} else if(n.cmdno ==2){  // sub
		reg[prog][0] -= reg[prog][1];
	}
}

int stack[200];
int stop = 0;

void fun(int x, int y){
	if(x==pos[0] && y== pos[1]){
		kind ++;
		map<string,int>::iterator iter;
		for(iter=table.begin();iter!=table.end();iter++){
			res[iter->second] += variable[iter->second];
		}
		for(int i=0;i<stop;i++){
			cout<<"("<<(stack[i]>>16)<<","<< (stack[i]&0xffff) <<") ";
		}
		cout<<" "<< variable[0]<< endl;
	}
	int save;
	Status stat;
	
	if(x < pos[0]){
		if(com[0][x].cmdno == 0 && com[0][x].from == 1){
			save = variable[ com[0][x].varno ];
		}
		execute(0,x,stat);
		stack[stop++] = x;
		fun(x+1,y);
		stop--;
		unexecute(0,x,stat);
		if(com[0][x].cmdno == 0 && com[0][x].from == 1){
			variable[ com[0][x].varno ] = save;;
		}
	}

	if(y < pos[1]){
		if(com[1][y].cmdno == 0 && com[1][y].from == 1){
			save = variable[ com[1][y].varno ];
		}
		execute(1,y,stat);
		stack[stop++] = (1<<16)+y; 
		fun(x,y+1);
		stop --;
		unexecute(1,y,stat);
		if(com[1][y].cmdno == 0 && com[1][y].from == 1){
			variable[ com[1][y].varno ] = save;;
		}
	}

}

void parse(int n){
	int result;
	int type; //0,2
	int value;
	int i,cmd;
	int s,e;
	for(i=0;buffer[i]==' ';i++){
		;
	}
	s = i;
	for(;buffer[i]!=':';i++){
		;
	}
	e=i-1;
	while(buffer[e] ==' '){
		e--;
	}
	e ++;
	result = getvariable(s,e, type); 
	for(;buffer[i]!='=';i++){
		;
	}
	i++;
	for(;buffer[i]==' ';i++){
		;
	}
	s = i;
	for(;buffer[i]!='+' && buffer[i]!='-';i++){
		;
	}
	e = i-1; cmd = buffer[i];
	while(buffer[e] ==' '){
		e--;
	}
	e++;
	value = getvariable(s,e,type);
	Command one;
	one.cmdno = 0;
	one.from = type;
	one.regno = 0;
	one.varno = value;
	com[n][pos[n]++] = one;

	for(i++;buffer[i]==' ';i++)
		;
	s = i;
	for(;buffer[i]!=' '&&buffer[i]!=0;i++)
		;
	e = i;
	value = getvariable(s,e,type);
	one.cmdno = 0;
	one.from = type;
	one.regno = 1;
	one.varno = value;
	com[n][pos[n]++] = one;

	one.from = 1;
	one.regno = 2;
	one.varno = 2;
	if(cmd == '+'){
		one.cmdno = 1;
	} else {
		one.cmdno = 2;
	}
	com[n][pos[n]++] = one;

	one.cmdno = 0;
	one.from = 1;
	one.regno = 0;
	one.varno = result;
	com[n][pos[n]++] = one;
}

int main(){
	int tstcase;
	int i;

	cin>>tstcase;
	cin.getline(buffer,Size);
	while(tstcase-- ){
		kind = num = pos[0] = pos[1] = 0;
		table.clear();
		
		cin.getline(buffer,Size);
		while(strcmp("END",buffer)!=0){
			parse(0);
			cin.getline(buffer,Size);
		}
		
		cin.getline(buffer,Size);
		while(strcmp("END",buffer)!=0){
			parse(1);
			cin.getline(buffer,Size);
		}
		
		for(i=0;i<num;i++){
			variable[i] = 0;
			res[i] = 0;
		}

		fun(0,0);
		for(i=0;i<num;i++){
			res[i] /= kind;
		}
		for(map<string,int>::iterator iter = table.begin();
				iter != table.end(); iter++){
			cout.setf(ios::fixed);
			cout.precision(4);
			cout<<res[iter->second]<<endl;
		}

		if(tstcase)
			cout<<endl;
	}

	

	return 0;
}

#include<iostream>
#include<deque>

using namespace std;
deque<int> operand;
deque<char> opter;
enum {
	NOT = 8, AND = 5, OR = 3, 
	BRANK = 1,
};

void process(int op){
	int a,b;
	a = operand[0]; operand.pop_front();
	if(op == NOT){
		a = !a;
	} else {
		b = operand[0]; operand.pop_front();
		if(op == AND ){
			a &= b;
		} else {
			a |= b;
		}
	}
	operand.push_front(a);
}

int fun(){
	int c,op;
read:switch(c = cin.get()){
		case '\n':
		case EOF:  
			if(!operand.size()){
				return -1;
			}
			break;
		case ' ':  goto read;
		case ')':
			op = opter[0]; opter.pop_front();
			while(op != BRANK){
				process(op);
				op = opter[0]; opter.pop_front();
			}
			goto read;
		case 'F':
			c = 0;
		case 'V':
			if(c) c = 1;
			operand.push_front(c);
			goto read;
		case '(':
			c = BRANK; opter.push_front(c);
			goto read;
		case '!':
			c = NOT; goto mylast;
		case '&':
			c = AND; goto mylast;
		case '|':
			c = OR; goto mylast;
		default :
		mylast:
			if(opter.size()){
				if(c == NOT){
					while(opter.size() && c < opter[0]){
						op = opter[0]; opter.pop_front();
						process(op);
					}
				} else {
					while(opter.size() && c <= opter[0]){
						op = opter[0]; opter.pop_front();
						process(op);
					}
				}
			}
			opter.push_front(c);
			goto read;
	}
	while(opter.size()){
		op = opter[0]; opter.pop_front();
		process(op);
	}
	c = operand[0]; operand.clear();opter.clear();
	return c;
}

int main(){
	int tstcase=0;
	int ret;
	char ans[2] = {'F','V'};
	while(EOF != (ret = fun())){
		cout<<"Expression "<<++tstcase<<": ";
		if(ret >=0){
			cout<<ans[ret]<<endl;
		}
	}

	return 0;
}

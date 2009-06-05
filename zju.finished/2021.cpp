#include<iostream>
using namespace std;

enum {
	SIZ = 280,
    Neg = 0,        // +- before a value    e.g. a+(-b+c)
    AddSub = 1,     // +- operators         e.g. a+b a-b
    Minus = 2,      // - before ()          e.g. a-(b+c)
    MultDiv = 3,    // */ operators         e.g. a*(b*c), a+(b/c), a-(b*c)
    Div = 4,        // / before ()          e.g. a/(b*c)
    None = 5,       // (x)                  e.g. a+(x)
};
struct Node{
    int  s, e;
    char p, b; // start, end, priority in (), priority before (),
               // if b<=p, we can erase the ()
    bool f;  // there is +- before any symbol?
};

char buf[SIZ];
int pos;
Node par[SIZ];

char getPrio(char c){
    switch(c){
        case '+':
        case '-':
            return AddSub;
        case '*':
        case '/':
            return MultDiv;
    }
    return None;
}
void fun(){
    int i;
    char p;
    pos = 0;
    par[pos].b = 10;
    par[pos].p = None;
    par[pos].f = true;
    p = None;
    for(i=0;buf[i]!='\n';i++){
		if(buf[i] =='('){
            par[pos].f = false;
            pos++;
            par[pos].s = i;
            p += i && (buf[i-1]=='-' || buf[i-1]=='/');
            par[pos].b = p;
            par[pos].p = None;
            par[pos].f = true;
            p = None;
			continue;
		}else if(buf[i] == ')'){
            par[pos].e = i;
            p = getPrio(buf[i+1]);
            if((par[pos].b == None || par[pos].b <= par[pos].p)
                &&(p==None||p <= par[pos].p)){
                buf[par[pos].s] = buf[par[pos].e] = ' ';
                par[pos-1].p = min(par[pos].p, par[pos-1].p);
            }
            --pos;
			continue;
		}
        if(isalpha(buf[i])){
            par[pos].f = false;
            continue;
        }
        p = getPrio(buf[i]);
        if(p==AddSub && par[pos].f && isalpha(buf[i+1])){
            p = Neg;
        }
        par[pos].p = min(par[pos].p, p);
        par[pos].f = false;
    }

    // for output
    int j = 0;
    for(i=0;buf[i]!='\n';i++){
        if(buf[i] != ' '){
            buf[j++] = buf[i];
        }
	}
	buf[j] = 0;
	printf("%s\n",buf);
}

int main(){
    int num;
    scanf("%d ", &num);
    while(num --){
		fgets(buf,SIZ,stdin);
		fun();		
	}
    return 0;
}


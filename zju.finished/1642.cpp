#include<iostream>

using namespace std;
enum {
    SIZ = 2001,
    LEN = 300,
};

char first[SIZ],second[SIZ];
int bonus[LEN];
int table[SIZ][SIZ];

int fun(int f, int s){
	if(first[f] ==0 || second[s] == 0)
		return 0;
	if(table[f][s] >= 0)
		return table[f][s];
	int m = 0,t;
	if(first[f] == second[s]){
		m = bonus[first[f]];
		m += fun(f+1,s+1);
	} 
    t = fun(f+1,s);
    m = t>m?t:m;
	t = fun(f,s+1);
    m = t>m?t:m;
	table[f][s] = m;
	return m;
}

int main(){
	int num;
	char c; int b;
	
	while(scanf("%d ", &num) > 0){
		memset(table,-1,sizeof(table));
		memset(bonus,0,sizeof(bonus));
		while(num--){
            scanf(" %c %d", &c, &b);
			bonus[c] = b;
		}
        scanf("%s %s ", first,second);
        printf("%d\n", fun(0,0));
	}

	return 0;	
}

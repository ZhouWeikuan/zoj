#include<cstdio>

using namespace std;
char words[100008][12];
int num;

void trace(int s, int e, int t){
	if(s >= e)
		return;
	int i;
	char c = words[s][t];
	for(i = s +1; i < e; i++){
		if(words[i][t] != c)
			break;
	}
	for(int k=0;k <t;k++){
		printf(" ");
	}
	printf("%s",words[s]);
	trace(s+1,i,t+1);
	trace(i,e,t);
}

int main(){
	int tstcase;
	
	scanf("%d",&tstcase);
	fgets(words[0],12,stdin);
	while(tstcase --){
		num = 0;
		fgets(words[0],12,stdin); //blank line
		num = -1;
		do {
			num ++;
			fgets(words[num],12,stdin);
		} while( words[num][0] != '\n' && words[num][0]!=0 );
		trace(0,num,0);
		if(tstcase)
			printf("\n");
	}

	return 0;
}

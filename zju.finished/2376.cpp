#include<cstdio>

using namespace std;
int num,len;

void fun(){
	int early = 0,late=0;
	int a,b,i;
	for(i=0;i<num;i++){
		scanf("%d ",&a);
		b = len - a;
		if(a < b){
			early = early < a?a:early;
			late = late < b?b:late;
		}else {
			early = early < b?b:early;
			late = late<a?a:late;
		}
	}
	printf("%d %d\n",early, late);
}

int main(){
	int tstcase,i;
	
	scanf("%d ",&tstcase);
	while(tstcase --){
		scanf("%d%d ",&len,&num);
		fun();
	}

	return 0;
}

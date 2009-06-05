int primelist[200] = {2,3,5,7};
int num = 4;

void init(){
	int n,i;
	int lim;
	int flag ;
	for(n=9;n<1000;n+=2){
		lim = (int)sqrt(n) + 1;
		flag = 0;
		for(i=0;primelist[i] < lim;i++){
			if(n % primelist[i] == 0){
				flag = 1;
				break;
			}
		}
		if(flag ==0){
			primelist[num++] = n;
		}
	}
}

int main(){
	int i;
	init();
	for(i=0;i<30;i++){
		printf("%d ", primelist[i]);
	}
	scanf("%d",&i);
	return 0;
}

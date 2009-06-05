#include<cstdio>

using namespace std;

int num;

int main(){
  
  	scanf("%d", &num);
    while(num > 0){
		printf("%d\n", num / 2);
		scanf("%d", &num);
	}
    return 0;
}

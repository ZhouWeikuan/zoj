#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int fun(){
    
}

int main(){
    char buffer[1024];
    int mileage;
    int dis;
    char level;
    
    scanf("%s", buffer);
    while(buffer[0] !='#' || strlen(buffer) != 1){
		mileage = 0;
		while(buffer[0] != '0' || strlen(buffer) != 1){
			scanf("%s %d %c ", buffer, &dis, &level);
			switch(level){
				case 'F':
					mileage += 2 * dis;
					break;
				case 'B':
					mileage += 3 *dis / 2;
					break;
				case 'Y':
					if(dis < 500)
						dis = 500;
					mileage += dis;
					break;
			}
			scanf("%s", buffer);
		}
		printf("%d\n", mileage);
		scanf("%s", buffer);
	}
    
    return 0;
}

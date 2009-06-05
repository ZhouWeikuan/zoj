#include<stdio.h>

int pack[6];

int fun(){
    int ret = pack[5]; /*  6x6 */
    
    /* 5x5 */
    ret += pack[4];
    pack[0] -= 11 * pack[4];
    if(pack[0] < 0)
    	pack[0] = 0;
    
    /* 4x4 */
    ret += pack[3];
    if(pack[1] >= 5 * pack[3]){		
		pack[1] -= 5 *pack[3];
	} else {
		pack[0] -= (5 * pack[3] - pack[1])*4;
		pack[1] = 0;
		if(pack[0] < 0)
			pack[0] = 0;		
	}
	
	/* 3x3 */
	ret += pack[2]/4;
	pack[2] %= 4;
	ret += (pack[2] != 0);
	if(pack[2] ==1){
		if(pack[1] >= 5){
			pack[1]-= 5;
			pack[0] -= 7;
		} else {
			pack[0] -= 27 - 4*pack[1];
			pack[1] = 0;
		}
		if(pack[0] < 0)
			pack[0] = 0;		
	}else if(pack[2] ==2){
		if(pack[1] >= 3){
			pack[1] -= 3;
			pack[0] -=6;
		} else {
			pack[0] -= 18 - 4*pack[1];
			pack[1] = 0;
		}
		if(pack[0] < 0)
			pack[0] = 0;		
	}else if(pack[2] ==3){
		if(pack[1]){
			pack[1] -= 1;
			pack[0] -= 5;
		} else {
			pack[0] -= 9;
		}
		if(pack[0] < 0)
			pack[0] = 0;
	}
	
	/* 2x2 */
	ret += pack[1]/9;
    pack[1] -= pack[1]/9 * 9;
	if(pack[1]){
		ret += 1;
		pack[0] -= 36 - 4*pack[1];
		pack[1] = 0;
		if(pack[0] < 0)
			pack[0] = 0;
	}
	
	/* 1x1 */
	ret += pack[0] /36;
    ret += (pack[0] %36)!=0;
    return ret;
}

int main(){
    int i;
    int sum =0;
    
    for(i=0;i<6;i++){
		scanf("%d",&pack[i]);
		sum += pack[i];
	}
	while(sum){
		sum = fun();
		printf("%d\n",sum);
		
		sum = 0;
		for(i=0;i<6;i++){
			scanf("%d",&pack[i]);
			sum += pack[i];
		}
	}
    
    return 0;
}

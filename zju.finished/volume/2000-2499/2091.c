#include<stdio.h>

/* Hardness ----   4 */

int num;
int game[10000];

int main(){	
	int i;
	int j;
    int value;
    int sum;
    int t, pos;
    double maxvalue;
	double minvalue;   
    
    scanf("%d", &num);
    while(!feof(stdin)){		
		for(i=0;i<num;i++){
			scanf("%d", &game[i]);		
		}
		
		pos = num-1;
		maxvalue = sum = game[pos];
		t = 0;
		
		for(i=num-2;i>=0; i--){
			sum += game[i];			
			if(game[i] < (int)maxvalue){
				t += game[i];
			 } else	{
				if( t ){
					t += game[i];
					minvalue = t;
					minvalue /= (pos -i);
					if(minvalue > maxvalue){
						t = 0;
						pos = i;
					} else {
						continue;
					}
				} else {
					pos = i;
				}
				double p = sum;
				p /= (num - i);
				
				if(t && p > minvalue){
					p = minvalue;
				}
				if(p > maxvalue){
					maxvalue = p;
				}
			}	
		}
		
		printf("%.6lf\n", maxvalue);
		scanf("%d", &num);
	}
    
    return 0;
}

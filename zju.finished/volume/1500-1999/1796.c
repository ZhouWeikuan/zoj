#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 4,	
};

int score[Size][2];
int win, loss;

void fun(){    
    int x, y;
    x = (2 * loss - win) / 3;
    y = win +x - loss;
    
    printf("Anna's won-loss record is %d-%d.\n",x,y);
}

int main(){    
    int i;
    
    win = loss = 0;
    for(i=0;i<3;i++){
        scanf("%d %d", &score[i][0], &score[i][1]);
        win += score[i][0];
        loss += score[i][1];
    }
	while( win + loss ){
        fun();
        
        win = loss = 0;
        for(i=0;i<3;i++){
            scanf("%d %d", &score[i][0], &score[i][1]);
            win += score[i][0];
            loss += score[i][1];
        }
    }
	
	return 0;
}

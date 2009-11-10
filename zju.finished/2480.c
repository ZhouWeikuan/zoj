#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int xlow;
	int xhigh;
	int ylow;
	int yhigh;	
}Window;

Window win[12];
int wnum;

int is_in_window(Window *w, int x, int y){
	return (x<=w->xhigh && x >= w->xlow) && (y<= w->yhigh && y>= w->ylow);
}

void determine(){
	int x, y;
	int pos;	
	scanf("%d %d ", &x, &y);
	for(pos=wnum-1;pos>=0; pos--){
		if(is_in_window(&win[pos],x,y)){
			break;
		}
	}
	printf("%d\n",pos);
}

void fun(){
    int click;
    int pos;
    scanf("%d", &click);
    while(click --){
		determine();
	}
}

void init(){
	int i;	
	for(i=0;i<wnum;i++){
		scanf("%d %d %d %d", &win[i].xlow, &win[i].ylow, &win[i].xhigh, &win[i].yhigh);	
	}
}

int main(){    
    
    scanf("%d", &wnum);
    while(wnum){
		init();
		fun();
		scanf("%d", &wnum);	
	}
    
    return 0;
}

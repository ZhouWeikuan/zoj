#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct {
	int r;
	int g;
	int b;
} Node;

enum {
	Size = 16,
};

Node color[Size];

int r,g,b;

void fun(){
    int i,t = -1;
    double value, min = 1024.0;
    
    for(i=0;i<Size;i++){
		value = (r - color[i].r)*(r - color[i].r) + (g - color[i].g)*(g - color[i].g) + (b - color[i].b)*(b - color[i].b);
		value = sqrt(value);
		if(value < min){
			min = value;
			t = i;
		}
	}    
    
    printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r,g,b, color[t].r,color[t].g,color[t].b);
}

int main(){
    int i;
    for(i=0;i<Size;i++){
		scanf("%d %d %d ", &color[i].r, &color[i].g, &color[i].b);
	}
	
	scanf("%d %d %d ", &r, &g, &b);
	while(r != -1 || g!= -1 || b!= -1){
		fun();		
		scanf("%d %d %d ", &r, &g, &b);
	}
	
    
    return 0;
}

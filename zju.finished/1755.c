#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 10,	
};

typedef struct {
    char name[12];
    int  value;
} Node;

Node stu[Size];
int  array[Size];
int num;

int mycomp(const int *a, const int *b){
    return stu[*a].value - stu[*b].value;	
}

int main(){
	int a,b,c;
	int i;
	
	scanf("%d", &num);
	while(num >0){
        for(i=0;i<num;i++){
            scanf("%d %d %d %s", &a, &b, &c, stu[i].name);
            stu[i].value = a * b * c;
            array[i] = i;
        }
        qsort(array, num, sizeof(int), mycomp);
        printf("%s took clay from %s.\n",stu[array[num-1]].name, stu[array[0]].name);
        scanf("%d", &num);
    }
	
	return 0;
}

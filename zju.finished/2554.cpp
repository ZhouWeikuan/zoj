#include<iostream>
using namespace std;
enum {
    SIZ = 200008,
};
struct Node {
    int x,y;
};
Node t[SIZ];
int num;

int readIn(){
    scanf("%d ", &num);
    if(num == 0)
        return 0;
    for(int i=0;i<num;i++){
        scanf("%d%d ", &t[i].x, &t[i].y);
    }
    return 1;
}

void fun(){
    int s=0, o = 0;
    int i; Node *p= &t[num/2];
    for(i=0;i<num;i++){
        if(t[i].x < p->x){
            if(t[i].y < p->y){
                s ++;
            } else if(t[i].y > p->y){
                o ++;
            }
        } else if(t[i].x > p->x){
            if(t[i].y < p->y){
                o ++;
            } else if(t[i].y > p->y){
                s ++;
            }
        }
    }
    printf("%d %d\n", s, o);
}

int main(){
    
    while(readIn()){
        fun();
    }

	return 0;
}

#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 2080,
};
char buf[SIZ][SIZ];
int num;

inline int w(int d){
    return 1<<(d+1);
}
inline int h(int d){
    return 1<<(d);
}

void write(int x, int y, int d){
    if(d == 1){
        char *p = &buf[x][y+1];
        *p++='/'; *p++='\\';
        p = &buf[x+1][y];
        *p++='/'; *p++='_'; *p++='_'; *p++='\\';
        return;
    }
    write(x, y + w(d-1)/2, d-1);
    write(x+h(d-1), y, d-1);
    write(x+h(d-1), y+w(d-1), d-1);
}

int fun(){
    memset(buf, ' ', sizeof(buf));
    write(0,0,num);
    int line = 1<<num;
    for(int i=0;i<line;i++){
        for(int j=SIZ-1;buf[i][j]==' ';j--){
            buf[i][j] = 0;
        }
        printf(buf[i]);
        printf("\n");
    }
    return 0;
}

int main(){

    scanf("%d",&num);
    while(num){
        fun();
        printf("\n");
        scanf("%d",&num);
    }

	return 0;
}

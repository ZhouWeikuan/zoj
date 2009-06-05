#include<iostream>
using namespace std;
enum {
    Row = 5,
    Col = 6,
};
int light[Row][Col];
int press[Row][Col];
inline void set(int r, int c){
    light[r][c] = 1 - light[r][c];
    if(r > 0) light[r-1][c] = 1 - light[r-1][c];
    if(c > 0) light[r][c-1] = 1 - light[r][c-1];
    if(r < Row -1) light[r+1][c] = 1 - light[r+1][c];
    if(c < Col -1) light[r][c+1] = 1 - light[r][c+1];
}
int test(int r, int c){
    if(c == Col)
        return 1;
    int nr = (r + 1) % Row,nc = (r+1)/Row + c;
    press[r][c] = 0;
    if(c==0 || 
         (c>0 && light[r][c-1]==0
             &&(c==Col-1&&r>0?(light[r-1][c]==0&&(r==Row-1?(light[r][c]==0):1)):1))){
        if(test(nr,nc))
            return 1;
    }
    press[r][c] = 1;
    set(r,c);
    if(c==0||
        (c>0 && light[r][c-1]==0
            &&(c==Col-1&&r>0?(light[r-1][c]==0&&(r==Row-1?light[r][c]==0:1)):1))){
        if(test(nr,nc))
            return 1;
    }
    set(r,c);
    return 0;
}
void readIn(){
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            scanf("%d",&light[i][j]);
        }
    }
}
void fun(){
    test(0,0);
    for(int i=0;i<Row;i++){
        printf("%d", press[i][0]);
        for(int j=1;j<Col;j++){
            printf(" %d", press[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tstnum, tstcase = 0;
    scanf("%d",&tstnum);
    while(tstcase++ < tstnum){
        printf("PUZZLE #%d\n", tstcase);
        readIn();
        fun();
    }

    return 0;
}


#include<iostream>
using namespace std;
enum {
    ROW = 10,
    COL = 31,
};
unsigned mat[ROW][COL];
// assume that r <= c 
unsigned preset(int r, int c){
    if(r*c%3!=0) return 0;

}
void init(){
    int i,j;
    for(i=1; i<ROW; i++){
        for(j=i; j<COL; j++){
            mat[i][j] = preset(i, j);
        }
    }
}

int main(){
    init();
    int r, c;
    scanf("%d%d",&r,&c);
    while(r+c){
        if(r > c) swap(r,c);
        printf("%u\n", mat[r][c]);
        scanf("%d%d",&r,&c);
    }
    return 0;
}


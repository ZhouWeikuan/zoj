#include <iostream>
#include <cstdio>
#include <cstdlib>

enum {
    SIZ = 5,
    UP = 0,
    RT = 1,
    DN = 2,
    LT = 3,
    MD = 4,
};

struct Box{
    int val[MD];
    int cnt;
    bool matchUp(const Box&b) {
        return (val[UP] == b.val[DN]);
    }
    bool matchLeft(const Box&b) {
        return (val[LT] == b.val[RT]);
    }
    bool equal(const Box&b){
        return (val[0]==b.val[0]) && (val[1]==b.val[1]) 
            && (val[2]==b.val[2]) && (val[3]==b.val[3]);
    }
};

Box box[28];
int mat[SIZ][SIZ];
int  num, edge, size;

inline void reset(int p){
    int y = p % edge;
    int x = p / edge;
    mat[x][y] = -1;
}

bool search(int p){
    if (p>=size) return true;
    int y = p % edge;
    int x = p / edge;
    int &o = mat[x][y];
    while(o < num){
        ++o;
        if (box[o].cnt<=0) 
            continue;
        if (x && !box[o].matchUp(box[mat[x-1][y]]))
            continue;
        if (y && !box[o].matchLeft(box[mat[x][y-1]]))
            continue;
        box[o].cnt--;
        reset(p+1);
        if (search(p+1))
            return true;
        box[o].cnt++;
    }
    return false;
}

bool fun(){
    reset(0);
    return search(0);
}

int main(){
    int tstcase = 0,i;
    const char *ans[2] = {"Impossible", "Possible"};

    scanf("%d", &num);
    while(num){
        edge = num;
        size = num * num;
        num = 0;
        int j;
        for(i=0;i<size;i++){
            for (j=0; j<MD; j++){
                scanf("%d ", &box[num].val[j]);
            }
            box[num].cnt = 1;
            for (j=0; j<num; j++){
                if (box[num].equal(box[j])){
                    box[j].cnt ++;
                    break;
                }
            }
            num += (j==num);
        }
        if(tstcase ++){
            printf("\n");
        }
        printf("Game %d: ",tstcase);
        printf("%s\n", ans[fun()]);

        scanf("%d", &num);
    }

    return 0;
}

#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
int row, col;
bool mat[SIZ][SIZ];
int wall[SIZ];

void do_up(int cnt){
    int i;
    int x = row, top=0, m=0;
    for(i=0; i<col; i++){
        wall[i] = 1;
        while(x-wall[i]>=top && mat[x-wall[i]][i] == true){
            ++wall[i];
        }
        if(m < wall[i]){
            m = wall[i];
        }
    }
    while(x-m>=top && cnt--){
        --x;
        for(i=0; i<col; i++){
            if(wall[i] > 1){
                mat[x][i] = false;
                mat[x-wall[i]+1][i] = true;
            }
            while(x-wall[i]>=top && mat[x-wall[i]][i] == true){
                ++wall[i];
            }
            if(m < wall[i]){
                m = wall[i];
            }
        }
    }
}

void do_down(int cnt){
    int i;
    int x = 0, bot=row, m=0;
    for(i=0; i<col; i++){
        wall[i] = 0;
        while(x+wall[i]<bot && mat[x+wall[i]][i] == true){
            ++wall[i];
        }
        if(m < wall[i]){
            m = wall[i];
        }
    }
    while(x+m<bot && cnt--){
        ++x;
        for(i=0; i<col; i++){
            if(wall[i] > 0 ){
                mat[x-1][i] = false;
                mat[x+wall[i]-1][i] = true;
            }
            while(x+wall[i]<bot && mat[x+wall[i]][i] == true){
                ++wall[i];
            }
            if(m < wall[i]){
                m = wall[i];
            }
        }
    }
}

void do_left(int cnt){
    int i;
    int y = col, lef=0, m=0;
    for(i=0; i<row; i++){
        wall[i] = 1;
        while(y-wall[i]>=lef && mat[i][y-wall[i]] == true){
            ++wall[i];
        }
        if(m < wall[i]){
            m = wall[i];
        }
    }
    while(y-m>=lef && cnt--){
        --y;
        for(i=0; i<row; i++){
            if(wall[i] > 1 ){
                mat[i][y] = false;
                mat[i][y-wall[i]+1] = true;
            }
            while(y-wall[i]>=lef && mat[i][y-wall[i]] == true){
                ++wall[i];
            }
            if(m < wall[i]){
                m = wall[i];
            }
        }
    }
}

void do_right(int cnt){
    int i;
    int y = 0, rit=col, m=0;
    for(i=0; i<row; i++){
        wall[i] = 0;
        while(y+wall[i]<rit && mat[i][y+wall[i]] == true){
            ++wall[i];
        }
        if(m < wall[i]){
            m = wall[i];
        }
    }
    while(y+m<rit && cnt--){
        ++y;
        for(i=0; i<row; i++){
            if(wall[i] > 0 ){
                mat[i][y-1] = false;
                mat[i][y+wall[i]-1] = true;
            }
            while(y+wall[i]<rit && mat[i][y+wall[i]] == true){
                ++wall[i];
            }
            if(m < wall[i]){
                m = wall[i];
            }
        }
    }
}

void fun(){
    int pos;
    static char buf[20];
    scanf("%s", buf);
    while(strcmp(buf, "done")!=0){
        scanf("%d",&pos);
        switch(buf[0]){
        case 'u':
            do_up(pos);
            break;
        case 'd':
            do_down(pos);
            break;
        case 'l':
            do_left(pos);
            break;
        case 'r':
            do_right(pos);
            break;
        }
        scanf("%s", buf);
    }
    int i,j;
    for(i=0 ;i<row; i++){
        for(j=0; j<col; j++){
            if(mat[i][j]){
                printf(" (%d,%d)", i,j);
            }
        }
    }
    printf(".\n");
}
int readIn(){
    scanf("%d%d",&row,&col);
    if(row + col == 0) return 0;
    memset(mat, false, sizeof(mat));
    int pos, a, b;
    scanf("%d",&pos);
    while(pos--){
        scanf("%d%d",&a,&b);
        mat[a][b] = true;
    }
    return 1;
}
int main(){
    int tst = 1;
    while(readIn() > 0){
        printf("Data set %d ends with boxes at locations", tst++);
        fun();
    }
    return 0;
}


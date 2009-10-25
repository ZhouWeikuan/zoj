#include<iostream>
using namespace std;
enum {
    SIZ = 104,
    KING = 0,
    QUEEN = 1,
    ROOK = 2,
    BISHOP = 3,
    KNIGHT = 4,
};

struct Point {
    int r, c, t;
};

int inline abs(int a){
    return a<0?-a:a;
}

typedef bool (*attack_t)(const Point&, const Point &);
bool king_atk(const Point &a, const Point &b){
    unsigned r = abs(a.r - b.r);
    unsigned c = abs(a.c - b.c);
    return (r+c==1)||(r==c&&r==1);
}

bool queen_atk(const Point &a, const Point &b){
    unsigned r = abs(a.r - b.r);
    unsigned c = abs(a.c - b.c);
    return (r==0)||(c==0)||(r==c);
}

bool rook_atk(const Point &a, const Point &b){
    unsigned r = abs(a.r - b.r);
    unsigned c = abs(a.c - b.c);
    return (r==0)||(c==0);
}

bool bishop_atk(const Point &a, const Point &b){
    unsigned r = abs(a.r - b.r);
    unsigned c = abs(a.c - b.c);
    return (r==c);
}

bool knight_atk(const Point &a, const Point &b){
    unsigned r = abs(a.r - b.r);
    unsigned c = abs(a.c - b.c);
    return (r*c==2);
}

int Row, Col, num;
bool tab[16][16];
Point pnt[16];
attack_t atk[] = {
    king_atk,
    queen_atk,
    rook_atk,
    bishop_atk,
    knight_atk,
};
int best;
int top[16];

void dfs(int pos, int fro){
    if (best < pos) best = pos;
    for (int i=fro; i<num; ++i){
        bool s = true;
        for (int j=0; j<pos; ++j){
            if (tab[i][top[j]]){
                s=false;
                break;
            }
        }
        if (s){
            top[pos] = i;
            dfs(pos+1, i+1);
        }
    }
}

void fun(){
    memset(tab, false, sizeof(tab));
    for (int i=0; i<num; ++i){
        for (int j=i+1; j<num; ++j){
            if (atk[pnt[i].t](pnt[i], pnt[j]) || atk[pnt[j].t](pnt[j], pnt[i])){
                tab[i][j] = tab[j][i] = true;
            }
        }
    }
    best = 0;
    dfs(0, 0);
    best = num - best;
    printf("Minimum Number of Pieces to be removed: %d\n", best);
}

int readIn(){
    char buf[20];
    if (scanf("%s", buf) < 0)
        return 0;
    scanf("%d%d", &Col, &Row);
    num = 0;
    char ch;
    for (int r=0; r<Row; ++r){
        for (int c=0; c<Col; ++c){
            scanf(" %c", &ch);
            switch(ch){
            case 'E':
            break;
            case 'K':
                pnt[num].t = KING;
                break;
            case 'Q':
                pnt[num].t = QUEEN;
                break;
            case 'R':
                pnt[num].t = ROOK;
                break;
            case 'B':
                pnt[num].t = BISHOP;
                break;
            case 'N':
                pnt[num].t = KNIGHT;
                break;
            }
            if (ch!='E'){
                pnt[num].r = r;
                pnt[num].c = c;
                ++ num;
            }
        }
    }

    // END
    scanf("%s", buf);
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


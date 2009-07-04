#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
enum {
    SIZ = 104,
    AND = ')',
    OR  = '>',
};

struct Node {
    bool rev;
    int type;
    int v, l, r;
    Node *link;
};

char pic[SIZ][SIZ];
Node tree[SIZ];
int num, x, y, row;
Node * pnt[SIZ]; // 0 means not used, for A, B, C, D...
int move[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool valid(int r, int c){
    return (r>=0)&&(r<row) &&(c>=0&&c<100);
}

int calc(int p){
    if (tree[p].v != -1){
        return tree[p].v;
    }
    int a = calc(tree[p].l);
    int b = calc(tree[p].r);
    if (tree[p].type == AND){
        a = (a&&b);
    } else if (tree[p].type == OR){
        a = (a||b);
    }
    if (tree[p].rev)
        a = 1 - a;
    tree[p].v = a;    
    return tree[p].v;
}

bool match(char ch, int d){
    if (ch <= 32) return false;
    if (d%2==0 && ch=='-')
        return false;
    if (d%2==1 && ch=='|')
        return false;

    return true;
}

void build_tree(int r, int c){
    Node &o = tree[num];
    o.rev  = false; 
    o.v = o.l = o.r = -1; o.link = 0;
    o.type = 0;
    int d = 3;
    if (num == 0){
        for (d=0; d<4; ++d){
            if (!valid(r+move[d][0], c+move[d][1]))
                continue;
            char ch = pic[r+move[d][0]][c+move[d][1]];
            if (ch > 32) 
                break;
        }
    }
    ++num;

    do {
        r += move[d][0];
        c += move[d][1];
        switch(pic[r][c]){
        case ')':
            o.type = AND;
            break;
        case '>':
            o.type = OR;
            break;
        case 'o':
            o.rev = !o.rev;
            break;
        case '+':
            {
                int od = (d+3)%4;
                for (d=(d+1)%4; d!=od; d=(d+2)%4){
                    int nx = r + move[d][0];
                    int ny = c + move[d][1];
                    if (valid(nx,ny) && match(pic[nx][ny],d)){
                        r = nx, c = ny;
                        break;
                    }
                }
            }
        default:
            if (isalpha(pic[r][c])){
                o.type = pic[r][c];
            }
            break;
        }
    } while(o.type == 0);
    if (isalpha(o.type)){
        int p = o.type - 'A';
        o.link = pnt[p];
        pnt[p] = &o;
    } else {
        o.l = num;
        build_tree(r+move[0][0], c+move[0][1]-1);
        o.r = num;
        build_tree(r+move[2][0], c+move[2][1]-1);
    }
}

void fun(){
    int i;
    const char *ans[2] = { "0", "1" };
    num = 0;
    memset(pnt, 0, sizeof(pnt));
    build_tree(x, y);
    cin.getline(pic[0], SIZ);
    while(pic[0][0] != '*'){
        for (i=0; i<num; i++){
            tree[i].v = -1;
        }
        for (i=0; pic[0][i]; i++){
            int v;
            if (pnt[i] == 0) continue;
            v = (pic[0][i]=='1');
            for (Node *p = pnt[i]; p; p=p->link){
                p->v = v;
                if (p->rev){
                    p->v = 1 - p->v;
                }
            }
        }
        i = calc(0);
        printf("%s\n", ans[i]);
        cin.getline(pic[0], SIZ);
    }
}

int readIn(){
    row = 0; x = 0, y = 0;
    char *s;
    memset(pic, 0, sizeof(pic));
    cin.getline(pic[row], SIZ);
    while(cin && pic[row][0] != '*'){
        for (int i=0; pic[row][i]; ++i){
            if (pic[row][i] == '?'){
                x = row; y = i;
            }
        }
        ++row;
        cin.getline(pic[row], SIZ);
    }
    return row;
}

int main(){
    int tst = 0;
    while(readIn() > 0){
        if (tst++)
            printf("\n");
        fun();
    }

    return 0;
}


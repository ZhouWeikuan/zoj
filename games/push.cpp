#include<iostream>
#include<map>
#include<string>

using namespace std;
enum {
    SIZ = 200,
};

const char ans[] = "UDLR";
int mv[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
unsigned col, row, deep, sum;
unsigned mat[SIZ][SIZ];
char buf[SIZ*SIZ];

bool valid(unsigned r, unsigned c){
    return r<row&&c<col;
}

void splitPos(unsigned p, unsigned &r, unsigned &c){
    r = (p/col);
    c = (p%col);
}

bool dfs(unsigned r, unsigned c){
    if (deep >= sum){
        buf[deep] = 0;
        return true;
    }
    unsigned ar, ac, br, bc;
    int s = 0;
    for (int m=0; m<4; ++m){
        ar = r + mv[m][0];
        ac = c + mv[m][1];
        s = 0;
        while(valid(ar, ac)){
            br = ar + mv[m][0];
            bc = ac + mv[m][1];
            if (mat[ar][ac]){
                if (s==0) break;
                int v = mat[ar][ac] - 1;
                if (v && !valid(br,bc)) break;
                mat[ar][ac] = 0;
                if (v)
                    mat[br][bc] += v;
                buf[deep++] = ans[m];
                if (dfs(ar, ac)){
                    return true;
                }
                buf[--deep] = 0;
                if (v)
                    mat[br][bc] -= v;
                mat[ar][ac] = v + 1;
                break;
            }
            ++s;
            ar = br;
            ac = bc;
        }
    }
    return false;
}

void fun(){
    deep = 0;
    unsigned r, c;
    for (r=0; r<row; ++r){
        for (c=0; c<col; ++c){
            if (mat[r][c] == 0) continue;
            for (int m=0; m<4; ++m){
                unsigned ar = r-2*mv[m][0], ac=c-2*mv[m][1];
                if (!valid(ar, ac)) continue;
                unsigned br = r-mv[m][0], bc=c-mv[m][1];
                if (mat[ar][ac]!=0||mat[br][bc]!=0 ) continue;
                int v = mat[r][c] - 1;
                unsigned cr = r+mv[m][0], cc=c+mv[m][1];
                if (v > 0 && !valid(cr, cc)) continue;
                mat[r][c] = 0;
                if (v)
                    mat[cr][cc] += v;
                buf[deep++] = ans[m];
                if (dfs(r, c)){
                    printf("path=%u,%u,%s\n", ac, ar, buf);
                    return;
                }
                if (v)
                    mat[cr][cc] -= v;
                mat[r][c] = v + 1;
                buf[--deep] = 0;
            }
        }
    }
}

void init(){
    unsigned i, p = 0;
    unsigned r,c;
    sum = 0;
    for (r=0; r<row; ++r){
        cin>>buf;
    for (c=0; c<col; ++c){
        if (buf[c] != '.'){
            mat[r][c] = buf[c] - 'a' + 1;
            sum += mat[r][c];
        }
    }
    }
}

int main(){
    cin>>col>>row;
    init();
    fun();

    return 0;
}


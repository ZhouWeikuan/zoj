#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 280,
};
int code(char c){
    static const char *s="BHJNY";
    int i;
    for(i=0; s[i]!=c; i++)
        ;
    return i;
}

struct Line {
    vector<int> pos[5];
    void parse(char *s);
    int calc(Line &l);
};
void Line::parse(char *s)
{
    int i;
    for(i=0; i<5; i++) pos[i].clear();
    for(i=0;s[i]; i++){
        pos[code(s[i])].push_back(i);
    }
}

int Line::calc(Line &l)
{
    int val = 0;
    vector<int>::iterator a;
    vector<int>::iterator b;
    for(int i=0; i<5; i++){
        int t = 0;
        b = l.pos[i].begin();
        a = pos[i].begin();
        while(a!=pos[i].end() && b!=l.pos[i].end()){
            if( *a < *b){
                ++a;
            }else if(*a >* b){
                ++b;
            }else {
                ++a, ++b;
                ++t;
            }
        }
        val += (t-1)*t/2;
    }
    return val;
}

int M, N;
char mat[SIZ];
Line row[SIZ];

void fun(){
    int val = 0;
    int i, j;
    for(i=0; i<M; i++){
        for(j=i+1; j<M; j++){
            val += row[i].calc(row[j]);
        }
    }
    printf("%d\n", val);
}

int readIn(){
    scanf("%d%d ", &M, &N);
    for(int i=0; i<M; i++){
        scanf("%s ", mat);
        row[i].parse(mat);
    }
    return 1;
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}


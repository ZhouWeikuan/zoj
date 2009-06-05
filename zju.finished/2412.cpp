#include<iostream>
using namespace std;
enum {
    SIZ = 52,
    UP = 0x001,
    DN = 0x002,
    LF = 0x004,
    RT = 0x008,
};
int type[11] = {
    UP|LF, /*A*/
    UP|RT, /*B*/
    LF|DN, /*C*/
    DN|RT, /*D*/
    UP|DN, /*E*/
    LF|RT, /*F*/
    UP|LF|RT, /*G*/
    LF|UP|DN, /*H*/
    LF|DN|RT, /*I*/
    UP|DN|RT, /*J*/
    UP|DN|LF|RT /*K*/
};
int mat[SIZ][SIZ];
int M, N;
int par[SIZ *SIZ];

int getPar(int a){
    int p = par[a];
    while(p != par[p]){
        p = par[p];
    }
    return par[a] = p;
}
int in_same(int a, int b){
    a = getPar(a); b = getPar(b);
    return (a == b);
}
void connect(int a, int b){
    a = getPar(a); b = getPar(b);
    if(a < b){
        par[b] = a;
    } else if(a > b){
        par[a] = b;
    } 
}

int readIn(){
    cin>>M>>N;
    if(M < 0)
        return 0;
    int p;
    char ch;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            p = i * N + j;
            cin>>ch;
            mat[i][j] = ch -'A';
            par[p] = p;
        }
    }
    return 1;
}

int fun(){
    int a,b;
    int i,j;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            a = i * N + j; // curr

            b = (i-1)*N + j; //top;
            if(i>0 && (type[mat[i-1][j]]&DN) && (type[mat[i][j]] &UP) ){
                connect(a,b);
            }

            b = i * N + j-1; // left;
            if(j>0&& (type[mat[i][j-1]]&RT) && (type[mat[i][j]] &LF) ){
                connect(a,b);
            }
        }
    }
    a = 0; b = M * N;
    for(i=0;i<b;i++){
        if(par[i] == i)
            a++;
    }
    return a;
}

int main(){
    
    while(readIn()){
        cout<<fun()<<endl;
    }

	return 0;
}

#include <iostream>
#include <string.h>
// To create a linear time suffix array.
//  incomplete for sorting S substring.
using namespace std;
enum {
    SIZ = 200,
    CMP_S = 0,
    CMP_L = 1,
    ALPHA = 128,
};
class SuffixArray {
  public:
    SuffixArray(){};
    void create(char *s);
    void output();
    
  private:    
    void computeType();
    void mySwap(int, int);
    void init();
    
    int R[SIZ];     // reverse, show R[pos] in A
    int A[SIZ];     // index, show A[i] == pos;
    int B[SIZ];     // collect all characters whose type is CMP_S
    int S[SIZ], E[SIZ];
    int type[SIZ]; 
    int num, p;
    char *str;
};

//char str[SIZ]={"MISSISSIPPI"};
char str[SIZ]={"wanglaowu"};

void SuffixArray::computeType(){
    int i, j;
    for(i=0; str[i]; ){
        if(str[i] != str[i+1]){
            type[i] = (str[i] > str[i+1]);
            i++;
        } else {
            for(j=i+1; str[j]==str[i]; j++) ;
            type[i] = (str[i] > str[j]);
            for(i++; i<j; i++){
                type[i] = type[i-1];
            }            
        }
    }
    type[i] = CMP_L;
}

void SuffixArray::mySwap(int i, int j){
    if(i==j) return;
    int t;
    t = A[i]; A[i] = A[j]; A[j] = t;
    R[A[i]] = i;
    R[A[j]] = j;
}

void SuffixArray::init(){
    int i, j;
    memset(type, -1, sizeof(type));    // type为同类链接
    memset(B, -1, sizeof(B));    // B为位置链接
    num = (int)strlen(str) + 1;
    // link the same character
    for(i=num-1; i>=0; i--){
        B[i] = type[str[i]];
        type[str[i]] = i;
    }
    // store same characters in A continuously and their inverse.
    p = 0;
    for(i=0; i<ALPHA; i++){
        S[i] = E[i] = -1;
        if(type[i] == -1) continue;
        S[i] = p;
        for(j=type[i]; j!=-1; j=B[j]){
            A[p] = j;
            R[j] = p;
            p++;
        }
        E[i] = p-1;
    }
    computeType();
    
    // collect pos that is CMP_S
    p = 0;
    for(i=0; i<num; i++){
        if(type[A[i]] == CMP_S){
            B[p++] = A[i];
        }
    }
}

void SuffixArray::create(char *s){
    str = s;    
    init();    
    int i,t;
    // process character whose type is CMP_S
    for(p--; p>=0; p--){
        t = B[p];
        mySwap(R[t], E[str[t]]);
        E[str[t]] --;
    }
    // process all characters
    for(i=0; i<num; i++){
        t = A[i] - 1;
        if(t < 0 || type[t] == CMP_S){
            continue;
        }
        mySwap(R[t], S[str[t]]);
        S[str[t]]++;
    }    
}

void SuffixArray::output(){
    for(int i=0; i<num; i++){
        printf("%s\n", &str[A[i]]);
    }
}

int main()
{
    SuffixArray sa;
    sa.create(str);
    sa.output();
    
    return 0;
} 


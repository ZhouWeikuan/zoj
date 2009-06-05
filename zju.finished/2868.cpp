#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
// Bidirectional DP!
enum {
    SIZ = 36, // 
    LIM = 132000,
};

int num;
int d[SIZ];
int sum;
int c[2][LIM];


int calc(int *c, int s, int e, int lim){
    int pos, i, j, np, t;
    c[0] = 0;
    pos = 1;
    for(i=s; i<e; i++){        
        np = pos;
        for(j=0; j<pos; j++){            
            t = c[j] + d[i];
            if(t <= lim){
                c[np++] = t;
            }
        }
        pos = np;
    }
    sort(c, c+pos);
    np = 1;
    for(i=1; i<pos; i++){
        if(c[i] == c[i-1]){
            continue;
        }
        c[np++] = c[i];
    }
    pos = np;
    return pos;
}
void fun(){
    int part, i, s;
    int m = sum;
    int alen, blen;
    part = sum / 2;
    
    alen = calc(c[0], 0, num/2, part);
    blen = calc(c[1], num/2, num, part);    
    blen--;
    
    for(i=0; i<alen; i++){
        s = c[0][i] + c[1][blen];
        while( s > part){
            blen--;
            s = c[0][i] + c[1][blen];
        }        
        s = sum - 2 * s;
        if(m > s){
            m = s;
            if(m <= 1)
                break;
        }
    }
    
    printf("%d\n", m);
}

int readIn(){
    scanf("%d", &num);
    sum = 0;
    for(int i=0; i<num; i++){
        scanf("%d", &d[i]);
        sum += d[i];
    }    
    return num;
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}


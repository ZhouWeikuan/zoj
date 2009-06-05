#include<iostream>
using namespace std;
enum {
    SIZ = 5004,
    Lim = 3,
};
char ge[SIZ];
int pos;

int ndiff(char *a, char *b, int n){
    for(int i=0;i<n;i++){
        if(a[i] != b[i])
            return 1;
    }
    return 0;
}

int check(int cur){
    cur ++;
    int t = 1;
    while(cur - 2 * t >= 0){
        if(ndiff(&ge[cur-t], &ge[cur-2*t], t) == 0)
            return 0;
        t ++;
    }
    return 1;
}

void init(){
    int cur = 0;
    ge[cur] = 0;
    while(cur < SIZ){
        if( check(cur) ){
            cur ++;
            ge[cur] = 0;
        } else {
            ge[cur]++;
        }
        while(ge[cur] >= Lim){
            cur--;
            ge[cur]++;
        }
    }
    const char alp[4] = "NOP";
    for(cur=0;cur<SIZ;cur++){
        ge[cur] = alp[ge[cur]];
    }
    ge[cur] = 0;
}

int main(){
    init();
    char t;
    
    cin>>pos;
    while(pos){
        t = ge[pos];
        ge[pos] = 0;
        cout<<ge<<endl;
        ge[pos] = t;

        cin>>pos;
    }

	return 0;
}

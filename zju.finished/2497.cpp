#include<iostream>
using namespace std;
enum {
    SIZ = 10008,
};
int oppo[6] = {5, 3, 4, 1, 2, 0};
struct Die{
    int face[6]; //0-5  1-3 2-4
    int val[6];
    void read(){
        for(int i=0; i<6; i++){
            scanf("%d", &face[i]);
            face[i]--;
            val[face[i]] = i;
        }
    }
    int get_max(int f){ // f as bottom
        int t = -1;
        if(f != 0 && f !=5){
            t = max(t, max(face[0], face[5]));
        }
        if(f!=1 && f!=3){
            t = max(t, max(face[1], face[3]));
        }
        if(f!=2 && f!=4){
            t = max(t, max(face[2], face[4]));
        }
        return t;
    }
};
int num;
Die d[SIZ];

int fun(){
    int b,f,i;
    int s, res=0;
    for(b=0; b<6; b++){
        s = 0; 
        f = b;
        for(i=0; i<num; i++){
            f = d[i].val[f];
            s += d[i].get_max(f);
            f = oppo[f];
            f = d[i].face[f];
        }
        if(res < s) res = s;
    }
    res += num;
    return res;
}
void readIn(){
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        d[i].read();
    }
}
int main(){
    int tst;
    scanf("%d",&tst);
    while(tst--){
        readIn();
        printf("%d\n", fun());
    }
    return 0;
}

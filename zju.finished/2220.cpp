#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 44,
    Num = 52,
};
struct Point {
    int x,y;
};
Point tree[Num];
int pos;
int size;

void readIn(){
    cin>>size>>pos;
    for(int i=0;i<pos;i++){
        cin>>tree[i].x>>tree[i].y;
    }
}

int test(int x, int y){
    int i;
    double t, val = -1;
    for(i=0;i<pos;i++){
        if(tree[i].x == x && tree[i].y == y)
            return 0;
        t = (x-tree[i].x)*(x-tree[i].x)+(y-tree[i].y)*(y-tree[i].y);
        t = sqrt(t);
        if(t >= val){
            val = t;
        }
    }
    t = val;
    if(x<t || y<t || size-x<t || size-y<t)
        return 0;
    return 1;
}

void fun(){
    int i,j;
    for(i=1;i<size;i++){
        for(j=1;j<size;j++){
            if(test(i,j)){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<"poodle"<<endl;
}

int main(){
    int tstcase;
    cin>>tstcase;
    while(tstcase --){
        readIn();
        fun();
    }

	return 0;
}

#include<iostream>

using namespace std;
enum {
    Round = 40,
};
int cur;
int x,y,z;

int counterclock(int a, int b){
    if(a <= b){
        return b-a;
    }
    return (b + Round) - a;
}
int clockwise(int a, int b){
    if(a >= b){
        return a-b;
    }
    return (a + Round) -b;
}

int fun(){
    int deg = 0;
    deg += 2 * Round;
    deg += clockwise(cur, x);
    cur = x; 
    deg += Round;
    deg += counterclock(cur, y);
    cur = y;

    deg += clockwise(cur, z);
    cur = z;

    deg *= 9;
    return deg;
}

int main(){

    cin>>cur>>x>>y>>z;
    while(cur + x + y + z){
        cout<<fun()<<endl;
        cin>>cur>>x>>y>>z;
    }

	return 0;
}

#include<iostream>

using namespace std;
enum {
    SIZ = 100008,
};
unsigned len[SIZ];
unsigned pos, off, num;

void init(){
    int t,i;
    len[0] = 0;
    for(i=1; i<10;i++){
        len[i] = len[i-1] + 1;
    }
    for(i=10; i<100;i++){
        len[i] = len[i-1] + 2;
    }
    for(i=100; i<1000;i++){
        len[i] = len[i-1] + 3;
    }
    for(i=1000; i<10000;i++){
        len[i] = len[i-1] + 4;
    }
    for(i=10000; i<100000;i++){
        len[i] = len[i-1] + 5;
    }
    for(i=100000; i<SIZ; i++){
        len[i] = len[i-1] + 6;
    }
}

void count_dig(){
    int low =0, high = num;
    int mid = (low + high) /2;
    while(low < high){
        if(len[mid] == pos ){
            break;
        } else if(len[mid] < pos){
            low = mid + 1;
        } else {
            high = mid;
        }
        mid = (low + high) / 2;
    }
    off = pos - len[mid - 1];
    pos = mid;
}

extern int del_even(int t);

int del_odd(int t){
    if(t <= 1)
        return 1;
    return 2*del_even(t/2) ;
}

int del_even(int t){
    if(t<=2)
        return 1;
    return 2*del_odd((t+1)/2)-1;
}

char fun(){
    static char buf[20];
    pos = del_even(len[num]);
    count_dig();
    sprintf(buf, "%d", pos);
    return buf[off - 1];
}

int main(){
    init();
    while(scanf("%d", &num) > 0){
        printf("%c\n", fun());
    }

	return 0;
}

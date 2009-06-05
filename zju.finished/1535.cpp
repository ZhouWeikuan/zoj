#include<iostream>
// 计算左右的值，若左小于右，则从右的最右位开始，加此位到0,递增，
//                      直到右小于左或溢出
//               若右小于左，则将差值从右的最右位开始加，直到差值为0
//               TLE
using namespace std;
enum {
    Siz = 28,
};
char buf[Siz];
int old[Siz];
int now[Siz];
int N;

void fun(){
    int i,j;
    int left,right;
    left = right = 0;
    for(i=0;i<N;i++){
        left += now[i];
        right += now[N+i];
    }
    i = 2 * N -1;
    while(left < right){
        right -= now[i];
        now[i] = 0;
        i --;
        while(i >= N){
            if(now[i]>=9){
                right -= now[i];
                now[i] = 0;
                i--;
            } else {
                right ++;
                now[i] ++;
                break;
            }
        }
        if(i < N)
            break;
    }
    if(i < N){ // overflow
        i = N-1;
        while(i>=0 && now[i]>=9){
            left -= now[i];
            now[i] = 0;
            i--;
        }
        now[i] ++;
        left ++;
    }
    int diff = left - right;
    i = 2 * N - 1;
    while(diff){
        j = 9 - now[i];
        if(diff >= j){
            diff -= j;
            now[i] = 9;
        } else {
            now[i] += diff;
            diff = 0;
        }
        i--;
    }

    // compute the increase
    int carry = 0;
    for(i= 2*N-1;i>=0;i--){
        if(carry + now[i] < old[i]){
            now[i] = now[i] + carry + 10 - old[i];
            carry = -1;
        } else {
            now[i] = now[i] + carry - old[i];
            carry = 0;
        }
    }
}

int main(){
    int i;
    while(cin>>buf){
        for(i=0;buf[i];i++){
            now[i] = old[i] = buf[i] - '0';
        }
        N = i/2;
        fun();
        for(i=0;now[i]==0 && i < 2*N;i++)
            ;
        if(i == 2*N){
            cout<<0<<endl;
        } else{
            for(;i<2*N;i++){
                cout<<now[i];
            }
            cout<<endl;
        }
    }

	return 0;
}

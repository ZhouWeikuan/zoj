#include<iostream>

using namespace std;
char buf[20];

void fun(){
    int len = strlen(buf);
    for(len --; len > 1;len--){
        if(buf[len] > '9'){
            buf[len-1]++;
            buf[len] -= 10;
        }
        if(buf[len] >= '5'){
            buf[len-1]++;
        }
        buf[len] = '0';
    }
    if(buf[1] > '9'){
        buf[0] ++;
        buf[1] -= 10;
        cout<<buf<<endl;
    } else {
        cout<<&buf[1]<<endl;
    }
}

int main(){
    int num;

    cin>>num;
    while(num --){
        buf[0] = '0';
        cin>> &buf[1];
        fun();
    }

	return 0;
}

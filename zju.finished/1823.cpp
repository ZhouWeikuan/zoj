#include<iostream>

using namespace std;
/*
	 看了衡阳八中的讨论，数据很弱不应该建表，直接循环就行了.
*/
long long num;
long long cur;

int main(){
    
    cin>>num;
    while(num > 0){
        cur = 2;
        while(cur * cur <= num){
            while(num%cur==0){
                cout<<cur<<endl;
                num /= cur;
            }
            cur++;
        }
        if(num > 1)
            cout<<num<<endl;
        cout<<endl;

        cin>>num;
    }

	return 0;
}

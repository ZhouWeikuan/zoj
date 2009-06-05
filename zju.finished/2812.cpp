#include<iostream>

using namespace std;
char buf[280];

void fun(){
    int ans = 0;
    int t,i;
    for(i=0; buf[i]; i++){
        t = buf[i] -'A'+1;
        if(t >=1 && t<= 26){
            t *= (i+1);
            ans += t;
        }
    }
    cout<<ans<<endl;
}

int main(){
    
    while(cin.getline(buf,280)){
        if(buf[0] == '#')
            break;
        fun();
    }

	return 0;
}

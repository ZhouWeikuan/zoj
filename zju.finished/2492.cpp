#include<iostream>

using namespace std;
enum {
    SIZ = 280,
};
char buf[SIZ];

char *parse(char *s, int &ret){
    int flag = 1;
    if(*s=='+'){
        flag = 1; s++;
    } else if(*s=='-'){
        flag = -1; s++;
    }
    if(*s == 'x'){
        ret = flag;
        return s;
    }
    ret = 0;
    while(isdigit(*s)){
        ret *= 10;
        ret += *s-'0';
        s++;
    }
    ret *= flag;
    return s;
}

void fun(){
    int a = 0,b = 0;
    int t;
    char *s = buf;
    while( *s!='='){
        s = parse(s, t);
        if(*s=='x'){
            a += t;
            s++;
        } else {
            b += t;
        }
    }
    s++;
    while(*s){
        s = parse(s, t);
        if(*s == 'x'){
            a -= t;
            s++;
        } else {
            b -= t;
        }
    }

    if( a== 0){
        if(b == 0){
            cout<<"IDENTITY"<<endl;
        } else {
            cout<<"IMPOSSIBLE"<<endl;
        }
    } else {
        b = -b;
        if( a * b < 0){
            a = abs(a);
            b = abs(b);
            t = b / a;
            if(b % a)
                t ++;
            t = -t;
        } else {
            t = b / a;
        }
        cout<<t<<endl;
    }
}

int main(){
    int tstcase;
    
    cin.getline(buf, SIZ);
    tstcase = atoi(buf);
    while(tstcase--){
        cin.getline(buf, SIZ);
        fun();
    }

	return 0;
}

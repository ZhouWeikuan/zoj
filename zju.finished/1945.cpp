#include<iostream>
#include<iomanip>
using namespace std;
enum {
    SIZ = 80,
};
char buf[SIZ];
double P,U,I;

double calc(char *s){
    double t, u;
    char *e = s;
    while( isdigit(*e) || *e=='.'){
        e ++;
    }
    switch(*e){
    case 'm':
        u = 0.001;
        break;
    case 'k':
        u = 1000.0;
        break;
    case 'M':
        u = 1000000.0;
        break;
    default:
        u = 1.0;
        break;
    }
    *e = 0;
    t = strtod(s, 0);
    t *= u;
    return t;
}

void parse(char *s){
    while(*s != '='){
        s++;
    }
    double t = calc(s+1);
    switch( *(s-1)){
    case 'P':
        P = t;
        break;
    case 'U':
        U = t;
        break;
    case 'I':
    default:
        I = t;
        break;
    }
}

void fun(){
    P = U = I = -1.0;
    int t = 0;
    while(t < 2){
        cin>>buf;
        if(buf[1] =='='){
            parse(buf);
            t ++;
        }
    }
    if(P < 0){
        P = U * I;
        cout<<"P="<<setiosflags(ios::fixed)<<setprecision(2)
            <<P<<"W"<<endl;
    } else if( U < 0){
        U = P / I;
        cout<<"U="<<setiosflags(ios::fixed)<<setprecision(2)
            <<U<<"V"<<endl;
    } else {
        I = P / U;
        cout<<"I="<<setiosflags(ios::fixed)<<setprecision(2)
            <<I<<"A"<<endl;
    }

}

int main(){
    int tstcase;
    cin>>tstcase;
    for(int i=1;i<=tstcase;i++){
        cout<<"Problem #"<<i<<"\n";
        fun();
        cout<<endl;
    }

	return 0;
}

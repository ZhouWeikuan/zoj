#include<iostream>
#include<iomanip>

using namespace std;
int su,sd,cu,cd, cnt;
int ud;
enum {
    UP = 0,
    DN = 1,
    UN = 2,
};

int readIn(){
    ud = su = sd = cu = cd = cnt = 0;
    unsigned a,b;
    int direct;
    cin>>a;
    if(a==0)
        return 0;
    cin>>b;
    if(b==0)
        return 1;
    if(b > a){
        cu++; su++;
        direct = UP;
    } else if(b < a) {
        cd++; sd++;
        direct = DN;
    } else {
        ud ++;
        direct = UN;
    }
    a = b;
    cnt = 1;
    cin>>b;
    while(b > 0){
        if(b > a){
            if(direct != UP){
                cu++;
                direct = UP;
            }
            su++;
            su += ud;
            ud = 0;
        } else if(b < a) {
            if(direct != DN){
                cd++;
                direct = DN;
            }
            sd++;
            sd += ud;
            ud = 0;
        } else {
            if(direct == UN){
                ud++;
            } else {
                if(direct == UP){
                    su ++;
                } else {
                    sd ++;
                }
            }
        }
        cnt++;
        a = b;

        cin>>b;
    }

    return 1;
}

void fun(){
    cout<<setiosflags(ios::fixed)<<setprecision(6);
    cout<<"Nr values = "<<(cnt + 1)<<":  ";
    if(cu){
        cout<<double(su)/cu;
    }else {
        cout<<0.0;
    }
    cout<<" ";
    if(cd){
        cout<<double(sd)/cd;
    } else {
        cout<<0.0;
    }
    cout<<endl;
}

int main(){
    
    while(readIn()){
        fun();
    }

	return 0;
}

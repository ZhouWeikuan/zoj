#include<iostream>
#include<string>
#include<map>
 
using namespace std;
map<string, int> tab;

void init(){
    tab["UTC"] = 0;     tab["GMT"] = 0;     tab["BST"] = 10;
    tab["IST"] = 10;     tab["WET"] = 0;     tab["WEST"] = 10;
    tab["CET"] = 10;     tab["CEST"] = 20;     tab["EET"] = 20;
    tab["EEST"] = 30;     tab["MSK"] = 30;     tab["MSD"] = 40;
    tab["AST"] = -40;     tab["ADT"] = -30;     tab["NST"] = -35;
    tab["NDT"] = -25;     tab["EST"] = -50;     tab["EDT"] = -40;
    tab["CST"] = -60;     tab["CDT"] = -50;     tab["MST"] = -70;
    tab["MDT"] = -60;     tab["PST"] = -80;     tab["PDT"] = -70;
    tab["HST"] = -100;     tab["AKST"] = -90;     tab["AKDT"] = -80;
    tab["AEST"] = 100;     tab["AEDT"] = 110;     tab["ACST"] = 95;
    tab["ACDT"] = 105;     tab["AWST"] = 80;    
}

void scantime(string &s, int &h, int &m){
    int i;
    h = m = 0;
    for(i=0;s[i]!=':';i++){
        h *= 10;
        h += s[i] -'0';
    }
    i ++;
    for(; s[i]; i++){
        m *= 10;
        m += s[i] - '0';
    }
}

void fun(){
    int h,m;
    string input,from,to;
    cin>>input;
    if(input == "midnight"){
        h = 0; m = 0;
    }else if(input == "noon"){
        h = 12; m = 0;
    }else {
        scantime(input,h,m);
        cin>>input;
        if(input[0]=='p'){
            if(h < 12){
                h += 12;
            }
        } else {
            if(h == 12){
                h = 0;
            }
        }
    }

    cin>>from>>to;
    int a,b;
    // convert "from" to "UTC"
    a = tab[from];
    b = a %10; a/= 10;
    h -= a;
    if(a < 0){ //add
        if(b){
            m += 30;
        }
        if(m >= 60){
            m -= 60; h++;
        }
    } else if(a > 0){ //sub
        if(b ){
            m -= 30;
        }
        if(m < 0){
            m += 60; h --;
        }
    }
    if(h < 0){
        h += 24;
    } else if(h >= 24){
        h -= 24;
    }
    // convert "UTC" to "to"
    a = tab[to];
    b = a %10; a/=10;
    h += a;
    if(a > 0){ //add
        if(b){
            m += 30;
        }
        if(m >= 60){
            m -= 60; h++;
        }
    } else if(a < 0){ //sub
        if(b ){
            m -= 30;
        }
        if(m < 0){
            m += 60; h --;
        }
    }
    if(h < 0){
        h += 24;
    }else if(h >= 24){
        h -= 24;
    }
    if(m==0 && (h ==0|| h==12 )){
        if(h ==0){
            cout<<"midnight"<<endl;
        }else {
            cout<<"noon"<<endl;
        }
        return;
    }
    if(h < 12){
        if(h ==0){
            h += 12;
        }
        cout<<h<<":";
        if(m < 10){
            cout<<0<<m;
        } else {
            cout<<m;
        }
        cout<<" a.m."<<endl;
        return;
    }
    if(h > 12)
        h -= 12;
    cout<<h<<":";
    if(m < 10){
        cout<<0<<m;
    } else {
        cout<<m;
    }
    cout<<" p.m."<<endl;
}

int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        fun();
    }
	return 0;
}

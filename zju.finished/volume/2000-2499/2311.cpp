#include<iostream>
#include<string>
#include<sstream>
#include<map>

using namespace std;
enum {
    Size = 1024,
};

map<string, int> tab;
char input[Size];

void init(){
     tab["zero"] = 0;      tab["one"] = 1;     tab["two"] = 2;
     tab["three"] = 3;     tab["four"] = 4;     tab["five"] = 5;
     tab["six"] = 6;     tab["seven"] = 7;     tab["eight"]= 8;
     tab["nine"] = 9;     tab["ten"] = 10;     tab["eleven"] = 11;
     tab["twelve"] = 12;     tab["thirteen"] = 13;     tab["fourteen"] = 14;
     tab["fifteen"] = 15;     tab["sixteen"]= 16;
     tab["seventeen"] = 17;      tab["eighteen"] = 18;     tab["nineteen"] = 19;
     tab["twenty"] = 20;     tab["thirty"] = 30;     tab["forty"] = 40;
     tab["fifty"] = 50;     tab["sixty"] = 60;     tab["seventy"] = 70;
     tab["eighty"] = 80;     tab["ninety"] = 90;     tab["hundred"] = 100;
}

void parse(){
    int cur,pre;
    int pos=1,ret=0;
    int t=0;
    int flag = 1;
    cur = pre = 0;
    while(flag){
        if(input[cur] ==' ' || input[cur] == 0){
            if(input[cur]==0){
                flag = 0;
            }
            input[cur] = 0;
            string s(&input[pre]);
            if(s == "negative"){
                pos = -1;
            }else if(s == "million"){
                t *= 1000000;
                ret += t;
                t = 0;
            }else if(s == "thousand"){
                t *= 1000;
                ret += t;
                t = 0;
            } else {
                if(s == "hundred"){
                    t *= 100;
                } else {
                    t += tab[s];
                }
            }
            pre = cur+1;
        }
        cur ++;
    }
    ret += t;
    ret *= pos;
    cout<<ret<<endl;
}

int main(){
    init();

    while(cin.getline(input,Size)){
        if(input[0] ==0)
            break;
        parse();
    }
	return 0;
}

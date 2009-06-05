#include<iostream>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 13,
};
int con[SIZ], len[SIZ], pos;
int num, mult;
const char * str[SIZ] = {
    "Ar","Ta","Ge","Ca","Le","Vi",
    "Li","Sc","Sa","Ca","Aq","Pi"
};
map<string, int> tab;

void init(){
    tab["January"] = 1;    tab["February"] = 2;
    tab["March"] = 3;      tab["April"] = 4;
    tab["May"] = 5;        tab["June"] = 6;
    tab["July"] = 7;       tab["August"] = 8;
    tab["September"] = 9;  tab["October"] = 10;
    tab["November"] = 11;  tab["December"] = 12;
}
int Mon(const string&s){
    map<string, int>::iterator it = tab.find(s);
    if(it != tab.end()){
        return it->second;
    }
    char *p=0; *p = 12;
    return 0;
}
int getCon(const string&s, int day){
    const int arr[] = {
        22, 21, 20, 21, 22, 23,
        23, 23, 23, 23, 23, 23
    };
    int m = Mon(s) - 1;
    int ret = 9;
    if(day >= arr[m]){
        ret++;
    }
    ret = (ret + m)%12;
    return ret;
}
int gcd(int a, int b){
    int t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
void fun(){
    string s; int d, c, i;
    memset(con, 0, sizeof(con));
    for(i=0; i<num; i++){
        cin>>s>>d;
        c = getCon(s, d);
        con[c]++;
    }
    mult = 0;
    for(i=0; i<12; i++){
        if(con[i] == 0) continue;
        if(mult ==0) 
            mult = con[i];
        else if(mult < con[i]){
            mult = gcd(con[i], mult);
        } else { // mult > con[i]
            mult = gcd(mult, con[i]);
        }
    }
    pos = -1;
    for(i=0; i<12;i++){
        con[i] /= mult;
        if(con[i] == 0){
            len[i] = -1;
        } else {
            len[i] = con[i] + 1;
        }
        if(pos < len[i]){
            pos = len[i];
        }
    }
}
inline void makeup(int a, int b){
    while(a < b){
        printf(" ");
        a++;
    }
}
void output(){
    int i, last, cur;
    while(pos > 0){
        last = cur = 0;
        for(i=0; i<11; i++){
            if(pos==len[i]){
                makeup(last, cur);
                printf(" %2d", con[i]*mult);
                last = cur + 3;
            }else if(pos < len[i]){
                makeup(last, cur);
                printf(" XX");
                last = cur + 3;
            }
            cur += 4;
        }
        if(pos==len[i]){
            makeup(last, cur);
            printf(" %2d", con[i]*mult);
        }else if(pos<len[i]){
            makeup(last, cur);
            printf(" XX");
        }
        printf("\n");
        pos --;
    }
    for(i=0; i<48; i++){
        printf("-");
    }
    printf("\n");
    for(i=0; i<11; i++){
        printf(" %s ", str[i]);
    }
    printf(" %s\n\n", str[i]);
}
int main(){
    init();

    cin>>num;
    while(num){
        fun();
        output();
        cin>>num;
    }

    return 0;
}


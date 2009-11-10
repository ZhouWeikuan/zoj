#include<iostream>
#include<string>
#include<set>

/*
	从衡阳八中获得思想，使用枚举法先建表再找。
*/
using namespace std;
char digit[10];
char base[10] = {'1','2','3','4','5','6','7','8','9'};
struct pred{
    bool operator()(const string&a, const string&b){
        if(a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    }
};
set<string, pred> tab;
set<string, pred>::iterator iter;
int num;

static int flag[10];
int runNumber(string &s){
    int len = s.size();
    int t = len;
    int cur = 0;
    memset(flag,0,sizeof(flag));
    while(t > 0){
        if(flag[cur])
             break;
        flag[cur] = 1;
        cur += s[cur] - '0';
        cur %= len;
        t --;
    }
    
    return (t == 0 && cur == 0);
}

void build(int cur, int n){
    if(n == num){
        string s(digit, digit+num);
        do {
            if(runNumber(s))
                tab.insert(s);
        }while(next_permutation(s.begin(), s.end()));
        return;
    }
    if(cur + num > 9 + n)
        return;
    while(cur + num <= 9 + n){
        digit[n] = base[cur];
        build(cur+1, n+1);
        cur ++;
    }
}

void init(){
    int i;
    for(i=0;i<9;i++){
        digit[0] = base[i];
        string s(digit,digit+1);
        tab.insert(s);
    }
    for(i= 2;i<=9;i++){
        num = i;
        build(0,0);
    }
}

int main(){
    int tstcase = 0;
    string s;
    init();

    cin>>s;
    while(s[0] != '0'){
       cout<<"Case "<<++tstcase<<": ";
       iter = tab.upper_bound(s); 
       cout<<*iter<<endl;

       cin>>s;
    }

	return 0;
}

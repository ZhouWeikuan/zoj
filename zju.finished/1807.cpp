#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cctype>
using namespace std;

string str;
int tot = 0, bld = 0;
vector<string> val;
vector<string> inv;
map<string, int> tab;
map<string, int>::iterator mit;

struct cmp5{
    bool operator()(const string&l, const string&r){
        return l < r;
    }
};
struct cmp3{
    bool operator()(const string&l, const string&r){
        return string(l,0,3) < string(r,0,3);
    }
};
struct cmp{
    bool operator()(const string&l, const string&r){
        return l < r;
    }
};

int countPacket(int v){
    if(v < 10) return 0;
    int ret = v / 15;
    ret += (v%15!=0);
    return ret;
}

bool bundle5(){
    int ret = 0, i;
    tab.clear();
    for(vector<string>::iterator it=val.begin();
            it!=val.end(); ++it){
        ++tab[*it];
    }
    stable_sort(val.begin(), val.end(), cmp5());
    i = 0;
    for(vector<string>::iterator it=val.begin();
            it!=val.end(); ++it){
        mit = tab.find(*it);
        if(mit == tab.end()) 
            continue;
        if(mit->second >= 10){
            int v = countPacket(mit->second);
            printf("%5s   %7d   %7d\n", it->c_str(), mit->second, v);
            bld += v;
            tot += mit->second;
            tab.erase(mit);
            ++ret;
            continue;
        }
        val[i++] = *it;
    }
    val.resize(i);
    return ret;
}
bool bundle3(){
    int ret = 0, i;
    tab.clear();
    for(vector<string>::iterator it=val.begin();
            it!=val.end(); ++it){
        str.assign(*it, 0, 3);
        ++tab[str];
    }
    stable_sort(val.begin(), val.end(), cmp3());
    i = 0;
    for(vector<string>::iterator it=val.begin();
            it!=val.end(); ++it){
        str.assign(*it, 0, 3);
        mit = tab.find(str);
        if(mit == tab.end()) 
            continue;
        if(mit->second >= 10){
            int v = countPacket(mit->second);
            str += "xx";
            printf("%5s   %7d   %7d\n", str.c_str(), mit->second, v);
            bld += v;
            tot += mit->second;
            tab.erase(mit);
            ++ret;
            continue;
        }
        val[i++] = *it;
    }
    val.resize(i);
    return ret;
}
bool handle_over(){
    int ret = 0;
    tab.clear();
    for(vector<string>::iterator it=val.begin();
            it!=val.end(); ++it){
        ++tab[*it];
    }
    stable_sort(val.begin(), val.end(), cmp());
    for(vector<string>::iterator it=val.begin();
            it!=val.end(); ++it){
        mit = tab.find(*it);
        if(mit == tab.end()) 
            continue;
        int v = countPacket(mit->second);
        printf("%5s   %7d   %7d\n", it->c_str(), mit->second, v);
        tot += mit->second;
        tab.erase(mit);
    }
    return val.size();
}

void handle_inv(){
    if(inv.size() <=0) return;
    printf("\nINVALID ZIP CODES\n");
    set<string> tab;
    for(vector<string>::iterator it=inv.begin();
            it!=inv.end(); ++it){
        tab.insert(*it);
    }
    for(vector<string>::iterator it=inv.begin();
            it!=inv.end(); ++it){
        set<string>::iterator sit=tab.find(*it);
        if(sit==tab.end())
            continue;
        printf("%s\n", it->c_str());
        tab.erase(sit);
    }
}

void fun(){
    printf("%-5s   %7s   %7s\n\n", "ZIP", "LETTERS", "BUNDLES");
    if(bundle5()){
        printf("\n");
    }
    if(bundle3()){
        printf("\n");
    }
    if(handle_over()){
        printf("\n");
    }
    printf("%s  %7d   %7d\n", "TOTALS", tot, bld);
    handle_inv();
}

bool check(){
    if(str.length()!=5){
        inv.push_back(str);
        return false;
    }
    int v = 0;
    for(int i=0; str[i]; i++){
        if(!isdigit(str[i])){
            inv.push_back(str);
            return false;
        }
        v += str[i]-'0';
    }
    if(!v)
        inv.push_back(str);
    return v;
}

int main(){

    tot = 0;
    while(cin>>str){
        if( check() ){
            val.push_back(str);
        }
    }
    fun();
    return 0;
}


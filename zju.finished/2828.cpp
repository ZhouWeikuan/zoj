#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;
// 按照定义，互换后再看是否在字典中
enum {
    SIZ = 24,
};
char word[SIZ];
set<string> tab;
void readIn(){
    tab.clear();
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",word);
        string s(word);
        tab.insert(s);
    }
}
void match(){
    string s(word);
    if(tab.find(s) != tab.end()){
        printf("%s\n",word);
        return;
    }
    int i; char c;
    vector<string> v;
    for(i=0; word[i+1];i++){
        c = s[i]; s[i] = s[i+1]; s[i+1] = c;
        if(tab.find(s)!=tab.end()){
            v.push_back(s);
        }
        c =s[i];s[i]=s[i+1];s[i+1]=c;
    }
    if(v.empty()){
        printf("%s",word);
    } else {
        sort(v.begin(),v.end());
        printf("%s",v[0].c_str());
        for(i=1;i<v.size();i++){
            printf(",%s",v[i].c_str());
        }
    }
    printf("\n");
}
void fun(){
    int num;
    scanf("%d",&num);
    while(num--){
        scanf("%s",word);
        match();
    }
}
int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase--){
        readIn();
        fun();
        if(tstcase)
            printf("\n");
    }
    return 0;
}

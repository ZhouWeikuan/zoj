#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
map<string, int> tab;
map<string, int>::iterator it;
char buf[1008];

int proc(){
    int i, v;
    vector<int> st;
    for(i=0; buf[i]!=0; i++){
        if(buf[i]=='('){
            st.push_back(-1);
        } else if(buf[i]==')'){
            v = 0;
            while(st.back()!=-1){
                v += st.back();
                st.pop_back();
            }
            st[st.size()-1] = v;
        } else if(isdigit(buf[i])){
            v = 0;
            do {
                v *= 10;
                v += buf[i]-'0';
            } while(isdigit(buf[++i]));
            i--;
            st[st.size()-1] = st.back()*v;
        } else { // capital
            v = islower(buf[i+1])!=0;
            string s(buf+i, buf+i+1+v);
            it = tab.find(s);
            if(it==tab.end()){
                return -1;
            }
            st.push_back(it->second);
            i += v;
        }
    }
    // combine;
    v = 0;
    for(i=0; i<st.size(); i++){
        v += st[i];
    }
    return v;
}
void fun(){
    int v;
    cin>>buf;
    while(buf[0]!='0'){
        v = proc();
        if(v < 0){
            printf("UNKNOWN\n");
        } else {
            printf("%d\n", v);
        }
        cin>>buf;
    }
}
void readIn(){
    int v;
    string s;
    cin>>s;
    while(s!="END_OF_FIRST_PART"){
        cin>>v;
        tab.insert(make_pair(s, v));
        cin>>s;
    }
}
int main(){
    readIn();
    fun();
    return 0;
}

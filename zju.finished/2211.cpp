#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
enum {
    SIZ = 84,
    LIN = 1504,
    BN = 104,
};
int bn;
int book[BN];
char txt[LIN][SIZ];
char buf[SIZ];
map<string, set<int> > tab;
map<string, set<int> >::iterator it;

int line2book(int line){
    int *a = lower_bound(book, book+bn, line);
    return (*a==line) + a-book;
}

void output(vector<int> &v){
    if (v.size() == 0){
        printf("Sorry, I found nothing.\n");
    } else {
        int p = line2book(v[0]);
        for(int i=0; i<v.size(); i++){
            int n = line2book(v[i]);
            if ( n != p) printf("----------\n");
            printf("%s", txt[v[i]]);
            p = n;
        }
    }
    printf("==========\n");
}

vector<int> find_exact(char *s){
    string str(s);
    it = tab.find(str);
    if (it!=tab.end()){
        vector<int> v(it->second.begin(), it->second.end());
        return v;
    }
    vector<int> v;
    return v;
}

vector<int> find_not(char *s){
    string str(s);
    it = tab.find(str);
    set<int> st;
    if (it!=tab.end()){
        for(set<int>::iterator i=it->second.begin();
                i!=it->second.end(); ++i){
            st.insert(line2book(*i));
        }
    }
    vector<int> v;
    for(int i=0; i<bn; i++){
        if(st.find(i)==st.end()){
            int s = i==0?0:book[i-1];
            int e = book[i];
            while(s<e){
                v.push_back(s);
                ++s;
            }
        }
    }
    return v;
}

vector<int> find_and(char *a, char *b){
    string as(a);
    string bs(b);
    map<string, set<int> >::iterator ai = tab.find(as);
    map<string, set<int> >::iterator bi = tab.find(bs);
    if (ai==tab.end() || bi==tab.end()){
        ;
    } else {
        set<int> at;
        set<int> bt;
        for(set<int>::iterator i=ai->second.begin(); 
                i!=ai->second.end(); ++i){
            at.insert(line2book(*i));
        }
        for(set<int>::iterator i=bi->second.begin(); 
                i!=bi->second.end(); ++i){
            bt.insert(line2book(*i));
        }
        set<int> com;
        for(set<int>::iterator i=at.begin();
                i!=at.end(); ++i){
            if (bt.find(*i)!=bt.end()){
                com.insert(*i);
            }
        }
        set<int> lin;
        for(set<int>::iterator i=ai->second.begin(); 
                i!=ai->second.end(); ++i){
            if (com.find(line2book(*i))!=com.end()){
                lin.insert(*i);
            }
        }
        for(set<int>::iterator i=bi->second.begin(); 
                i!=bi->second.end(); ++i){
            if (com.find(line2book(*i))!=com.end()){
                lin.insert(*i);
            }
        }
        vector<int> v(lin.begin(), lin.end());
        return v;
    }
    vector<int> v;
    return v;
}

vector<int> find_or(char *a, char *b){
    string as(a);
    string bs(b);
    map<string, set<int> >::iterator ai = tab.find(as);
    map<string, set<int> >::iterator bi = tab.find(bs);
    set<int> st;
    if (ai!=tab.end())
        st.insert(ai->second.begin(), ai->second.end());
    if (bi!=tab.end())
        st.insert(bi->second.begin(), bi->second.end());

    vector<int> v(st.begin(), st.end());
    return v;
}

void fun(){
    int num;
    scanf("%d ", &num);
    while(num --){
        fgets(buf, SIZ, stdin);
        vector<char *> v;
        char *p=strtok(buf, " \t\n");
        while(p!=NULL){
            v.push_back(p);
            p = strtok(NULL, " \t\n");
        }
        vector<int> a;
        if (v.size() == 1){
            a = find_exact(v[0]);
        }else if(v.size() ==2){
            a = find_not(v[1]);
        }else if(v.size() == 3){
            a = (strcmp(v[1], "AND")==0
                        ?find_and(v[0], v[2])
                        :find_or(v[0],v[2]));
        } else {
        }
        output(a);
    }
}

void add(char *s, char *e, int l){
    string str="";
    while(s < e){
        str += tolower(*s);
        ++s;
    }
    tab[str].insert(l);
}

void parse(char *s, int l){
    char *pre=s, *cur=s;
    while(*cur){
        while(isalpha(*cur))
            ++cur;
        if (cur - pre >= 1){
            add(pre, cur, l);
        }
        pre = cur + 1;
        ++cur;
    }
}

int readIn(){
    scanf("%d ", &bn);
    int line = 0;
    for(int i=0; i<bn; ){
        fgets(txt[line], SIZ, stdin);
        if (strcmp(txt[line], "**********\n")==0){
            book[i] = line;
            ++i; 
            continue;
        }
        parse(txt[line], line);
        ++line;
    }
    return 0;
}

int main(){

    readIn();
    fun();

    return 0;
}


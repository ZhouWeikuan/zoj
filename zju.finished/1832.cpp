#include<iostream>
#include<string>
using namespace std;
enum {
    SIZ = 300,
};

int len, num;
int low, high;
int cnt[SIZ];
bool vis[SIZ];
string str[SIZ];
char buf[SIZ];

bool search(const string&s){
    int i, j;
    for (i=0; i<num; ++i){
        if (vis[i]) continue;
        for (j=i+1; j<num; ++j){
            if (vis[j]) continue;
            if (str[j].length() + str[i].length() != len) continue;
            if (s == str[i] + str[j] || s == str[j] + str[i]){
                vis[i] = vis[j] = true;
                break;
            }
        }
        if (!vis[i]){
            memset(vis, false, sizeof(vis));
            return false;
        }
    }

    memset(vis, false, sizeof(vis));
    return true;
}

void fun(){
    int pos = low, i, t;
    for (i=low+1; i<=high; ++i){
        if (cnt[i] && cnt[i] < cnt[pos]){
            pos = i;
        }
    }
    t = len - pos;
    for (i=0; i<num; ++i){
        if (str[i].length() == pos){
            pos = i;
        }
    }
    for (i=0; i<num; ++i){
        if (!vis[i] && str[i].length() == t){
            vis[i] = true;
            vis[pos] = true;
            string s = str[i] + str[pos];
            if (search(s)){
                cout<<s<<endl;
                return;
            }
            s = str[pos] + str[i];
            if (search(s)){
                cout<<s<<endl;
                return;
            }
        }
    }
}

int readIn(){
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    low = SIZ, high = -1;
    num = 0;

    char *p = fgets(buf, SIZ, stdin);
    while(p && *p != '\n'){
        p = strtok(p, "\n\t ");
        str[num] = string(p);
        len = str[num].length();
        ++cnt[len];
        if (low > len){
            low = len;
        }
        if (high < len){
            high = len;
        }
        ++num;
        p = fgets(buf, SIZ, stdin);
    }
    len = low + high;
    return num;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
/*
 * TLE
 */
enum {
    SIZ = 104,
    ALP = 26,
};

struct Node {
    unsigned mask;
    Node *lnk[ALP];
};

Node head;
int cnt;
char one[ALP+1];
char ec[ALP+1];
char dc[ALP+1];
int  de[ALP];
int  dd[ALP];
char buf[SIZ];
int freq[ALP][ALP];
vector<string> wd;

Node *getNode(){
    Node *p = (Node*)malloc(sizeof(Node));
    memset(p, 0, sizeof(Node));
    return p;
}

void release(Node *p){
    if (p == 0) return;
    int i;
    for (i=0; i<ALP; ++i){
        if (p->lnk[i]){
            release(p->lnk[i]);
        }
        p->lnk[i] = 0;
    }
    free(p);
}

Node * insert(Node *h, unsigned m, char c){
    c -= 'A';
    h->mask |= m;
    if (h->lnk[c] == 0){
        h->lnk[c] = getNode();
    }
    h = h->lnk[c];
    return h;
}

struct Small {
    bool operator()(const string&a, const string&b){
        int af = 0, bf = 0;
        int i;
        for (i=0; i<a.length(); ++i){
            af += freq[i][a[i]-'A'];
        }
        af /= a.length();
        for (i=0; i<b.length(); ++i){
            bf += freq[i][b[i]-'A'];
        }
        bf /= a.length();
        return af > bf;
    }
};

bool tryMatch(Node *p, unsigned m, char s, char d){
    s -= 'A'; d -= 'A';
    if (p->lnk[s]==0 || (p->lnk[s]->mask&m)!=m)
        return false;

    if (de[s] && ec[s]!=(d+'A'))
        return false;
    if (dd[d] && dc[d]!=(s+'A'))
        return false;
    ++de[s];
    ++dd[d];
    ec[s] = (d+'A');
    dc[d] = (s+'A');
    return true;
}

void tryUnmatch(char s, char d){
    s -= 'A'; d -= 'A';
    if (--de[s]<=0)
        ec[s] = '*';
    if (--dd[d]<=0)
        dc[d] = '*';
}

int dfs(int);

int search(int p, Node *h, int m, const char *s, int d){
    if (s[d]==0){
        return dfs(p+1);
    }
    int r = -1;
    for (int i=0; i<ALP; ++i){
        if (h->lnk[i] == 0 || (h->lnk[i]->mask & m) ==0)
            continue;
        if (tryMatch(h, m, i+'A',s[d])){
            int t = search(p, h->lnk[i], m, s, d+1); 
            if (t > 1) return t;
            if (r < t) r = t;
            tryUnmatch(i+'A', s[d]);
        }
    }
    return r;
}

int dfs(int p){
    if (p >= wd.size()){
        if (cnt == 0){
            memmove(one, ec, sizeof(ec));
            ++cnt;
        }else{
            for (int i=0; i<ALP; i++){
                if ((ec[i]&0x0ff)!=(one[i]&0x0ff)){
                    ++cnt;
                    break;
                }
            }
        }
        return cnt;
    }
    int len = wd[p].length();
    int r = -1;
    for (int i=0; i<ALP; ++i){
        len = search(p, &head, 1<<len, wd[p].c_str(), 0);
        if (len > 1) return len;
        if (r < len) r = len;
    }
    return r;
}

void solve(bool flag){
    memset(ec, '*', sizeof(ec));
    memset(dc, '*', sizeof(dc));
    memset(de, 0, sizeof(de));
    memset(dd, 0, sizeof(dd));
    cnt = 0;

    int t;
    if (flag)
        t = dfs(0);
    else 
        t = -1;
    if (t< 0){
        printf("#No solution#\n");
    } else if(t > 1){
        printf("#More than one solution#\n");
    } else {
        one[ALP] = 0;
        printf("%s\n", one);
    }
}

void fun(){
    int n;
    char *p;
    const char *tstr=" \n\t\r";
    bool flag = true;
    scanf("%d ", &n);
    while(n--){
        flag = true;
        memset(freq, 0, sizeof(freq));
        wd.clear();
        fgets(buf, SIZ, stdin);    
        while(buf[0]!='\n'){
            p = strtok(buf, tstr);
            while(p!= NULL){
                wd.push_back(p);
                if (wd.back().length() > 20)
                    flag = false;
                if (head.mask & (1<<wd.back().length()) != (1<<wd.back().length())){
                    flag = false;
                }
                for (int i=0; p[i]; ++i){
                    ++freq[i][p[i]-'A'];
                }
                p = strtok(NULL, tstr);
            }
            fgets(buf, SIZ, stdin);    
        }
        sort(wd.begin(), wd.end(), Small());
        solve(flag);
    }
}


int readIn(){
    int n,t;
    if(scanf("%d ", &n)!=1)
        return 0;

    Node *p=0;
    head.mask = 0;
    for (t=0; t<ALP; ++t){
        if(head.lnk[t]){
            release(head.lnk[t]);
        }
        head.lnk[t] = 0;
    }

    while(n--){
        scanf("%s ", buf);
        t = strlen(buf);
        p = &head;
        for (int i=0; i<t; ++i){
            p = insert(p, 1<<t, buf[i]);
        }
        p->mask |= (1<<t);
    }

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


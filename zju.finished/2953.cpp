#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
enum {
    SIZ = 104,
};

char name[SIZ][12];
int score[SIZ];
int cnt[SIZ];
int ptr[SIZ];
int par[20], pnum, pos;
struct cmp {
    static bool equal(int a, int b){
        if (score[a] != score[b])
            return false;
        return true;
    }
    bool operator()(const int &a, const int &b) const {
        if (score[a] != score[b])
            return score[a] < score[b];
        if (cnt[a] != cnt[b] && score[a] != 0)
            return score[a] < 0?(cnt[a] < cnt[b]):(cnt[a] > cnt[b]);
        return strcmp(name[a], name[b]) < 0;
    }
};
map<string, int> tab;
char line[100], buf[100];

int find(const string &s){
    map<string, int>::iterator it=tab.find(s);
    if (it != tab.end())
        return it->second;
    strcpy(name[pos], s.c_str());
    tab.insert(make_pair(s, pos));
    ptr[pos] = pos;
    return pos++;
}

void insert(int n, int v){
    score[n] += v - par[cnt[n]];
    ++cnt[n];
}

void format(char *s, int w){
    int len = strlen(s);
    while(len < w){
        printf(" ");
        ++len;
    }
    printf("%s", s);
}

void showRank(){
    sort(ptr, ptr+pos, cmp());
    printf("Place  Name        Score  Holes\n");
    int last = 1;
    for (int i=0; i<pos; ++i){
        if (i && cmp::equal(ptr[i-1], ptr[i])){
            ;
        } else {
            last = i + 1;
        }
        sprintf(line, "%d", last);
        format(line, 5);
        printf("  ");
        printf("%s", name[ptr[i]]);
        line[0] = 0;
        format(line, 10-strlen(name[ptr[i]]));
        printf("  ");
        if (score[ptr[i]] != 0){
            if (score[ptr[i]] > 0){
                line[0] = '+';
                sprintf(line+1, "%d", score[ptr[i]]);
            } else {
                line[0] = '-';
                sprintf(line+1, "%d", -score[ptr[i]]);
            }
        } else {
            strcpy(line, "0");
        }
        format(line, 5);
        printf("  ");
        if (cnt[ptr[i]] >= pnum){
            strcpy(line, "F");
        } else {
            sprintf(line, "%d", cnt[ptr[i]]);
        }
        format(line, 5);
        printf("\n");
    }
    printf("\n");
}

void fun(){
    gets(line);
    while(strcmp(line, "EndOfTournament")!=0){
        if (strcmp(line, "ShowRank") == 0){
            showRank();
        } else {
            int h;
            sscanf(line, "%s%d", buf, &h);
            string s(buf);
            int no = find(s);
            insert(no, h);
        }
        gets(line);
    }
}

void readIn(){
    scanf("%d", &pnum);
    for (int i=0; i<pnum; ++i){
        scanf("%d ", &par[i]);
    }
    tab.clear();
    pos = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(score, 0, sizeof(score));
}

int main(){
    int tst, tn=0;
    scanf("%d", &tst);
    while(tst-- > 0){
        printf("Tournament %d\n", ++tn);
        readIn();
        fun();
    }

    return 0;
}


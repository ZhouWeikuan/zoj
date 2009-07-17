#include<iostream>
#include<algorithm>
using namespace std;
enum {
    SIZ = 64,
    ALP = 20,
};

int freq[2][4];
int up[ALP];
int dn[ALP];
int num;
string ec[SIZ];
string co[SIZ];
char one[26];
char mat[26];
int cnt;

int genCode(int a[5]){
    int b[5] = {a[0],a[1],a[2],a[3],a[4]};
    sort(b, b+5);
    int r = 0;
    for(int i=0; i<5;i++){
        r *= 64;
        r += b[i];
    }
    return r;
}

bool checkFreq(int m[4]){
    for (int i=0; i<4; ++i){
        if (freq[0][i] != freq[1][m[i]])
            return false;
    }
    return true;
}

bool check_and_set(char a, char b){
    a -= 'A';
    if (mat[a] == '?'){
        mat[a] = b;
        return true;
    }
    return mat[a] == b;
}

bool pass(string &a, string &b, int m[4]){
    for (int i=0; i<4; ++i){
        if (!check_and_set(a[i], b[m[i]])){
            return false;
        }
    }
    return true;
}

void match(int m[4]){
    memset(mat, '?', sizeof(mat));
    int i;
    for (i=0; i<num; ++i){
        if (!pass(ec[i], co[i], m)){
            return;
        }
    }
    ++cnt;
    if (cnt == 1){
        memcpy(one, mat, sizeof(one));
    } else {
        for (i=0; i<26; ++i){
            if (one[i] == mat[i])
                continue;
            one[i] = '?';
        }
    }
}

void fun(){
    int m[4] = {0, 1, 2, 3};
    cnt = 0;
    do {
        if (!checkFreq(m))
            continue;
        match(m);
    } while (next_permutation(m, m+4));
}

void output(){
    int i, j;
    int t = 0;
    for (i=0; i<4; ++i){
        for (j=0; j<5; ++j){
            if (j)
                printf(" ");
            printf("%c-%c", 'A'+t, one[t]);
            ++t;
        }
        printf("\n");
    }
}

char * findMiss(int i, int&n){
    n = 0;
    i *= 5;
    char *p = 0;
    for (int j=0; j<5; j++){
        if (one[i+j] == '?'){
            p = &one[i+j];
            ++n;
        }
    }
    return p;
}

char fakeOne(int i){
    i *= 5;
    int t = 0;
    int b;
    for (int j=0; j<5; j++){
        if (one[i+j] != '?'){
            b = one[i+j] -'a';
            t += b % 5;
            b = b - (b % 5);
        }
    }
    t = 10 - t;
    return 'a'+b+t;
}

void makeup(){
    int i, j;
    char *p;
    for (i=0; i<4; ++i){
        p = findMiss(i, j);
        if (j == 1){
            *p = fakeOne(i);
        }
    }
}

int readIn(){
    memset(freq, 0, sizeof(freq));
    memset(up, 0, sizeof(up));
    memset(dn, 0, sizeof(dn));
    cin>>num;
    if (num <=0) return 0;
    int i;
    for (i=0; i<num; i++){
        cin>>ec[i];
        ++up[ec[i][0]-'A'];
        ++up[ec[i][1]-'A'];
        ++up[ec[i][2]-'A'];
        ++up[ec[i][3]-'A'];
    }
    for (i=0; i<ALP; i++){
        freq[0][i] = genCode(&up[i*5]);
    }

    for (i=0; i<num; i++){
        cin>>co[i];
        ++dn[co[i][0]-'a'];
        ++dn[co[i][1]-'a'];
        ++dn[co[i][2]-'a'];
        ++dn[co[i][3]-'a'];
    }
    for (i=0; i<ALP; i++){
        freq[1][i] = genCode(&dn[i*5]);
    }

    return 1;
}

int main(){
    int tst = 1;
    while(readIn() > 0){
        fun();
        printf("Test #%d:\n", tst++);
        makeup();
        output();
    }

    return 0;
}


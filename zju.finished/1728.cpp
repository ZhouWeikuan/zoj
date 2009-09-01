#include<iostream>
using namespace std;
enum {
    ALP = 26,
};

int key[ALP];
int rev[ALP];

void outKey(){
    for (int i=0; i<ALP; ++i){
        printf("%c", 'A'+key[i]);
    }
}

int getVal(char c){
    if (isupper(c)){
        return c-'A';
    }
    return c-'a';
}

inline int toVal(char c){
    return rev[getVal(c)];
}

char enc(char p, char c){
    if (!isalpha(c)) return c;
    if (!isalpha(p)) p = 'a';
    int t = toVal(c) - toVal(p);
    t = (t + ALP)%ALP;
    p = key[t] + 'a';
    if (isupper(c)){
        p = toupper(p);
    }
    return p;
}

char dec(char p, char c){
    if (!isalpha(c)) return c;
    if (!isalpha(p)) p = 'a';
    int t = toVal(c) + toVal(p);
    t = (t + ALP)%ALP;
    p = key[t] + 'a';
    if (isupper(c)){
        p = toupper(p);
    }
    return p;
}

int changeKey(char *str = NULL){
    int i;
    if (str==0){
        for (i=0; i<ALP; ++i){
            key[i] = i;
            rev[i] = i;
        }
        return 0;
    }
    int j=0;
    bool vis[ALP] = {false};
    for (i=0; str[i]; ++i){
        if (!isalpha(str[i])) continue;
        int t = getVal(str[i]);
        if (vis[t]){
            changeKey(NULL);
            return -1;
        }
        vis[t] = true;
        rev[t] = j;
        key[j++] = t;
    }
    if (j<ALP){
        changeKey(NULL);
        return -1;
    }
    return 0;
}

char cmd[100];
char line[10004];

void encrypt(){
    char p = 'a';
    for (int i=0; line[i]; ++i){
        char t = enc(p, line[i]);
        p = line[i];
        line[i] = t;
    }
    printf("RESULT: %s", line);
}

void decrypt(){
    char p = 'a';
    for (int i=0; line[i]; ++i){
        line[i] = dec(p, line[i]);
        p = line[i];
    }
    printf("RESULT: %s", line);
}

void fun(){
    while(scanf("%s", cmd) > 0){
        fgets(line, 10004, stdin);
        if (strcasecmp(cmd, "ENCRYPT")==0){
            encrypt();
        } else if(strcasecmp(cmd, "DECRYPT")==0){
            decrypt();
        } else if(strcasecmp(cmd, "CIPHER")==0){
            if (0==changeKey(line)){
                printf("Good cipher.  Using ");
                outKey();
                printf(".\n");
            } else {
                printf("Bad cipher.  Using default.\n");
            }
        } else {
            printf("Command not understood.\n");
        }
    }
}

int main(){
    changeKey(0);
    fun();

    return 0;
}


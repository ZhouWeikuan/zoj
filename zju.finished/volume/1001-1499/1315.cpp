#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>

using namespace std;
enum {
    LEN = 24,
    SIZ = 80,
};
typedef int(*cmp_t)(const void*, const void*);
char exlist[LEN][LEN];
char sentence[LEN][SIZ];
char buf[SIZ];
int K, S;

int readIn(){
    if(scanf("%d%d ",&K,&S) < 0)
        return 0;
    int i;
    for(i=0; i<K; i++){
        fgets(buf, SIZ, stdin);
        for(int j=0; buf[j]; j++){
            if(buf[j]>='a' && buf[j]<='z'){
                exlist[i][j] = buf[j];
            } else {
                exlist[i][j] = 0;
                break;
            }
        }
    }
    qsort(exlist, K, sizeof(exlist[0]), (cmp_t)strcmp);
    for(i=0; i<S;i ++){
        fgets(sentence[i], SIZ, stdin);
    }

    return 1;
}
void scopy(char *d, char *s){
    int i;
    for(i=0; s[i]; i++){
        if(isalpha(s[i])){
            d[i] = s[i];
            if(s[i] >= 'A' && s[i] <='Z'){
                d[i] -= 'A';
                d[i] += 'a';
            }
        } else if(s[i] == '\n'){
            d[i] = s[i] = 0;
            return;
        } else {
            d[i] = ' ';
        }
    }
    d[i] = 0;
}
int cnt_num(char *s){
    int val = 0;
    scopy(buf, s);
    s = strtok(buf, " ");
    char *ptr;
    while(s){
        ptr = (char *)bsearch(s, exlist, K, sizeof(exlist[0]), (cmp_t)strcmp);
        if(ptr != NULL) {
            val ++;
        }

        s = strtok( NULL, " ");
    }

    return val;
}

void fun(){
    int val = -1, t, top, i;
    char * sl[LEN] = {0};
    top = 0;
    for(i=0;i<S;i++){
        t = cnt_num( sentence[i]);
        if(t > val){
            val = t;
            top = 0;
            sl[top++] = sentence[i];
        } else if(t == val){
            sl[top++] = sentence[i];
        }
    }
    for(i=0; i<top ;i++){
        printf("%s\n", sl[i]);
    }
}

int main(){
    int tstcase = 0;

    while(readIn()){
        printf("Excuse Set #%d\n", ++tstcase);
        fun();
        printf("\n");
    }

	return 0;
}

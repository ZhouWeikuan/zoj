#include<cstdio>
#include<cstring>

// 先转化，再匹配，从strux?处拷贝思想
using namespace std;
const char * str[26] = {
    ".-","-...", "-.-.", "-..",".", "..-.", "--.", "....",
    "..", ".---", "-.-",  ".-..",   "--", "-.",   "---",  ".--.",
    "--.-", ".-.", "...", "-",    "..-", "...-", ".--", "-..-",    "-.--", "--.."
};
enum {
    SIZ = 10004,
};
struct Node {
    int pos;
    char alp[84];
};
Node word[SIZ];
char input[SIZ];
int len;
int num;
int res[SIZ] = {0};

void tran(char *s, Node * p){
    p->alp[0] = 0;
    while(*s){
        strcat(p->alp, str[*s - 'A']);
        s ++;
    }
    p->pos = strlen(p->alp);
}

void readIn(){
    scanf("%d",&num);
    static char buf[26];    
    for(int i=0;i<num;i++){
        scanf("%s",buf);
        tran(buf, &word[i]);
    }
}

void fun(){
    int i,j;
    res[0] = 1;
    for(i=0;i<len;i++){
        if(res[i] == 0)
            continue;
        for(j=0;j<num;j++){
            if(strncmp(&input[i], word[j].alp, word[j].pos) == 0){
                res[i + word[j].pos] += res[i];
            }
        }
        res[i] = 0;
    }
    printf("%d\n", res[i]);
    res[i] = 0;
}

int main(){
    int tstcase;
    scanf("%d",&tstcase);

    while(tstcase --){
        scanf("%s", input);
        len = strlen(input);
        readIn();
        fun();
    }

	return 0;
}

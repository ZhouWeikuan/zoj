#include<iostream>
using namespace std;
enum {
    SIZ = 108,
    MaxN = 1000008,
};
// 空集,
char str[MaxN];
int deep[SIZ], pos;
int dir[SIZ], num; 

int output(char *s){
    int d = 0;
    while(*s==' '){
        s++;
    }
    char *a = s;
    while(*s){
        if(*s=='{'){
            d++;
        } else if(*s=='}'){
            d--;
        } else if(d==0 && *s==','){
            break;
        }
        if(d < 0){
            break;
        }
        s++;
    }
    *s = 0;
    if(a == s)
        return -1;
    printf("%s\n", a);
    return 1;
}
int fun(){
    int t; char ch;
    num = 0;
    do {
        scanf("%d%c", &t, &ch);
        dir[num++] = t;
    } while(ch!='\n');
    pos = -1;
    for(int i=0; str[i]!='\n';){
        switch(str[i]){
        case '{':
            deep[++pos] = 0;
            break;
        case '}':
            --pos;
            break;
        case ',':
            deep[pos]++;
            if(deep[pos] > dir[pos])
                return -1;
            break;
        default:
            break;
        }
        i++;
        if(pos+1 == num && deep[pos] == dir[num-1]){
            return output(&str[i]);
        }
    }

    return -1;
}

int main(){
    int tstcase, tstnum=0;
    int t;
    scanf("%d ", &tstcase);

    while(tstnum++ < tstcase){
        fgets(str, MaxN, stdin);
        printf("Case %d:\n", tstnum);
        t = fun();
        if(t == -1){
            printf("Invalid query!\n");
        }
        if(tstnum < tstcase){
            printf("\n");
        }
        fgets(str, MaxN, stdin);
    }

    return 0;
}


#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
enum {
    SIZ = 108,
    ALP = 26,
};
typedef int(*cmp_t)(const void*,const void*);
char orig[SIZ];
char dest[SIZ];
int o[ALP];
int d[ALP];

int mycmp(const int *a, const int *b){
    return *a - *b;
}

void calc(char *s, int *c){
    memset(c, 0, sizeof(d));
    while(*s){
        c[*s -'A']++;
        s ++;
    }
}

int fun(){
    int i,j;
    int flag;
    calc(orig, o);
    calc(dest, d);
    /* 任意替换 */
    qsort(o, ALP, sizeof(o[0]), (cmp_t)mycmp);
    qsort(d, ALP, sizeof(d[0]), (cmp_t)mycmp);
    flag = 1;
    for(i=0;i<ALP; i++){
        if(o[i] != d[i]){
            flag = 0;
            break;
        }
    }
    return flag;
/*  隔x个位置替换
    for(i=0; i<ALP; i++){ // shift
        flag = 1;
        for(j=0;j<ALP; j++){ // index compare
            if(d[j] != o[(j+i)%ALP]){
                flag = 0;
                break;
            }
        }
        if(flag)
            return 1;
    }
    return 0;
*/
}

int main(){
    int t;
    const char *ans[2] = {
        "NO",
        "YES"
    };

    while(scanf("%s %s ", orig, dest) > 0){
        t = fun();
        printf("%s\n", ans[t]);
    }

	return 0;
}

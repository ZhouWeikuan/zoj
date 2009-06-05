#include<iostream>
using namespace std;
enum {
    SIZ = 30,
};
int s, e;
char car[SIZ];

int find(char ch){
    int i;
    for(i=s; i<=e&&car[i]!=ch; i++)
        ;
    return i;
}
void change(int s, int e){
    char ch;
    while(s<e){
        ch = car[s], car[s] = car[e], car[e]=ch;
        ++s, --e;
    }
}
void fun(){
    int n, p;
    char ch;
    static int tst=1;
    if(tst>1) printf("\n");
    printf("Dataset #%d:  The initial order is %s.\n", tst++, car);
    scanf("%d", &n);
    while(n--){
        scanf(" %c", &ch);
        p = find(ch);
        if(p-s<=e-p){ // left;
            car[p] = car[s];
            ++s;
            change(s,p-1);
        } else { // right;
            car[p] = car[e];
            --e;
            change(p+1, e);
        }
        car[e+1] = 0;
        printf("After %c leaves, the order is %s.\n", ch, &car[s]);
    }
}
int readIn(){
    scanf("%s", car);
    if(strcmp(car, "STOP")==0){
        return 0;
    }
    s = 0;
    e = strlen(car)-1;
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}


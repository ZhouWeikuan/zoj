#include<iostream>
using namespace std;
enum {
    SIZ = 20,
};
int num;
char card[SIZ][8];

bool same(char a, char b, char c){
    return a==b && b==c;
}
bool diff(char c, char b, char a){
    return (a!=b)&&(b!=c)&&(a!=c);
}
bool inset(char *a, char *b, char *c){
    for(int i=0; i<4; i++){
        if(same(a[i], b[i], c[i]) || diff(a[i], b[i], c[i])){
            ;
        }else{
            return false;
        }
    }
    return true;
}
void fun(){
    int i,j,k;
    int cnt = 0;
    printf("CARDS: ");
    for(i=0; i<num; i++){
        printf(" %s", card[i]);
    }
    printf("\nSETS:");
    for(i=0; i<num; i++){
        for(j=i+1; j<num; j++){
            for(k=j+1; k<num; k++){
                if(inset(card[i], card[j], card[k])){
                    ++cnt;
                    if(cnt == 1){
                        printf("   %d. ", cnt);
                    } else {
                        printf("        %d. ", cnt);
                    }
                    printf(" %s %s %s\n", card[i], card[j], card[k]);
                }
            }
        }
    }
    if(cnt == 0){
        printf("   *** None Found ***\n");
    }
}
int readIn(){
    num = 0;
    if(gets(card[num]) == 0)
        return 0;
    while(card[num][0] != 0){
        num++;
        gets(card[num]);
    }
    return num;
}
int main(){
    int tst=0;
    while(readIn() > 0){
        if(tst++) printf("\n");
        fun();
    }
    return 0;
}


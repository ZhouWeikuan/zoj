#include<iostream>
using namespace std;
enum {
    SIZ = 8,
    LIM = SIZ*24,
};
char buf[SIZ][LIM];
char ten[11][SIZ][SIZ + 1] = {
{ "  XXXX  ",  " XX  XX ",  " XX  XX ",  " XX  XX ",  
  " XX  XX ",  " XX  XX ",  " XX  XX ",  "  XXXX  "},
{ "   XX   ",  " XXXX   ",  "   XX   ",  "   XX   ",
  "   XX   ",  "   XX   ",  "   XX   ",  " XXXXXX "},
{ "  XXXX  ",  " XX  XX ",  " XX  XX ",  "     XX ",
  "    XX  ",  "   XX   ",  "  XX    ",  " XXXXXX "},
{ "  XXXX  ",  " X   XX ",  "     XX ",  "   XXX  ",
  "     XX ",  "     XX ",  " X   XX ",  "  XXXX  "},
{ "    XX  ",  "   XXX  ",  "   XXX  ",  "  X XX  ",
  " X  XX  ",  " XXXXXX ",  "    XX  ",  "  XXXXX "},
{ "  XXXXX ",  "  XX    ",  "  XXXX  ",  "  X  XX ",
  "     XX ",  "     XX ",  " X   XX ",  "  XXXX  "},
{ "   XXXX ",  "  XX    ",  " XX     ",  " XXXXX  ",
  " XX  XX ",  " XX  XX ",  " XX  XX ",  "  XXXX  "},
{ " XXXXXX ",  " X   XX ",  "     XX ",  "    XX  ",
  "    XX  ",  "    XX  ",  "   XX   ",  "   XX   "},
{ "  XXXX  ",  " XX  XX ",  " XX  XX ",  "  XXXX  ",
  " XX  XX ",  " XX  XX ",  " XX  XX ",  "  XXXX  "},
{ "  XXXX  ",  " XX  XX ",  " XX  XX ",  " XX  XX ",
  "  XXXXX ",  "     XX ",  "    XX  ",  " XXXX   "}
};

int mycmp(char *s, char *m){
    for(int i=0; i<6; i++){
        if(s[i] == 0){
            s[i+1] = 0;
        }
        if(m[i] != 'X' && s[i] !='X') continue;
        if(m[i] !=s[i]){
            return 1;
        }
    }
    return 0;
}
int check(int &s){
    bool b = true;
    int i;
    while(1) {
        for(i=0; i<SIZ; i++){
            if(buf[i][s] != ' ')
                break;
        }
        if(i!=SIZ)
            break;
        s ++;
    }
    for(int i=0; i<10; i++){
        b = true;
        for(int j=0; j<SIZ; j++){
            if(mycmp(&buf[j][s], &ten[i][j][1]) != 0){
                b = false;
                break;
            }
        }
        if(b){
            s += 6;
            return i;
        }
    }
    s += 7;
    return 10;
}
void fun(){
    int a = 0, b = 0;
    int i=0, t;
    for( ;(t=check(i))!=10;){
        a *= 10;
        a += t;
    }
    for(;(t=check(i))!=10;){
        b *= 10;
        b += t;
    }
    static char ans[10], pos;
    a += b;
    sprintf(ans, "%d", a);
    for(i=0; i<SIZ; i++){
        for(int j=0; ans[j]; j++){
            printf("%s", ten[ans[j]-'0'][i]);
        }
        printf("\n");
    }
}

void readIn(){
    fgets(buf[0], LIM, stdin); 
    for(int i=0; i<SIZ; i++){
        fgets(buf[i], LIM, stdin);
    }
}
int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase--){
        readIn();
        fun();
        if(tstcase){
            printf("\n");
        }
    }
    return 0;
}

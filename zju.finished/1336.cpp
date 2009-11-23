#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
enum {
    SIZ = 104,
    BOLD = 1, 
    FONT = 2,
    ITAL = 4, 
};
char buf[SIZ] = {0};
bool isCmt;
unsigned mark;
int pos;

char getNext(){
    if (buf[pos] == 0){
        if (fgets(buf, SIZ, stdin) == 0)
            return -1;
        pos = 0;
    }
    return buf[pos++];
}

void putBack(char ch){
    buf[--pos] = ch;
}

void ignoreNumeric(){
    bool pnt = false;
    char ch = getNext();
    while(isdigit(ch) || (!pnt && ch=='.')){
        if (ch == '.')
            pnt = true;
        ch = getNext();
    }
    putBack(ch);
}

void fun(){
    char ch;
    while(-1!=(ch=getNext())){
        if (ch == '\\'){
            ch = getNext();
            if (isCmt){
                if (ch == '*') {
                    isCmt = false;
                } else {
                    printf("\\");
                    putBack(ch);
                }
            } else {
                if (ch == '*'){
                    isCmt = true;
                } else if (ch == 'b'){
                    ;
                } else if (ch == 's'){
                    ignoreNumeric();
                } else if (ch == 'i'){
                    ;
                } else { // 
                    printf("%c", ch);
                }
            }
        } else {
            printf("%c", ch);
        }
    }
}

int main(){
    isCmt = false;
    mark = 0;
    fun();
    return 0;
}


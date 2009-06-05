#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int reg[10];
int ram[1000];
int pc, ins;

inline int get0(int a){
    return a/100%10;
}
inline int get1(int a){
    return a/10%10;
}
inline int get2(int a){
    return a%10;
}
void fun(){
    int code, a, b;
    ins = pc = 0;
    for(;;){
        ins++;
        code = ram[pc++];
        pc %= 1000;
        a = get1(code);
        b = get2(code);
        switch(get0(code)){
        case 1:
            if(code == 100)
                return;
            break;
        case 2:
            reg[a]=b;
            break;
        case 3:
            reg[a]+=b; reg[a]%=1000;
            break;
        case 4:
            reg[a]*=b; reg[a]%=1000;
            break;
        case 5:
            reg[a]=reg[b];
            break;
        case 6:
            reg[a]+=reg[b]; reg[a]%=1000;
            break;
        case 7:
            reg[a]*=reg[b]; reg[a]%=1000;
            break;
        case 8:
            reg[a]=ram[reg[b]]; reg[a]%=1000;
            break;
        case 9:
            reg[a]%=1000;
            ram[reg[b]]=reg[a]; 
            break;
        case 0:
            if(reg[b]%1000!=0){
                pc = reg[a]%1000;
            }
            break;
        default:
            break;
        }
    }
}

int readIn(){
    int p = 0;
    memset(reg, 0, sizeof(reg));
    memset(ram, 0, sizeof(ram));
    char s = fgetc(stdin);
    while(s!='\n'&&!feof(stdin)){
        do {
            if(isdigit(s)){
                scanf("%d", &ram[p]);
                ram[p] += (s-'0')*100;
                p++;
            }
            s = fgetc(stdin);
        } while(s!='\n');
        s = fgetc(stdin);
    }
    return p;
}

int main(){

    while(readIn() > 0){
        fun();
        printf("%d\n", ins);
    }

    return 0;
}


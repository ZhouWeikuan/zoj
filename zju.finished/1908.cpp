#include<iostream>
#include<set>
#include<stack>

using namespace std;
set<unsigned int> tab;
char desk[3][3] = {0};

const unsigned bitloc = 20;
const unsigned play = ~(1<<bitloc);
const unsigned X = 0x01;
const unsigned O = 0x02;
const unsigned op[2] = {O,X};

unsigned char2int(){
    int i,j;
    unsigned ret = 0,t;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            t = desk[i][j];
            t &= 0x03;
            t <<= (i*3+j)*2;
            ret |= t;
        }
    }
    return ret;
}
void int2char(unsigned u){
    int i,j;
    char t;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            desk[i][j] = u &0x03;
            u>>=2;
        }
    }
}
bool line(void){
    int i;
    //vertical
    for(i=0;i<3;i++){
        if((desk[1][i] > 0) 
            && (desk[1][i] == desk[0][i])
            && (desk[2][i] == desk[1][i])){
            return true;
        }
    }
    //horizontal
    for(i=0;i<3;i++){
        if((desk[i][0] > 0) 
            && (desk[i][0] == desk[i][1])
            && (desk[i][0] == desk[i][2])){
            return true;
        }    
    }
    //diagonal
    if( (desk[1][1] > 0) && (desk[0][0]==desk[1][1]) && (desk[1][1]==desk[2][2])){
        return true;
    }
    if( (desk[1][1] > 0) && (desk[0][2]==desk[1][1]) && (desk[1][1]==desk[2][0])){
        return true;
    }
    return false;
}

void fun(int cur){
    unsigned state = char2int();
    state |= (cur<<bitloc);
    if(tab.find(state)!=tab.end()){
        return;
    }
    tab.insert(state);
    if(line() == true){
        return;
    }
    cur = 1 - cur;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(desk[i][j] != 0){
                continue;
            }
            desk[i][j] = op[cur];
            fun(cur);
            desk[i][j] = 0;
        }
    }
}

void init(){
    fun(0); 
}

//ret value: who finished the last op, 0,1
// -1 indicate fail.
int readIn(){
    char t;
    int a= 0,b =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>t;
            if(t == 'X'){
                t = X;
                a++;
            }else if(t=='O'){
                t = O;
                b++;
            }else{
                t = 0;
            }
            desk[i][j] = t;
        }
    }
    if(b > a || a - b > 1){
        return -1;
    }
    if(a == b){
        return 0;
    }
    return 1;
}

int main(){
    init();
    
    int num,ret;
    unsigned state;
    cin>>num;
    while(num--){
        ret = readIn();
        state = char2int();
        state |= (ret<<bitloc);
        if(ret >= 0 && tab.find(state) != tab.end()){
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }

	return 0;
}

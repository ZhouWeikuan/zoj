#include<iostream>

using namespace std;
enum {
    SIZ = 70,
};

struct Node {
    bool    pos;
    bool    use;    
};

struct BigNum {
    int sign;   // 1, -1;
    char dat[SIZ];
    int len;
    
    BigNum(){
        len = 0;
    }
    void convert(char *s){
        if(*s == '-'){
            sign = -1;
            s++;
        } else {
            sign = 1;
        }
        len = (int)strlen(s);
        for(int i=0; i<len; i++){
            dat[i] = s[len - i - 1] - '0';
        }
        dat[len] = 0;
    }
    void inc(){        
        dat[0] += sign;
        adjust();
    }
    void dec(){
        dat[0] -= sign;
        adjust();
    }
    void adjust(){
        for(int i=0; i<len; i++){
            if(dat[i] < 0){
                dat[i] += 10;
                dat[i+1] -= 1;
            } else if(dat[i] > 9){
                dat[i] -= 10;
                dat[i+1] += 1;
            } else {
                return;
            }
        }
        len ++;
        dat[len] = 0;
    }
    bool odd(){
        return (dat[0]%2)!=0;
    }
    bool zero(){
        return len==0 || (len ==1 && dat[0] == 0);
    }
    void div2(){
        int carry = 0;
        for(int i=len-1; i>=0; i--){
            carry *= 10;
            carry += dat[i];
            dat[i] = carry / 2;
            carry %= 2;
        }
        while(len > 1 && dat[len-1] == 0){
            len--;
        }
    }
};

int     num;
Node    tree[SIZ];
char    input[SIZ];
BigNum  val;

void readIn(){
    cin>>num>>input;        
        
    for(int i=0; i<num; i++){    
        tree[i].use = false;
        if(input[i] == 'p'){
            tree[num-i-1].pos = true;            
        } else {
            tree[num-i-1].pos = false;            
        }
    }
    
    cin>>input;
    val.convert(input);
}

bool fun(){
    for(int i=0; i<num; i++){             
        if(val.odd() ){
            tree[i].use = true;
            if(tree[i].pos ){
                val.dec();
            } else {
                val.inc();
            }
        }
        val.div2();
    }
    return (val.zero());
}

int main(){
    int tstcase;
    
    cin>>tstcase;
    while(tstcase --){
        readIn();
        if( fun() ){
            for(int i=0; i<num; i++){
                int t = num - i - 1;
                cout<<(tree[t].use?"1":"0");
            }
            cout<<endl;
        } else {
            cout<<"Impossible"<<endl;
        }
    }
    
    return 0;
}
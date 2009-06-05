#include<iostream>
using namespace std;
enum {
    SIZ = 8,
};
int c2d(char c){
    switch(c){
    case 'V':
        return 0;
    case 'U':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    }
    return 0;
}
char d2c(int d){
    static const char ans[5] ="VUCD";
    return ans[d];
}
class Cow{
  public:
    Cow();
    Cow &operator=(const char*s);
    void A(const Cow & rhs);
    void R();
    void L();
    void N();
    int cmp(const char*s);
  private:
    Cow(const char *s);
    Cow(const Cow&rhs);
    void set(const char *s);

    int len;
    char dat[SIZ];
};
Cow::Cow(){
    len =0;
}
Cow& Cow::operator=(const char *s){
    this->set(s);
}
void Cow::set(const char*s){
    len = strlen(s);
    int i,j=0;
    int t;
    for(i=len-1;i>=0;i--){
        t = c2d(s[i]);
        dat[j++] = t;
    }
}
void Cow::A(const Cow & rhs){
    int i = 0;
    while(i<len && i < rhs.len){
        dat[i] += rhs.dat[i];
        i++;
    }
    while(i < rhs.len){
        dat[i] = rhs.dat[i];
        i++;
    }
    if(len < i)
        len = i;
    int carry = 0;
    for(i=0;i<len;i++){
        carry += dat[i];
        dat[i] = carry % 4;
        carry /= 4;
    }
    while(carry){
        dat[len++] = carry % 4;
        carry /= 4;
    }
}
void Cow::R(){
    int i;
    for(i=0;i<len-1;i++){
        dat[i] = dat[i+1];
    }
    dat[i] = 0;
}
void Cow::L(){
    int i;
    for(i=len;i>0;i--){
        dat[i] = dat[i-1];
    }
    len++;
    dat[0] = 0;
}
void Cow::N(){
    return;
}
int Cow::cmp(const char *s){
    while(len<8){
        dat[len] = 0;
        len++;
    }
    int i;
    for(i=0;i<len;i++){
        dat[i] = d2c(dat[i]);
    }
    for(i=len-1;i>=0;i--){
        if(s[len-i-1] != dat[i])
            return 0;
    }
    return 1;
}
void fun(){
    Cow a,b;
    char op;
    static char buf[20];
    cin>>buf;
    a = buf;
    cin>>buf;
    b = buf;
    for(int i=0;i<3;i++){
        cin>>op;
        switch(op){
        case 'R':
            b.R();
            break;
        case 'L':
            b.L();
            break;
        case 'N':
            b.N();
            break;
        default:
            b.A(a);
            break;
        }
    }
    static const char *ans[2] = {
        "NO",
        "YES"
    };
    cin>>buf;
    cout<<ans[b.cmp(buf)]<<endl;
}

int main(){
    int num;
    cout<<"COWCULATIONS OUTPUT"<<endl;
    cin>>num;
    while(num--){
        fun();
    }
    cout<<"END OF OUTPUT"<<endl;

    return 0;
}

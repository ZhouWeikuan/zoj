#include<iostream>
#include<iomanip>
using namespace std;
enum {
    SIZ = 100,
};
struct Format{
    int size;
    int adj;
};
int row,col,total;
Format title[SIZ];
string tab[SIZ][SIZ];
char buf[SIZ];

void dup_char(char c, int n){
    while(n--){
        cout<<c;
    }
}

inline int check(char s){
    if(s=='*'||s=='='||s=='<'||s=='>')
        return 0;
    return 1;
}

void parse(){
    int p = 0,cur=0;
    int c = -1;
    while(1){
        c++;
        while(buf[cur] && buf[cur]!='&'){
            cur++;
        }
        tab[row][c] = string(buf+p, buf+cur);
        if(title[c].size < tab[row][c].length()){
            total -= title[c].size;
            total += tab[row][c].length();
            title[c].size = tab[row][c].length();
        }
        p = cur + 1;
        if(!buf[cur])
            break;
        cur++;
    }

}

void readIn(){
    row = col = total = 0;
    for(col=0;buf[col];col++){
        title[col].size = 0;
        if(buf[col] =='='){
            title[col].adj = 0;
        } else if(buf[col] == '<'){
            title[col].adj = -1;
        } else {
            title[col].adj = 1;
        }
    }
    total = 1 + col * 3;
    cin.getline(buf, SIZ);
    while( check(buf[0])){
        parse();
        row++;
        cin.getline(buf, SIZ);
    }
}

void output_col(int r, int c){
    if(title[c].adj == -1){
        cout.width(title[c].size);
        cout<<resetiosflags(ios::adjustfield)<<setiosflags(ios::left)<<tab[r][c];
    } else if(title[c].adj == 1){
        cout.width(title[c].size);
        cout<<resetiosflags(ios::adjustfield)<<setiosflags(ios::right)<<tab[r][c];
    } else {
        int t = title[c].size - tab[r][c].length();
        int f = t/2;
        dup_char(' ', f);
        cout<<tab[r][c];
        dup_char(' ', t-f);
    }
}

void output_row(int r){
    cout<<"| ";
    for(int i=0;i<col;i++){
        output_col(r,i);
        if(i<col-1){
            cout<<" | ";
        } else {
            cout<<" |"<<endl;
        }
    }
}
void output_row0(){
    output_row(0);
    cout<<'|';
    int t;
    for(int i=0;i<col;i++){
       t = title[i].size + 2; 
       dup_char('-', t);
       if(i <col-1){
           cout<<'+';
       } else {
           cout<<'|'<<endl;
       }
    }
}

int fun(){
    int i;
    cout<<'@';
    dup_char('-', total -2);
    cout<<'@'<<endl;
    output_row0();
    for(i=1;i<row;i++){
        output_row(i);
    }
    cout<<'@';
    dup_char('-', total -2);
    cout<<'@'<<endl;
}

int main(){
    cin.getline(buf, SIZ);
    while(buf[0] != '*'){
        readIn();
        fun();
    }

    return 0;
}

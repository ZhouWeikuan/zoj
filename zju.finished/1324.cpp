#include<iostream>
#include<string>
using namespace std;
enum {
    SIZ = 108,
    WID = 60,
};
int len, num;
string word[SIZ];

void readIn(){
    len = 0;
    for(int i=0; i<num; i++){
        cin>>word[i];
        if(len < word[i].length() ){
            len = word[i].length();
        }
    }
    sort(word, word+num);
}
void fun(){
    int col, grp;
    for(col=1; col<=num; col++){
        grp = num/col;
        if(num%col != 0) grp++;
        if((col-1)*(len+2) + len > WID){
            col--;
            grp = num/col + (num%col!=0);
            break;
        }
    }
    int i,j,t;
    for(i=0; i<WID; i++){
        printf("-");
    }
    printf("\n");
    for(i=0; i<grp; i++){
        for(j=0; j<col; j++){
            t = j * grp + i;
            printf("%s", word[t].c_str());
            if( t + grp < num){
                printf("  ");
            } else {
                break;
            }
            for(int k=word[t].length(); k<len; k++){
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main(){
    while(cin>>num){
        readIn();
        fun();
    }
    return 0;
}


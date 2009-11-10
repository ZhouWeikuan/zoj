#include<iostream>

using namespace std;
enum {
    SIZ = 100,
};
char s[SIZ];
int tstcase = 0;
int tab[1000] = {0};

int fun(){
    int len;
    for(len = 0; s[len]; len++){
        s[len] -= 'A';
    }
    int i,j;
    int t;
    for(i=1;i<len;i++){
        tstcase ++;
        for(j=0;j+i<len;j++){
            t = s[j]*26 + s[j+i];
            if(tab[t] < tstcase){
                tab[t] = tstcase;
            } else {
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int t;

    cin>>s;
    while(s[0] !='*'){
        cout<<s<<" is ";
        t = fun();
        if(t){
            cout<<"NOT ";
        }
        cout<<"surprising."<<endl;

        cin>>s;
    }

	return 0;
}

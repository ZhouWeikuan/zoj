#include<iostream>
#include<map>
#include<string>
#include<cstring>

using namespace std;
enum {
    SIZ = 100,
};
char buf[2][SIZ];
char *pre, *cur;
map<string,int> tab;

void compute(){
    static int d[10]={0};
    static char mybuf[20];
    int i,t;
    memset(d,0,sizeof(d));
    cur[0] = 0;
    for(i=0;pre[i];i++){
        t = pre[i] - '0';
        d[t] ++;
    }
    for(i=0;i<10;i++){
        if(d[i]==0)
            continue;
        sprintf(mybuf,"%d%d",d[i],i);
        strcat(cur,mybuf);
    }
}

void fun(){
    cout<<pre;
    compute();
    if(strcmp(pre,cur)==0){
        cout<<" is self-inventorying"<<endl;
        return;
    }

    int step = 0;
    int t;
    tab.clear();
    while(step++ < 16){
        string s(pre);
        if(tab.find(s) != tab.end()){
            t = tab[s];
            step -= t;
            cout<<" enters an inventory loop of length "<<step<<endl;
            return;
        } else {
            tab[s] = step;
        }
        char *k=pre; pre=cur; cur=k;
        compute();
        if(strcmp(pre,cur)==0){
            cout<<" is self-inventorying after "<<step<<" steps"<<endl;
            return;
        }

    }
    
    cout<<" can not be classified after 15 iterations"<<endl;
}

int main(){
    int blocknum;
    cin>>blocknum;
    while(blocknum--){
        pre = buf[0]; cur = buf[1];
        cin>>pre;
        while(pre[0] != '-'){
            fun();

            pre = buf[0]; cur = buf[1];
            cin>>pre;
        }

        if(blocknum){
            cout<<endl;
        }
    }

	return 0;
}

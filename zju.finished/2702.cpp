#include<iostream>
#include<map>
using namespace std;
// Wrong Answer
enum {
    SIZ = 4008,
};
int num, out;
int dat[SIZ];
int ptr[SIZ];
map<int, int>  tab;
map<int, int>::iterator it;

void output(){
    int i;
    out /= 4;
    printf("%d\n", out);
    for(i=0; i<out;++i){
        printf("%d %d %d %d\n", 
                ptr[4*i], 
                ptr[4*i+1], 
                ptr[4*i+2], 
                ptr[4*i+3]);
    }
    printf("\n");
}
void fun(){
    int i;
    tab.clear();
    for(i=0; i<num; i++){
        it=tab.find(dat[i]);
        if(it == tab.end()){
            tab.insert(make_pair(dat[i], i));
        } else {
            ptr[out++] = 1 + it->second;
            ptr[out++] = 1 + i;
            if(out % 4 == 0){
                tab.clear();
            } else {
                tab.erase(it);
            }
        }
    }
    sort(ptr, ptr+out);
    output();
}
int readIn(){
    int i;
    if(scanf("%d",&num)<0)
        return 0;
    out = 0;
    for(i=0; i<num; i++){
        scanf("%d",&dat[i]);
    }
    return num;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

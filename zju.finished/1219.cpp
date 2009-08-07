#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 16,
    MSK = (1<<SIZ) - 1,
};

char buf[100];
int ptr[MSK+10], num;

void fun(){
    if(num==0){
        printf("No pizza can satisfy these requests.\n");
    } else {
        printf("Toppings: ");
        int i,j, ans=ptr[0];
        for (i=0,j=1; i<SIZ; ++i, j<<=1){
            if (ans & j){
                putchar('A'+i);
            }
        }
        printf("\n");
    }
}

void parse(char *s, vector<int> &res){
    res.clear();
    int i, v;
    for (i=0; s[i]!=';'; i+=2){
        v = (s[i+1]-'A') + 1;
        if (s[i] == '-'){
            v = -v;
        }
        res.push_back(v);
    }
}

bool mat(int v, vector<int>&pat){
    for (int i=0; i<pat.size(); ++i){
        if (pat[i] > 0 && (v & (1<<(pat[i]-1)))){
            return true;
        } else if(pat[i] < 0 && (v&(1<<(-pat[i]-1)))==0){
            return true;
        }
    }
    return false;
}

int readIn(){
    if(scanf("%s", buf)<0) return 0;
    int i, j;
    
    num = 1<<SIZ;
    for (i=0; i<num; ++i){
        ptr[i] = i;
    }

    vector<int> v;
    while(buf[0]!='.'){
        parse(buf, v);
        j = 0;
        for (i=0; i<num; ++i){
            if (mat(ptr[i], v)){
                ptr[j++] = ptr[i];
            }
        }
        num = j;
        scanf("%s", buf);
    }
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}


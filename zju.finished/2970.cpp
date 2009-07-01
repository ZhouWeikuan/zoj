#include<iostream>
#include<cstring>
using namespace std;

char buf[20];

int Minest(){
    int n;
    int a, b;
    scanf("%d ", &n);
    for (int i=0; i<n; i++){
        scanf("%d ", &b);
        if ( i==0){
            a = b;
        } else {
            a = min(a, b);
        }
    }
    return a;
}

int Maxest(){
    int n;
    int a, b;
    scanf("%d ", &n);
    for (int i=0; i<n; i++){
        scanf("%d ", &b);
        if ( i==0){
            a = b;
        } else {
            a = max(a, b);
        }
    }
    return a;
}

int main(){
    int n;
    scanf("%d ", &n);
    while(n--){
        scanf("%s", buf);
        int t;
        if (strcmp(buf, "Faster")==0){
            t = Minest();
        } else {
            t = Maxest();
        }
        printf("%d\n", t);
    }

    return 0;
}


#include<iostream>
#include<map>
#include<string>
using namespace std;
enum {
    SIZ = 20,
};
int sum;
char dat[SIZ];
map<int, int> tab;

void insert(int a, int b){
    tab.insert(make_pair(a,b));
}

void removeLast(){
    int i, s;
    for (i=0; i<10; ++i){
        s = sum - i;
        if (s%11 == 0){
            s /= 11;
            if (s <=0) continue;
            insert(s*10+i, s);
        }
    }
}

void removeFirst(){
    int i, u=10, s=sum, v;
    s /= 10;
    while(s>=10){
        u *= 10;
        s /= 10;
    }
    for(i=1; i<=s; ++i){
        v = (sum - i * u)/2;
        if (v >= u) continue;
        insert(i*u+v, v);
    }
}

void removePos(int unit){
    int s = sum / unit;
    int a = s % 11;
    int x = s / 11;
    int v = (sum % unit)/2;
    if (a < 10)
        insert(x*10*unit+a*unit+v, x*unit+v);
    if (a <= 0) return;
    --a;
    v = (sum%unit + unit)/2;
    if (v < unit){
        insert(x*10*unit+a*unit+v, x*unit+v);
    }
}

void fun(){
    tab.clear();
    if (sum % 2 == 0){
        removeFirst();
        for (int u=10; sum/u>=10; u*=10){
            removePos(u);
        }
    }
    removeLast();
}

void output(){
    printf("%d\n", tab.size());
    sprintf(dat, "%d", sum);
    for(map<int,int>::iterator it=tab.begin();
            it!=tab.end(); ++it){
        sprintf(dat, "%d", it->first);
        string a(dat);
        sprintf(dat, "%d", it->second);
        string b(dat);
        while(b.length()+1<a.length())
            b = "0" + b;
        printf("%s + %s = %d\n", a.c_str(),
                b.c_str(), sum);
    }
}

int main(){
    int tst;
    scanf("%d", &tst);
    // tst = 1;
    while(tst--){
        scanf("%d", &sum);
        fun();
        output();
        if (tst)
            printf("\n");
    }

    return 0;
}


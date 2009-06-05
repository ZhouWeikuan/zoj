#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 20,
};
int pl[SIZ] = {2, 3};
int pn = 2;
map<int, double> tab[SIZ];

double best(int i, int v){
    if(v < 0) return 0;
    if(v <= 1) return 1;
    if(i >= pn) return 1;
    map<int,double>::iterator it=tab[i].find(v);
    if(it != tab[i].end())
        return it->second;
    double b, tmp;
    b = best(i+1, v);
    for(int t=pl[i]; t<=v; t*=pl[i]){
        tmp = t*best(i+1, v-t);
        b = max(tmp, b);
    }
    tab[i].insert(make_pair(v, b));
    return b;
}

void init(){
    bool flag;
    int i,j;
    double ret = 6;
	for(i=5; ; i+=2){
        flag = true;
		for(j=0; pl[j]*pl[j]<=i; j++){
			if(i%pl[j]==0){
                flag = false;
				break;
			}
		}
		if(flag){
			pl[pn++] = i;
            ret *= i;
		}
        if(pn >= SIZ)
            break;
	}
}

void fun(int v){
    printf("%.0lf\n", best(0,v));
}

int main(){
    init();
    int t;
    while(cin>>t){
        fun(t);
    }
    return 0;
}


#include<iostream>
#include<queue>

using namespace std;
enum {
    SIZ = 10000,
};
int from, to;
int tab[SIZ];
int array[4] = {1,10,100,1000 };

int dec(int v, int p){
    int t = v / array[p];
    t %= 10;
    int n = t -1;
    if(n <= 0)
        n = 9;
    v -= t * array[p];
    v += n * array[p];
    return v;
}

int inc(int v, int p){
    int t = v / array[p];
    t %= 10;
    int n = t + 1;
    if(n >= 10)
        n = 1;
    v -= t * array[p];
    v += n * array[p];
    return v;
}

int swap_val(int v, int p1, int p2){
    int t = v / array[p1];
    t %= 10;
    int n = v / array[p2];
    n %= 10;
    v -= t * array[p1]; v -= n * array[p2];
    v += t * array[p2]; v += n * array[p1];
    return v;
}

int fun(){
    memset(tab, -1, sizeof(tab));
    queue<int> q;
    tab[from] = 0;
    q.push(from);
    
    int cur,next,i;
    while(tab[to] < 0 ){
        cur = q.front(); q.pop();
        for(i=0;i<4;i++){
            next = dec(cur, i);
            if(tab[next] < 0){
                tab[next] = tab[cur] + 1;
                q.push(next);
            }
            next = inc(cur, i);
            if(tab[next] < 0){
                tab[next] = tab[cur] + 1;
                q.push(next);
            }
        }
        for(i=0;i<3;i++){
            next = swap_val(cur, i, i+1);
            if(tab[next] < 0){
                tab[next] = tab[cur] + 1;
                q.push(next);
            }
        }
    }
    return tab[to];
}

int main(){
	int tstcase;
	cin>>tstcase;

	while(tstcase --){
        cin>>from>>to;
        cout<<fun()<<endl;
	}
	
	return 0;
}

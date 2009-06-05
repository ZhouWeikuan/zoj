#include<iostream>
/*
	从网上得知N>= 50时必定有解。
	代码是从 http://blog.programfan.com/article.asp?id=17099 拷贝来的
	我自己本来写了一个步数推算的代码，计算每个M所需的最小N数，但提交时结果却不对。

	现在这个版本终于对了:)
*/
using namespace std;
enum {
    SIZ = 51,
};
int tree[SIZ];
int N,M;

void calc(int cur, int lim, int count){
    int t;
    if(tree[cur] > lim)
        tree[cur] = lim;
    t = cur + count;
    if(t < SIZ){
        calc(t, lim<t?t:lim, count+2);
    }
    t = cur - count;
    if(t > 0){
        calc(t, lim, count+2);
    }
}

int main(){
    const char *good="Let me try!";
    const char *bad ="Don't make fun of me!";
    for(int i=0;i<SIZ;i++)
        tree[i] = SIZ;
    calc(1,1,3);

    cin>>N>>M;
    while(M + N){
        int t = 0;
        if(N >= SIZ)
            t = 1;
        else {
            if(tree[M] <= N){
                t = 1;
            }
        }
        if(t){
            cout<<good<<endl;
        } else {
            cout<<bad<<endl;
        }
        cin>>N>>M;
    }

	return 0;
}

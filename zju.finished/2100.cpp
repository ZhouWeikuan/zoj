#include<iostream>

// DFS，一开始我还以为有什么好的方法..
using namespace std;
enum {
    None = 0,
    Stone = 1,
    Occupy = 2,
};
int fld[8][8]; 
int N,M,sum,top;
const char *ans[2] = {
	"NO",
	"YES"
};

int fun(int a, int b){
	fld[a][b] = Occupy;
    if(++top == sum){
        return 1;
    }
	if(a>0 && fld[a-1][b]== None){
		if(fun(a-1,b))
			return 1;
	}
	if(b >0 && fld[a][b-1]== None){
		if(fun(a,b-1)){
			return 1;
		}
	}
	if(a < N-1 && fld[a+1][b] == None){
		if(fun(a+1,b)){
			return 1;
		}
	}
	if(b < M-1 && fld[a][b+1] == None){
		if(fun(a,b+1)){
			return 1;
		}
	}
	fld[a][b] = None;
    --top;
	return 0;
}

int main(){
	int i,j;
	char ch;
	bool ret;
	cin>>N>>M;
	while(N + M	){
		sum = N * M;
		ret = false;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				cin>>ch;
				if(ch == 'S'){
					fld[i][j] = Stone;
					sum --;
				} else {
					fld[i][j] = None;
				}
			}
		}
        top = 0;
        ret = (fld[0][0] ==0&&fun(0,0));
		printf("%s\n", ans[ret]);

		cin>>N>>M;
	}

	return 0;
}

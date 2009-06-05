#include<iostream>

using namespace std;
int sum, num;
struct Node{
	int value;
	int count;
    bool operator<(const Node&rhs) const {
        return value>rhs.value;
    }
};

Node cards[12];
int mat[11][1001];

int fun(){
    int i,j,t,k;
    memset(mat, 0, sizeof(mat));
    for(j=0;j<=cards[0].count;j++){
        t = j * cards[0].value;
        if(t > sum)
            break;
        mat[0][t] = 1;
    }
    for(i=1;i<num;i++){
        for(j=0;j<=cards[i].count;j++){
            t = j * cards[i].value;
            for(k=0;k<=sum;k++){
                if(k + t > sum)
                    break;
                mat[i][k+t] += mat[i-1][k];
            }
        }
    }
    return mat[num-1][sum];
}

int main(){
    int i;
    int tstcase = 0;
    
    while(cin>>sum>>num){
		if(tstcase ++)
			printf("\n");
		for(i=0;i<num;i++){
            cin>>cards[i].value>>cards[i].count;
		}
        sort(cards, cards+num);
        i = fun();
        cout<<i<<endl;
	}
    
    return 0;
}

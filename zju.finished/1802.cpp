#include<iostream>
#include<cmath>
// 这不是最大团问题:)
enum {
    MaxN = 16,
};
using namespace std;

int  num, maxValue;
int  path[MaxN][MaxN];
double pos[MaxN][2];
const double eps = 1e-12;
int mark[MaxN];
int freq[MaxN];

void fun(){
    memset(freq, 0, sizeof(freq));
    int i,j;
    for(i=0; i<num; i++){
        memset(mark, 0, sizeof(mark));
        for(j=0; j<num; j++){
            if(path[i][j]==1&&freq[j]&&mark[freq[j]] == 0){
                mark[freq[j]] = 1;
            }
        }
        for(j=1; mark[j]!=0; j++)
            ;
        freq[i] = j;
        if(maxValue < j) maxValue = j;
    }
}
inline double getDis(int a, int b){
    double t = pos[a][0] - pos[b][0];
    t *= t;
    t += (pos[a][1] - pos[b][1])*(pos[a][1] - pos[b][1]);
    return sqrt(t);
}
void readIn(){
    int i,j;
    for(i=0;i<num;i++){
        cin>>pos[i][0]>>pos[i][1];
    }
    double d;
    for(i=0;i<num;i++){
        path[i][i] = 0;
        for(j=i+1;j<num;j++){
            path[i][j] = path[j][i] = (getDis(i,j)<=20+eps);
        }
    }
}
int main()
{
    int tstcase = 0;
    cin>>num;
    while (num > 0)
    {
        maxValue = 1;
        readIn();
        fun();
        tstcase++;
        cout<<"The towers in case "<<tstcase
            <<" can be covered in "<<maxValue
            <<" frequencies."<<endl;
        cin>>num;
    }
    return 0;
}


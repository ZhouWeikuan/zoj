#include<iostream>
#include<map>


//������ѣ���ȷ�Ϻ���ܷŵ���ɳ����� 
using namespace std;
enum {
    SIZ = 204,
};
int N,K;
int cost[SIZ][SIZ];
int dis[SIZ];
map<int,int> tab;
map<int,int>::iterator iter;

int compute(int a, int b){
    int mid = (a+b)/2;
    int ret = 0,t;
    for(int i=a;i<=b;i++){
        t = dis[i] - dis[mid];
        if(t < 0)
            t = -t;
        ret += t;
    }
    return ret;
}
int calc(int n, int k){
    int key = (n<<8) + k;
    iter = tab.find(key);
    if(iter != tab.end()){
        return iter->second;
    }
    if(k==1){
        return cost[0][n];
    }
    int cur,save = 99999999;
    for(int i=n;i>=k-1;i--){
        cur = calc(i-1,k-1) + cost[i][n];
        if(cur < save)
            save = cur;
    }
    return tab[key] = save;
}

int fun(){
    int i,j;
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            cost[i][j] = compute(i,j);
        }
    }
    tab.clear();
    return calc(N-1,K);
}

int main(){
    int tstcase = 0;
    cin>>N>>K;
    while(N){
        cout<<"Chain "<<++tstcase
            <<"\nTotal distance sum = ";
        for(int i=0;i<N;i++){
            cin>>dis[i];
        }
        cout<<fun() <<endl<<endl;

        cin>>N>>K;
    }

	return 0;
}


/*
zoj1196_Fast Food

zju1196_Fast Food 解体报告

译题：zju 1196 fast food 修仓库

有一个公司,在一条街上有N个快餐店,公司决定修K个仓库以满足这些快餐电的原料需求.

现在给出N个快餐店的横坐标(他们都在一条直线上面),要求修K个仓库,使得所有的快餐店离其对应的仓库的距离最短.

公式如下:


1 <= n <= 200, 1 <= k <= 30, k <= n

Sample Input

6 3
5
6
12
19
20
27
0 0

Sample Output

Chain 1
Total distance sum = 8
每个输出之后打一个空行

*********************************************************************************************************

相当经典的一道题。。

设 F[ i , j ] 表示前 i  个快餐店修 j  个仓库的最小 distant ：

则 F[ i , j ]=F[ k , j-1 ] + cost[ k+1 , i ]   { k>=j-1, k+1<=i}

其中 Cost[ i, j ] 表示第 i  个餐厅到第 j 个餐厅间插 1 个仓库的最小 distant， 等于所有餐厅到第 (i+j+1)div 2  个餐厅的distant 之和。

1) F[i , 1] 初值即为 Cost[ 1, i];

2) Cost[i , j] 可提前算出以加快效率；

附AC代码：

program zju1196;

const maxnA=200;
      maxnB=30;
var f:array[1..maxnA,1..maxnB]of longint;
    cost:array[1..maxnA,1..maxnA]of longint;
    d:array[1..maxnA]of longint;
    i,j,p,n,k,index,tmp:longint;

function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;

function data(x,y:longint):longint;
var i,mid,sum:longint;
begin
  mid:=(x+y+1)div 2;
  sum:=0;
  for i:=x to y do
    sum:=sum+abs(d[i]-d[mid]);
  data:=sum;
end;

begin
  n:=1; k:=1; index:=0;
  while (n<>0)or(k<>0) do begin
    fillchar(f,sizeof(f),0);
    fillchar(cost,sizeof(cost),0);
    read(n,k);
    readln;
    if (n=0)and(k=0) then break;
    for i:=1 to n do readln(d[i]);
    for i:=1 to n-1 do
      for j:=i+1 to n do cost[i,j]:=data(i,j);
    for i:=1 to n do f[i,1]:=cost[1,i];
    for i:=1 to n do
      for j:=2 to k do
        if j<i then begin
          tmp:=maxlongint;
          for p:=j to i do tmp:=min(cost[p,i]+f[p-1,j-1],tmp);
          if tmp<maxlongint then f[i,j]:=tmp;
        end;
    inc(index);
    writeln('Chain ',index);
    writeln('Total distance sum = ',f[n,k]);
    writeln;
  end;
end.
*/

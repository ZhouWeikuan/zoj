//对于这道题目，首先把程序转化为机语言，这里由于机器语言只有种，所以用结构体表示
//然后用规划的方法来求出他的值
//据刘汝佳的书上说，寄存器没有使用同一个，而是使用不同的寄存器


#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

#define MAX 101

double d[MAX][MAX];
double R[4][MAX][MAX];
double v[10][MAX][MAX];
char in[21];
int x;
int pos;

struct Node
{
int kind;    //kind就是机器语言的种类
int s1;      //s1是指令的第一个数
int s2;      //s2是指令的第二个数
};

//kind分为5种，1---3为MOV指令，1表示第二个数为符号，2表示数字,而且前面的数为寄存器
//3表示前面的数为变量，后面的是寄存器
//4为add指令，5为sub指令，因为指令的第一个和第二个数为固定的，表示R1和R2

Node code[2][MAX];
int codelen[2];

typedef map<string,int> st;
st Tree;

int StringToInt(string &temp)
{
int num = 0 , i;
int len = temp.size();
int power = 1;
for(i = len-1;i >= 0;--i)
{
  num += (temp[i] - '0') * power;
  power *= 10;
}
return num;
}

void change(char *t)
{
int i = 0;
while(t[i] != 0)
{
  if(t[i] >= 'a' && t[i] <= 'z')
   t[i] = t[i]+'A'-'a';
  ++i;
}
}

void input()
{
string temp;
Node now;
st::iterator Ite;
char p;
pos = 0;
int result;
int len = 0;
codelen[x] = 1;
memset(in,0,sizeof(in));
cin.get(p);
while( p != ':' && p != ' ' && p != '\n')
{
  in[len++] = p;
  cin.get(p);
}
change(in);
//in[len] = '\n';
//temp.assign(in);
while(strcmp(in,"END") != 0)
{
  //in[len] = '\n';
  temp.assign(in);
  Ite = Tree.find(temp);
  if(Ite == Tree.end())
  {
   Tree.insert(make_pair(temp,pos));
   pos++;
   now.kind = 3;
   now.s1 = pos-1;
   now.s2 = 2*x;
   code[x][codelen[x]+3] = now;
  }
  else
  {
   now.kind = 3;
   now.s1 = Ite->second;
   now.s2 = 2*x;
   code[x][codelen[x]+3] = now;
  }
  cin >> p;
  while(p == ':' || p == '=')
   cin >> p;
  len = 0;
  memset(in,0,sizeof(in));
  if(p >= '0' && p <= '9') //是数字
  {
   in[len++] = p;
   cin >> p;
   while(p != '+' && p != '-')
   {
    in[len++] = p;
    cin >> p;
   }
   //len--;
   //in[len] = "";
   //in[len] = '\n';
   temp.assign(in);
   result = StringToInt(temp);
   now.kind = 2;
   now.s1 = 2*x;
   now.s2 = result;
   code[x][codelen[x]] = now;
  }
  else
  {
   in[len++] = p;
   cin >> p;
   while(p != '+' && p != '-')
   {
    in[len++] = p;
    cin >> p;
   }
   change(in);
   //in[len] = '\n';
   temp.assign(in);
   Ite = Tree.find(in);
   if(Ite == Tree.end())
   {
    Tree.insert(make_pair(temp,pos));
    pos++;
    now.kind = 1;
    now.s1 = 2*x;
    now.s2 = pos-1;
    code[x][codelen[x]] = now;
   }
   else
   {
    now.kind = 1;
    now.s1 = 2*x;
    now.s2 = Ite->second;
    code[x][codelen[x]] = now;
   }
  }
  if(p == '+')
  {
   now.kind = 4;
   now.s1 = 2*x;
   now.s2 = 2*x+1;
   code[x][codelen[x]+2] = now;
  }
  else
  {
   now.kind = 5;
   now.s1 = 2*x;
   now.s2 = 2*x+1;
   code[x][codelen[x]+2] = now;
  }
  cin >> p;
  len = 0;
  memset(in,0,sizeof(in));
  if(p >= '0' && p <= '9') //是数字
  {
   in[len++] = p;
   cin.get(p);
   while(p != '\n' )
   {
    in[len++] = p;
    cin.get(p);
   }
   //len--;
   //in[len] = '';;
   //in[len] = '\n';
   temp.assign(in);
   result = StringToInt(temp);
   now.kind = 2;
   now.s1 = 2*x+1;
   now.s2 = result;
   code[x][codelen[x]+1] = now;
  }
  else
  {
   in[len++] = p;
   cin.get(p);
   while(p != '\n')
   {
    in[len++] = p;
    cin.get(p);
   }
   change(in);
   //in[len] = '\n';
   temp.assign(in);
   Ite = Tree.find(in);
   if(Ite == Tree.end())
   {
    Tree.insert(make_pair(temp,pos));
    pos++;
    now.kind = 1;
    now.s1 = 2*x+1;
    now.s2 = pos-1;
    code[x][codelen[x]+1] = now;
   }
   else
   {
    now.kind = 1;
    now.s1 = 2*x+1;
    now.s2 = Ite->second;
    code[x][codelen[x]+1] = now;
   }
  }
  codelen[x] += 4;
  cin.get(p);
  len = 0;
  memset(in,0,sizeof(in));
  while( p != ':' && p != ' ' && p != '\n')
  {
   in[len++] = p;
   cin.get(p);
  }
  //in[len] = '\n';
  //temp.assign(in);
}
}

void cal()
{
int l,m,n,k;
int i,j;
memset(d,0,sizeof(d));
memset(v,0,sizeof(v));
memset(R,0,sizeof(R));
  d[0][0] = 1;
  for(i = 0;i < codelen[0];++i)
   for(j = 0;j < codelen[1];++j)
   {
    if( i != 0)
     d[i][j] += d[i-1][j];
    if(j != 0)
     d[i][j] += d[i][j-1];
    if(i != 0)
    {
     l = code[0][i].kind;
     m = code[0][i].s1;
     n = code[0][i].s2;
     switch(l)
     {
     case 1:
      R[m][i][j] += v[n][i-1][j]*d[i-1][j]/d[i][j];
      for(k = 0;k < 4;++k)
      {
       if(k != m)
        R[k][i][j] += R[k][i-1][j]*d[i-1][j]/d[i][j];
      }
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i-1][j]*d[i-1][j]/d[i][j];
      break;
     case 2:
      R[m][i][j] += n*d[i-1][j]/d[i][j];
      for(k = 0;k < 4;++k)
      {
       if(k != m)
        R[k][i][j] += R[k][i-1][j]*d[i-1][j]/d[i][j];
      }
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i-1][j]*d[i-1][j]/d[i][j];
      break;
     case 3:
      v[m][i][j] += R[0][i-1][j]*d[i-1][j]/d[i][j];
      for(k = 0;k < 4;++k)
       R[k][i][j] += R[k][i-1][j]*d[i-1][j]/d[i][j];
      for(k = 0;k < 10;++k)
      {
       if(k != m)
        v[k][i][j] += v[k][i-1][j]*d[i-1][j]/d[i][j];
      }
      break;
     case 4:
      R[0][i][j] += (R[0][i-1][j]+R[1][i-1][j])*d[i-1][j]/d[i][j];
      for(k = 1;k < 4;++k)
       R[k][i][j] += R[k][i-1][j]*d[i-1][j]/d[i][j];
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i-1][j]*d[i-1][j]/d[i][j];
      break;
     case 5:
      R[0][i][j] += (R[0][i-1][j]-R[1][i-1][j])*d[i-1][j]/d[i][j];
      for(k = 1;k < 4;++k)
       R[k][i][j] += R[k][i-1][j]*d[i-1][j]/d[i][j];
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i-1][j]*d[i-1][j]/d[i][j];
      break;
     }
    }
    if(j != 0)
    {
     l = code[1][j].kind;
     m = code[1][j].s1;
     n = code[1][j].s2;
     switch(l)
     {
     case 1:
      R[m][i][j] += v[n][i][j-1]*d[i][j-1]/d[i][j];
      for(k = 0;k < 4;++k)
      {
       if(k != m)
        R[k][i][j] += R[k][i][j-1]*d[i][j-1]/d[i][j];
      }
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i][j-1]*d[i][j-1]/d[i][j];
      break;
     case 2:
      R[m][i][j] += n*d[i][j-1]/d[i][j];
      for(k = 0;k < 4;++k)
      {
       if(k != m)
        R[k][i][j] += R[k][i][j-1]*d[i][j-1]/d[i][j];
      }
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i][j-1]*d[i][j-1]/d[i][j];
      break;
     case 3:
      v[m][i][j] += R[2][i][j-1]*d[i][j-1]/d[i][j];
      for(k = 0;k < 4;++k)
       R[k][i][j] += R[k][i][j-1]*d[i][j-1]/d[i][j];
      for(k = 0;k < 10;++k)
       if(k != m)
        v[k][i][j] += v[k][i][j-1]*d[i][j-1]/d[i][j];
       break;
     case 4:
      R[2][i][j] += (R[2][i][j-1]+R[3][i][j-1])*d[i][j-1]/d[i][j];
      R[0][i][j] += R[0][i][j-1]*d[i][j-1]/d[i][j];
      R[1][i][j] += R[1][i][j-1]*d[i][j-1]/d[i][j];
      R[3][i][j] += R[3][i][j-1]*d[i][j-1]/d[i][j];
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i][j-1]*d[i][j-1]/d[i][j];
      break;
     case 5:
      R[0][i][j] += R[0][i][j-1]*d[i][j-1]/d[i][j];
      R[1][i][j] += R[1][i][j-1]*d[i][j-1]/d[i][j];
      R[2][i][j] += (R[2][i][j-1]-R[3][i][j-1])*d[i][j-1]/d[i][j];
      R[3][i][j] += R[3][i][j-1]*d[i][j-1]/d[i][j];
      for(k = 0;k < 10;++k)
       v[k][i][j] += v[k][i][j-1]*d[i][j-1]/d[i][j];
      break;
     }
    }
  }
}

int main()
{
int tests;
int i,j;
cin >> tests;
cin.get();
int pos;
for(i = 0;i < tests;++i)
{
  Tree.clear();
  pos = 0;
  x = 0;
  input();
  x = 1;
  input();
  cal();
  st::iterator p;
  int s;
  for(p = Tree.begin();p != Tree.end();++p)
  {
   s = p->second;
   cout.setf(ios::fixed);
   cout << setprecision(4);
   cout << v[s][codelen[0]-1][codelen[1]-1]<<endl;
  }
}
return 0;
}

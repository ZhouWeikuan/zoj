#include<iostream>
#include<set>
#include<string>
/* 程序很简单， 但要注意理解题意。 */
using namespace std;

enum {
    SIZ = 240,
};
char s1[SIZ/2];
char s2[SIZ/2];
char buf[SIZ];
char tar[SIZ];
int num;
set<string> tab;

void unite(){
    int i,j;
    for(i=0,j=0;i<num;i++,j+=2){
        buf[j] = s2[i];
    }
    for(i=0, j=1;i<num; i++,j+=2){
        buf[j] = s1[i];
    }

    buf[num * 2] = 0;
}
void split(){
    int i,j;
    for(i=0;i<num;i++){
        s1[i] = buf[i];
    }
    for(i=0,j=num;i<num;i++,j++){
        s2[i] = buf[j];
    }

    s1[num] = s2[num] = 0;
}

void fun(){
    int step = 0;
    tab.clear();
    while(1){
        unite();
        step ++;

        string s(buf);
        if(s == tar){
            cout<<step<<endl;
            return;
        }
        if(tab.find(s)!=tab.end()){
            break;
        }
        tab.insert(s);

        split();
    }

    cout<<-1<<endl;
}

int main(){
    int tstcase;
    int inc = 0;
    cin>>tstcase;
    while(tstcase --){
        cin>>num;
        cin>>s1>>s2;
        cin>>tar;
        cout<<++inc<<" ";

        fun();
    }

	return 0;
}

/*

ZJU2774

题目要求：

有两组个数相同（C）的筹码S1和S2，可对其进行两种操作：

     1、合并：最底放s2的底牌，上面放s1的底牌，再上面放s2的次底牌……依次交叉排列，形成组合s12。

     2、拆分：将s12的下面c个筹码取出作为新的s1，上面的c个筹码作为新的s2。

题目给出最初的s1和s2的颜色排列及目标s12的颜色排列，求第一次出现目标颜色排列所需要经过的操作次数（以合并为标准），若无法达到目标颜色排列则输出-1。

Sample Input

24
AHAH
HAHA
HHAAAAHH
3
CDE
CDE
EEDDCC

Sample Output

1 2
2 -1

解题思路：

     根据题意，很容易可以得出目标排列前一步时的s1，s2情况。记此时的s1为ch，若ch与最初的s1相同，则步数为1。若不同则进行上述的合并、拆分操作，并将每次形成的新的s1排列记录下来，若经过i次操作后可得到与ch相同的s1，那么步数为i+1；若进行操作的过程中出现生成的s1已经存在的情况则说明不可能达到目标排列，输出-1（因为n个砝码的排列一定是有限的，所以s1不会出现无限不循环的情况，当s1与前面某一个重复的时候就说明它进入了死循环）。

程序代码：

#include<stdio.h>

#include<string.h>

char s1[100],s2[100],s12[200];

char str[1000][100],ch[100];

void shu(int c)               //进行合并、拆分操作

{

    int i,j;

    for(i=0,j=0;i<c;i++,j=j+2)

        s12[j]=s2[i];

    for(i=0,j=1;i<c;i++,j=j+2)

        s12[j]=s1[i];

    for(i=0;i<c;i++){

        s1[i]=s12[i];

        s2[i]=s12[i+c];

    }

}

int have(int n)                     //判断新生成的s1是否已经存在

{

    int i;

    for(i=0;i<n;i++)

       if(strcmp(s1,str[i])==0)

          return 1;

    return 0;

}

int main()

{

    int n,c;

    int ca;

    int i,j;

    for(scanf("%d",&n),ca=1;ca<=n;ca++){

        memset(str,0,sizeof(str));

        memset(ch,0,sizeof(ch));

        scanf("%d",&c);

        scanf("%s",s1);

        scanf("%s",s2);

        scanf("%s",s12);

        strcpy(str[0],s1);

        for(i=0,j=1;i<c;i++,j=j+2)

           ch[i]=s12[j];

        if(strcmp(ch,s1)==0)

        {

            printf("%d 1\n",ca);

            continue;

        }

        i=1;

        while(1){

            shu(c);

            if(strcmp(ch,s1)!=0){

               if(have(i+1)==0)

                  strcpy(str[i++],s1);

               else{

                  printf("%d -1\n",ca);

                  break;

               }

            }

            else if(strcmp(ch,s1)==0){

                printf("%d %d\n",ca,i+1);

                break;

             }

        }

        continue;

    }

}
*/


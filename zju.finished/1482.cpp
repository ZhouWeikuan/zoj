#include<cstdio>

using namespace std;
int N;
int mat[3008];

void fun(){
    int i,j,k,t;
    int used = 1, ans = 0;
    for(i=0;i<=N;i++){
        mat[i] = 0;
    }
    for(i=0;i<N;i++){
        for(j=1;j<=N;j++){
            scanf("%d ",&t);
            if(t == 1){
                mat[j] = 0;
                continue;
            }
            if(mat[j] == mat[j-1]){
                if(mat[j] ==0){
                    mat[j] = used ++;
                    ans ++;
                }
                continue;
            } 
            if(mat[j] == 0){
                mat[j] = mat[j-1];
            } else if(mat[j-1] ==0){
                ;
            } else { // diff colors, look as the left
                ans --;
                for(t=1;t<=N;t++){
                    if(t == j)
                        continue;
                    if(mat[t] == mat[j])
                        mat[t] = mat[j-1];
                }
                mat[j] = mat[j-1];
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    
    while(scanf("%d ",&N) > 0){
        fun();
    }
	return 0;
}


/*
一．题目描述：

一个蛮有意思的题，因为他限制内存。题目给出一个由0-1组成的矩阵，其中1用来描述障碍，0描述未占空间。于是，某些未占空间可以被认为是相连的，如果其中一个在另一个的上，下，左或右。

要求：给出矩阵的大小（0<N<=3000）和他的描述，问在这个矩阵中有多少不相连的未为占空间；

二．解题思路：

如果不考虑内存，那么这个题会变的很简单。我们首先用一个二维数组保存下整个矩阵，然后扫描，碰到0就开始一次深度搜索或宽度搜索，那么深度搜索或宽度搜索被调用的次数就是分区的数量。

但是因为内存限制的缘故，我们不得不另寻他法。我们是否可以通过只保存几行或者一行，然后对一些特征进行判断从而解决问题呢？

我们用着色的思路来进行，为防止标号重复带来的冲突，我们使标号单调递增。即：假设当前有三个空间分别被着色1，2，3，那么即使空间1和2在某处合并了，我们就用1或2继续保持对他们整体的标号，而那个被放弃的标号以后也不会用到，如果有一个新的空间，他将被标记4。

我们用ans表示空间数，max表示当前用到的最大标号；矩阵中相连的未占空间将做相同标号。越界部分也假想成障碍。考察一个数左边和上面的两个数的状况，那么就会有如下几种情况：

1） Up=M && Left=M à那么假设当前出现的是新的分区，着色（max+1）同时max++，ans++;

2）Up=M && Left=num[left]à说明当前的数可以和左边相连，着色num[left]。

3）Up=num[up] && Left=Mà当前数和上面相连，那么着色num[up];

4)  Up=num[up] && Left=num[left] 这样又有两种情况

[1]   num[up]=num[left]à上面和左边就属于相同分区,着色num[up] ( num[left] )；

       [2] num[up]!=num[left]à上面和左边是不同分区，并且在当前点合并，那么ans--,同时

              我们得改变num[left]使得他们等于num[up], 或者相反；

在上面的描述中，可以认为我们只用到了两个行。但是实际处理时，我们只需要一行。用一个例子来说明：

试一下下面这个简单的矩阵；（用Mà1来表示障碍）

（M）（M）（M）（M）（M）

（M）M   0   M    0

（M）M   0   0     0

（M） 0   M  0     0

        (M )  0   0   0     0

假定我们只有一保存一行，每次读入一个数对当前位置进行更新：

       初始：M M M M                      ans=0,max=0;

       读入第一行：M 1 M 2              ans=2,max=2;

       读入第二行：M 1 1 (X)      

              因为1和2在(2,4)出交汇。所以我们更新所有标记1的点成为2,

       得到：M 2 2 2                                  ans=1,max=2;

       读入第三行：3 M 2 2                 ans=2,max=3;

       读入第四行：3 3（X）（）

              3和2在（4，3）处交汇，所以我们更新所有标记3的点成为2,

       得到：3 3 2 （）

       继续读入：2 2 2 2                     ans=1,max=3;

最后ans所保持的数就是结果；

三．我的代码：

以下内容为程序代码:

#include<stdio.h>

#define MAX 999999999

#define SIZE 3001

int main(  ){

    int i,j,k;

    int n;

    int line[SIZE];

    int num,hold;

    int max,ans;

    while( scanf("%d",&n)!=EOF ){

        for( i=0;i<=n;i++ )

            line[i]=MAX;

        ans=0;max=0;

        for( i=0;i<n;i++ ){

            for( j=1;j<=n;j++ ){

                scanf("%d",&num);

                if( num==1 )    line[j]=MAX;

                else{

                    if( line[j]==MAX && line[j-1]==MAX ){   //假定当前这点是新的点

                        max++;

                        line[j]=max;

                        ans++;

                    }//end if

                    else if( line[j]==MAX && line[j-1]!=MAX )

                        line[j]=line[j-1];

                    else if( line[j-1]==MAX && line[j]!=MAX )

                        continue;

                    else{                                   //两个都是数的情况；

                        if( line[j-1]==line[j] )    continue;

                        else{                               //合并不同分区；

                            hold=line[j];

                            for( k=1;k<=n;k++ )

                                if( line[k]==hold )  line[k]=line[j-1];

                            ans--;

                        }

                    }//end else

                }//end else

            }//end for( j )

        }

        printf("%d\n",ans);

    }//end while

    return 0;

}
*/

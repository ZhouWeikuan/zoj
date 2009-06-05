/*[Spot - Puff] = s ([n] 代表不大于n的整数）

=> Puff < Spot - s - 1, Puff >= Spot - s

同理得：Spot <= Yertle < Spot - y - 1

又Spot + Puff + Yertle = j + d

=>  3Spot <= j + d < 3Spot - s - y - 2  

=>  (d + j + s + y) / 3 <= Spot < (d + j + s + y + 2) / 3

其余同上

*/

#include<stdio.h>
int main ()
{
   int Spot , Puff , Yertle;
   int s , p , y , j , d = 12;

   while ( scanf ( "%d%d%d%d" , &s , &p , &y , &j ) != EOF )
   {
      Spot = ( d + j + s + y + 2 ) / 3;
      Puff = ( d + j + p - s + 1 ) / 3;
      Yertle = ( d + j - p - y + 0 ) / 3;
      printf ( "%d %d %d\n" , Spot , Puff , Yertle );
   }
   return 0 ;
}

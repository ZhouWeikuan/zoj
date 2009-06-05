#include<iostream>
/*
 * Simplex Algorithm must follow the standard form:
 *  z = max(sum(ai xi))
 *      sum(bixi) <= val
 *    xi >= 0  
 */ 
using namespace std;
enum {
    COL = 10,
    ROW = 10,
};
typedef double Vec[COL];
Vec vec[ROW]; /// the elements are : val, x1, x2, x3, ...
              /// the first row is to calculate the max, so vec[0][0]
              ///     contains the value we want at last.

// find the one with the most positive coefficients
int findLeave()
{
}

// find the one with the tightest value
int selectRow(int l)
{
}

// update other elements in the same row with element l.
void formatRow(int r, int l)
{
}

// replace element l with other elements in other rows
void updateOtherRows(int r, int l)
{
}

void fun(){
    while ( (l=findLeave())!= 0){
        r = selectRow(l);
        formatRow(r, l);
        updateOtherRows(r, l);
    }
}

int readIn(){
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


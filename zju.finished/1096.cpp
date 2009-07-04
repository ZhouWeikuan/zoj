#include<iostream>
#include<cmath>
// Copy a standard solution
using namespace std;
enum {
    SIZ = 104,
};
/*      ta
 *      ---
 *     /   \
 *  tx/     \tx
 *   /       \  tv
 *            -------         -  a at different time
 *            |      \       /
 *            |       \     /
 *            v        \   /
 *          max speed   ---
 */

double D,M,A,J;
double jtime;
double jtimeaccellimit; // the time used to accelerate, e.g. tx in the graph
double jtimespeedlimit; // the time used to reach the maximum speed,
double jtimedistlimit;
double atime;
double dist;
double delta;
double a, 
       b, 
       c, 
       r;

void fun(){
    jtimeaccellimit = A / J;            // A >= J * tx;
    jtimespeedlimit = sqrt(M/J);        // M >= J * tx^2;
    jtimedistlimit = cbrt(D/2.0/J);     // D >= 2 * J * tx^3;
    jtime  = jtimeaccellimit;
    if (jtime > jtimespeedlimit) jtime = jtimespeedlimit;
    if (jtime > jtimedistlimit) jtime = jtimedistlimit;
    atime = (M - J*jtime*jtime)/A;      // M <= J*tx*tx + A*atime
    // A *ta^2 + (2*A*tx + J*tx*tx)*ta + 2*J*tx*tx*tx - D = 0; calc accel time
    a = A/2;
    b = A*jtime + J*jtime*jtime/2;
    c = J*jtime*jtime*jtime - D/2; 
    r = (-b + sqrt(b*b-4*a*c))/2/a;
    if (r < atime) atime = r;

    dist = 2*J*jtime*jtime*jtime 
            + J*jtime*jtime*atime + 2*A*jtime*atime
            + A*atime*atime;
    r = 4 * jtime + 2*atime + (D-dist)/M;
    printf("%.1lf\n", r);
}

int readIn(){
    return scanf("%lf%lf%lf%lf ", &D, &M, &A, &J);
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


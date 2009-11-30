#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-7;

//Compute the dot product AB ⋅ BC
double dot(double A[], double B[], double C[]){
    double AB[2] = {B[0]-A[0], B[1]-A[1]};
    double BC[2] = {C[0]-B[0], C[1]-B[1]};
    double dot = AB[0] * BC[0] + AB[1] * BC[1];
    return dot;
}
//Compute the cross product AB x AC
double cross(double A[], double B[], double C[]){
    double AB[2] = {B[0]-A[0], B[1]-A[1]};
    double AC[2] = {C[0]-A[0], C[1]-A[1]};
    double cross = AB[0] * AC[1] - AB[1] * AC[0];
    return cross;
}
//Compute the distance from A to B
double distance(double A[], double B[]){
    double d1 = A[0] - B[0];
    double d2 = A[1] - B[1];
    return sqrt(d1*d1+d2*d2);
}
//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double linePodoubleDist(double A[], double B[], double C[], bool isSegment){
    double dist = cross(A,B,C) / distance(A,B);
    if(isSegment){
        double dot1 = dot(A,B,C);
        if(dot1 > 0)return distance(B,C);
        double dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return abs(dist);
}

double getArea(double p[][2], int N){
    double area = 0;
    //We will triangulate the polygon
    //doubleo triangles with podoubles p[0],p[i],p[i+1]
    for(int i = 1; i+1<N; i++){
        double x1 = p[i][0] - p[0][0];
        double y1 = p[i][1] - p[0][1];
        double x2 = p[i+1][0] - p[0][0];
        double y2 = p[i+1][1] - p[0][1];
        double cross = x1*y2 - x2*y1;
        area += cross;
    }
    return abs(area/2.0);
}

bool intersectPoint(){
    A = y2-y1;
    B = x1-x2;
    C = A*x1+B*y1;
    A1x + B1y = C1;
    A2x + B2y = C2;
    double det = A1*B2 - A2*B1;
    if(fabs(det) < eps){
        //Lines are parallel
        return false;
    }else{
        double x = (B2*C1 - B1*C2)/det;
        double y = (A1*C2 - A2*C1)/det;
    }
    return true;
}


#include<iostream>
#include<iomanip>
#include<cmath>

/*半径肯定把边都占满，即正好是每两半径正好是边长*/
using namespace std;
struct Point {
    double x;
    double y;
};
Point pnt[3];
double mat[3][3];
double tmp1, tmp2;
double getDis(Point &a, Point &b){
    tmp1 = a.x - b.x;
    tmp2 = a.y - b.y;
    tmp1 *= tmp1;
    tmp2 *= tmp2;
    tmp1 += tmp2;
    tmp1 = sqrt(tmp1);
    return tmp1;
}

int readIn(){
    if(cin>>pnt[0].x>>pnt[0].y){
    } else {
        return 0;
    }

    cin>>pnt[1].x>>pnt[1].y;
    cin>>pnt[2].x>>pnt[2].y;
    int i,j;
    for(i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            mat[i][j] = mat[j][i] = getDis(pnt[i], pnt[j]);
        }
    }
    return 1;
}

void fun(){
    double t[3];
    t[0] = (mat[0][1] + mat[0][2] - mat[1][2])/2;
    t[1] = (mat[0][1] + mat[1][2] - mat[0][2])/2;
    t[2] = (mat[0][2] + mat[1][2] - mat[0][1])/2;
    cout.setf(ios::fixed);
    cout<<setprecision(6)<<t[0]<<endl
        <<setprecision(6)<<t[1]<<endl
        <<setprecision(6)<<t[2]<<endl;
    
}

int main(){
    
    while(readIn()){
        fun();
    }

	return 0;
}

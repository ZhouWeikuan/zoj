#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
const double eps = 1e-5;
const double sqrt2 = 1.0 / sqrt(2.0);
enum {
    N = 0, E = 1, S = 2, W =3,
    NE = 4, SE = 5, SW = 6, NW=7,
};
const char *pos[8] = {
    "N","E","S","W","NE","SE","SW","NW"
};
double move[8][2] = {
    /* N = 0  */ {0, 1.0},
    /* E = 1  */ {1.0, 0},
    /* S = 2  */ {0, -1.0}, 
    /* W = 3  */ {-1.0, 0},
    /* NE = 4 */ {sqrt2, sqrt2},
    /* SE = 5 */ {sqrt2, -sqrt2}, 
    /* SW = 6 */ {-sqrt2, -sqrt2}, 
    /* NW = 7 */ {-sqrt2, sqrt2}
};
char buf[240];
double x,y,d;

void parse(char *s){
    int t = 0, i;
    while(*s <='9' && *s>='0'){
        t *= 10;
        t += *s-'0';
        s ++;
    }
    for(i=0;i<8;i++){
        if(strcmp(s, pos[i]) ==0){
            break;
        }
    }
    x += t * move[i][0];
    y += t * move[i][1];
}

void fun(){
    char *ptr;
    d = x = y = 0.0;
    ptr = strtok(buf, ",.");
    while(ptr != NULL){
        parse(ptr);
        ptr = strtok(NULL,",.");
    }

    if(fabs(x) < eps){
        x = 0;
    }
    if(fabs(y) < eps){
        y = 0;
    }
    d = x*x + y *y;
    d = sqrt(d);
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    cout<<"The treasure is located at ("
        <<x<<","<<y<<")."<<endl
        <<"The distance to the treasure is "
        <<d<<"."<<endl;
}

int main(){
    int tstcase = 0;
    cin.getline(buf, 240);
    while(strcmp(buf,"END") != 0){
        cout<<"Map #"<<++tstcase<<endl;
        fun();
        cout<<endl;
        cin.getline(buf, 240);
    }

	return 0;
}

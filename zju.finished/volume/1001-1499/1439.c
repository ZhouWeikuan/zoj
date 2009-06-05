#include<stdio.h>
#include<math.h>

/*****
    内切圆与外接圆之比为 r/R = (a+b-c)*(a+c-b)*(b+c-a)/ (2*a*b*c)

***/

 double v[3][3];

 double get(int i, int j){
    int k;
     double sum = 0.0,t;
    
    for(k=0;k<3;k++){
        t =v[i][k] - v[j][k];
        t *=t;
        sum += t;
    }
    return sqrt(sum);
}

void fun(){
     double a,b,c;
     double r;
    c = get(0,1);
    b = get(1,2);
    a = get(2,0);    
    
    r = (a+b-c)/a;
    r *= (b+c-a)/b;
    r *= (-b+c+a)/c;
    r /= 2;
    r *= r;
    
    printf("%.3lf\n",r);
}

int main(){
    int i;    
    
    scanf("%lf", &v[0][0]);
    while(!feof(stdin)){
        for(i=1;i<3;i++){
            scanf("%lf", &v[0][i]);
        }
        for(i=1;i<3;i++){
            scanf("%lf %lf %lf", &v[i][0], &v[i][1], &v[i][2]);
        }
        fun();
        scanf("%lf", &v[0][0]);
    }
    return 0;
}

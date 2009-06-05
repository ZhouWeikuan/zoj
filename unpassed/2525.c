#include<stdio.h>
#include<math.h>

#define MaxSize (60)
const double PI = 3.1415927;

typedef double Matrix[3][3];
typedef double Vector[3];
typedef struct {
    double x;
    double y;
    double degree;
} Node ;

int nodenum;
Node vertex[MaxSize];
Matrix mat[MaxSize];

Matrix e = { 1, 0 ,0, 
             0 ,1, 0,
             0 , 0 ,1};
void assign(Matrix *a, Matrix *b){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            (*a)[i][j]  =   (*b)[i][j];
        }
    }
}

void move_from(Matrix *m, double a, double b){
    assign(m,&e);
    (*m)[2][0]  =   -a;
    (*m)[2][1]  =   -b;
}

void rotate(Matrix *m, double degree){
    double c = cos(degree);
    double s = sin(degree);
    assign(m,&e);
    (*m)[0][0] = c;
    (*m)[1][1] = c;
    (*m)[0][1] = s;
    (*m)[1][0] = -s;
}

void move_back(Matrix *m, double a, double b){
    assign(m,&e);
    (*m)[2][0] = a;
    (*m)[2][1] = b;
}

void multiply(Matrix *a, Matrix *b){
    int i,j,k;
    double t;
    static Matrix m;
    assign(&m,a);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            t = 0;
            for(k=0;k<3;k++){
                t += m[i][k] * (*b)[k][j];
            }
            (*a)[i][j] = t;
        }
    }
}

void V_mul_M(Vector *v, Matrix *m){
    int i;
    static Vector nv;
    for(i=0;i<3;i++){
        nv[i] = (*v)[i];
    }
    for(i=0;i<3;i++){
        (*v)[i] = nv[0] * (*m)[0][i];
        (*v)[i] += nv[1] * (*m)[1][i];
        (*v)[i] += nv[2] * (*m)[2][i];
    }
}

void fun(){
    int i;
    Matrix a,b;
    Vector v;
    
    assign(&a,&e);
    
    for(i=0;i<nodenum;i++){
        move_from(&b,vertex[i].x, vertex[i].y);
        multiply(&a,&b);
        rotate(&b,vertex[i].degree);
        multiply(&a,&b);
        move_back(&b,vertex[i].x, vertex[i].y);
        multiply(&a,&b);
        assign(&mat[i],&a);
    }
    for(i =0;i < 3;i++){
        printf("%.2lf %.2lf %.2lf\n", a[i][0], a[i][1], a[i][2]);
    }
    v[0] = a[2][1]*a[1][0]  + a[2][0]*(1-a[1][1]);
	v[0]/= ((1-a[1][1])*(1-a[0][0]) - a[0][1] * a[1][0]);
    
    v[1] = a[0][1] * v[0] + a[2][1]*a[1][0] ;
    v[1] /= (1 - a[1][1]);
    v[2] = 1;    
    
    vertex[0].x = v[0];
    vertex[0].y = v[1];
    
    for(i =0;i < nodenum-1;i++){
        V_mul_M(&v, &mat[i]);
        vertex[i+1].x = v[0];
        vertex[i+1].y = v[1];
		v[0] = vertex[0].x;
		v[1] = vertex[0].y;
		v[2] = 1;
    }    
    for(i=0;i<nodenum;i++){
        printf("%.2lf %.2lf\n", vertex[i].x, vertex[i].y);
    }
}

int main(){
    int testnum = 0;
    int i;
	
    scanf("%d\n", &nodenum);
    while(! feof(stdin)){
        if(testnum !=0){
            printf("\n");
        }
        for(i=0;i<nodenum;i++){
            scanf("%lf %lf", &vertex[i].x, &vertex[i].y);
        }
        for(i=0;i<nodenum;i++){
            scanf("%lf", &vertex[i].degree);
			vertex[i].degree *= PI;
			vertex[i].degree /= 180.0;
        }
        fun();
        scanf("%d\n", &nodenum);
        testnum ++;
    }
    
}

#include<stdio.h>

enum {
    N = 12,
    Row = 2*N+3,
    Col = N+2,
};

int displaysize;
char digit[10][Row][Col];
char buffer[12];
const char HorChar = '-';
const char VerChar = '|';
int row;
int column;

void lcd_0(){    
    int i,j;    
    
    int t = 2 * displaysize + 2;
    for(i=1;i<column-1;i++){
        digit[0][0][i] = HorChar;
        digit[0][t][i] = HorChar;
    }
    t = displaysize + 1;
    for(i=1;i<column-1;i++){
        digit[0][i][0] = VerChar;
        digit[0][i+t][0] = VerChar;
        digit[0][i][t] = VerChar;
        digit[0][i+t][t] = VerChar;
    }
    
}

void lcd_1(){
    int i,j = displaysize +1;
    int t = displaysize +1;
    for(i=1;i<t;i++){
        digit[1][i][j] = VerChar;
        digit[1][i + t][j] = VerChar;
    }    
}
void lcd_2(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){
        digit[2][0][i] = HorChar;
        digit[2][t][i] = HorChar;
        digit[2][t+t][i] = HorChar;
    }
    for(i=1;i<t;i++){
        digit[2][i][t] = VerChar;
        digit[2][i+t][0] = VerChar;        
    }
}
void lcd_3(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){
        digit[3][0][i] = HorChar;
        digit[3][t][i] = HorChar;
        digit[3][t+t][i] = HorChar;
    }
    for(i=1;i<t;i++){
        digit[3][i][t] = VerChar;
        digit[3][i+t][t] = VerChar;        
    }
}
void lcd_4(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){        
        digit[4][t][i] = HorChar;        
    }
    for(i=1;i<t;i++){
        digit[4][i][0] = VerChar;
        digit[4][i][t] = VerChar;
        digit[4][i+t][t] = VerChar;        
    }
}
void lcd_5(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){
        digit[5][0][i] = HorChar;
        digit[5][t][i] = HorChar;
        digit[5][t+t][i] = HorChar;
    }
    for(i=1;i<t;i++){
        digit[5][i][0] = VerChar;
        digit[5][i+t][t] = VerChar;        
    }
}
void lcd_6(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){
        digit[6][0][i] = HorChar;
        digit[6][t][i] = HorChar;
        digit[6][t+t][i] = HorChar;
    }
    for(i=1;i<t;i++){
        digit[6][i][0] = VerChar;
        digit[6][i + t][0] = VerChar;
        digit[6][i+t][t] = VerChar;        
    }
}
void lcd_7(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){
        digit[7][0][i] = HorChar;        
    }
    for(i=1;i<t;i++){
        digit[7][i][t] = VerChar;
        digit[7][i + t][t] = VerChar;        
    }
}
void lcd_8(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){
        digit[8][0][i] = HorChar;
        digit[8][t][i] = HorChar;
        digit[8][t+t][i] = HorChar;
    }
    for(i=1;i<t;i++){
        digit[8][i][0] = VerChar;
        digit[8][i][t] = VerChar;
        digit[8][i + t][0] = VerChar;
        digit[8][i+t][t] = VerChar;        
    }
}
void lcd_9(){
    int i,j;
    int t = displaysize + 1;
    for(i=1;i<t;i++){
        digit[9][0][i] = HorChar;
        digit[9][t][i] = HorChar;
        digit[9][t+t][i] = HorChar;
    }
    for(i=1;i<t;i++){
        digit[9][i][0] = VerChar;
        digit[9][i][t] = VerChar;        
        digit[9][i+t][t] = VerChar;        
    }
}

void init(){
    int i,j;
    memset(digit,' ', sizeof(char) * 10 * Row * Col);    
    column = displaysize + 2;
    row = 2 * displaysize + 3;
    
    for(i=0;i<row;i++){
        for(j=0;j<10;j++){
            digit[j][i][column] =0;
        }
    }
    lcd_0();
    lcd_1();
    lcd_2();
    lcd_3();
    lcd_4();
    lcd_5();
    lcd_6();
    lcd_7();
    lcd_8();
    lcd_9();
}

void draw(char c, int row ,int follow){
    int i = c-'0';
    if(follow)
        printf(" ");
    printf("%s",digit[i][row]);
}

void fun(){
    int i;
    int j;
    int lim = displaysize * 2 + 3;
    int k;
    for(i=0;i<lim;i++){
        for(j=0;buffer[j];j++){            
            draw(buffer[j],i,j);
        }
        printf("\n");
    }    
}

int main(){
    int tstcase = 0;
    
    scanf("%d",&displaysize);
    while(displaysize){
        tstcase ++;        
        
        scanf("%s",buffer);
        init();
        fun();
        printf("\n");
        scanf("%d",&displaysize);    
    }
    
    return 0;
}

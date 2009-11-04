#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 10008,
};

char digit[Size];
int  num;
char alpha[Size];
char save[Size];
int  pos;

void conv_d2a(char *d, char *a){
	num = strlen(d);
	pos = Size-1;
	a[pos]=0;
	pos--;
	int carry = 0;
	int i,start = 0;
	strcpy(save,d);
	while(start < num) {
		carry = 0;
		for(i=start;i<num;i++){
			carry *= 10;
			carry += d[i]-'0';
			d[i] = carry /26;
			d[i] += '0';
			carry %= 26;
		}
		a[pos--] = carry-1 + 'a';
		while(start < num && d[start] == '0')
			start ++;
	}
	pos ++;
	printf("%-22s",a + pos);
	pos = num %3;
	start = 0;
	if(pos && num >3){
		while(pos --){
			printf("%c",save[start]);
			start ++;
		}
		printf(",");
	}
	while(start < num-3){
		printf("%c%c%c,", save[start] , save[start+1],save[start+2]);
		start += 3;
	}
	if(start < num)
		printf("%s\n", save + start);
}
void conv_a2d(char *a, char *d){
	int i,carry = 0,start =0;
	pos = strlen(a);
	num = Size -1;
	d[num --] = 0;
	printf("%-22s", a);
	while(start < pos) {
		carry = 0;
		for(i=start;i<pos;i++){
			carry *= 26;
			carry += a[i] -'a' + 1;
			a[i] = carry/10;
			carry %= 10;
			if(a[i] == 0){
				a[i] = 'a'-1;
			} else {
				a[i] += 'a' - 1;
			}
		}
		d[num--] = carry + '0';
		while(start < pos && a[start] =='a'-1){
			start ++;
		}
	}
	num++;
	start = Size -1 - num;
	start %= 3;
	if(start && Size -1-num>3) {
		while(start--){
			printf("%c",d[num]);
			num++;
		}
		printf(",");
	}
	while(num < Size-4){
		printf("%c%c%c,",d[num], d[num+1],d[num+2]);
		num+= 3;
	}
	printf("%s\n",d+num);
}

int main(){

	scanf("%s", alpha);
	while(alpha[0] !='*'){
		if(alpha[0] <='9' && alpha[0] >='0'){
			conv_d2a(alpha,digit);
		} else {
			conv_a2d(alpha,digit);
		}
		scanf("%s", alpha);
	}

	return 0;
}

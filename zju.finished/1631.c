#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Character {
	char name[80];
	int HP;
	int Armor;
	int Power;
	int Amount;
	int Cool;
	int next;
}sc[2];

void attack(int from, int to){
	int harm;
	harm = (sc[from].Power - sc[to].Armor) * sc[from].Amount;
	if(harm <=0)
		harm = 1;
	sc[from].next += sc[from].Cool;
	sc[to].HP -= harm;
	if(sc[to].HP <0)
		sc[to].HP =0;
}

void fun(){
	
	while(sc[1].HP && sc[0].HP){
		if(sc[0].next < sc[1].next){	/* 0 attack 1 */
			attack(0,1);
		} else if(sc[0].next > sc[1].next){ /* 1 attack 0 */
			attack(1,0);
		} else {
			attack(1,0);
			attack(0,1);
		}
	}
	
	if(sc[0].HP == sc[1].HP){
		printf("All Die!\n");
	} else if(sc[0].HP){
		printf("%s Survive!\n", sc[0].name);
	}else {
		printf("%s Survive!\n", sc[1].name);
	}
	
}

int main(){

	scanf("%s", sc[0].name);
	while(!feof(stdin)){
		scanf("%d %d %d %d %d", &sc[0].HP,&sc[0].Armor,&sc[0].Cool,
				&sc[0].Amount, &sc[0].Power);
		scanf("%s", sc[1].name);
		scanf("%d %d %d %d %d", &sc[1].HP,&sc[1].Armor,&sc[1].Cool,
				&sc[1].Amount, &sc[1].Power);
		sc[0].next = sc[0].Cool;
		sc[1].next = sc[1].Cool;
		fun();
		scanf("%s", sc[0].name);
	}

	return 0;
}

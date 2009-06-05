#include<iostream>

using namespace std;

int top,bot,lef,rig,up,down;
char buffer[20];
int num;

void turn_north(){
	int saveup = up, savetop = top, savebot=bot,savedown=down;
	top = saveup; up = savebot; 
	down=savetop; bot= savedown;
}

void turn_south(){
	int saveup = up, savetop=top, savebot=bot,savedown=down;
	top = savedown; up = savetop;
	bot = saveup; down= savebot;
}

void turn_west(){
	int savelef = lef, saverig=rig, savetop=top, savebot=bot;
	top = savelef, lef=savebot;
	rig=savetop, bot=saverig;
}

void turn_east(){
	int savelef = lef, saverig=rig, savetop=top, savebot=bot;
	top = saverig, lef=savetop;
	rig=savebot, bot=savelef;
}

int fun(){
	top = 1, bot=6,up=2,down=5,lef=3,rig=4;

	while(num--){
		cin>>buffer;
		switch(buffer[0]){
			case 'n':
				turn_south();
				break;
			case 's':
				turn_north();
				break;
			case 'w':
				turn_east();
				break;
			case 'e':
				turn_west();
				break;
			default:
				break;
		}
	}
	return top;
}

int main(){
	
	cin>>num;
	while(num){
		cout<<fun()<<endl;
		cin>>num;
	}

	return 0;
}

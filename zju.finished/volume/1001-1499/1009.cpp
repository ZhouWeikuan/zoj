#include<iostream>

using namespace std;

struct Rotor {
	int map[32];
	int pre[32];
	int rev;
};

Rotor rot[3];
char buffer[1024];
int num;

void movenext(int cur){
	static int premap[32];
	memcpy(premap, rot[cur].map, sizeof(premap));
	int i,t;
	for(i=0;i<num;i++){
		t = (i+num-1)%num;
		t = premap[t];
		t = (t+1)%num;
		rot[cur].map[i] = t;
		rot[cur].pre[t] = i;
	}
	if(cur < 2){
		rot[cur].rev ++;
		if(rot[cur].rev >= num){
			movenext(cur+1);
			rot[cur].rev = 0;
		} 
	}
}

void init(){
	int i,j,t;
	for(i=0;i<3;i++){
		cin>>buffer;
		for(j=0;buffer[j];j++){
			t = buffer[j] - 'A';
			rot[i].map[j] = t;
			rot[i].pre[t] = j;
		}
		rot[i].rev = 0;
	}
}

void decrypt(){
	int i,j,t;
	for(i=0;buffer[i];i++){
		t = buffer[i] - 'A';
		t = rot[2].pre[t];
		t = rot[1].pre[t];
		t = rot[0].pre[t];
		buffer[i] = t +'a';
		movenext(0);
	}
	cout<<buffer<<"\n";
}
void save_rot(int status){
	static Rotor save_rot[3];
	if(status == 0){
		memcpy(save_rot, rot, sizeof(save_rot));
	} else {
		memcpy(rot, save_rot, sizeof(save_rot));
	}
}

void fun(){
	static int tstcase = 1;
	int crypt;

	save_rot(0);
	
	if(tstcase !=1)
		cout<<"\n";
	cout<<"Enigma "<<tstcase++<<":\n";
	cin>>crypt;	
	while(crypt --){
		save_rot(1);
		cin>>buffer;
		decrypt();
	}
}
	
int main(){
	
	cin>>num;
	while(num){
		init();
		fun();
		cin>>num;
	}
	
	return 0;
}

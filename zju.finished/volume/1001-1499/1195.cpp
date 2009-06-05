#include<iostream>

using namespace std;
enum {
	Size = 1000,
};
struct Device {
	bool status;
	int value;	
};

Device dev[Size];
int dnum, knum;
int limit;

void fun(){
	static int tstcase = 0;
	int maxValue = 0,current = 0;
	int id;
	while(knum--){
		cin>>id;
		id --;
		dev[id].status = 1-dev[id].status;
		if(dev[id].status){
			current += dev[id].value;
		} else {
			current -= dev[id].value;
		}
		if(current > maxValue){
			maxValue = current;
		}
	}

	cout<<"Sequence "<< ++tstcase<<endl;
	if(maxValue > limit){
		cout<<"Fuse was blown."<<endl;
	} else {
		cout<<"Fuse was not blown."<<endl;
		cout<<"Maximal power consumption was "<< maxValue<<" amperes."<<endl;
	}
	cout<<endl;
}


int main(){
	int i;
	cin>>dnum>>knum>>limit;
	while(dnum){
		for(i=0;i<dnum;i++){
			dev[i].status = false;
			cin>>dev[i].value;
		}

		fun();

		cin>>dnum>>knum>>limit;
	}

	return 0;
}

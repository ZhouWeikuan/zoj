#include<iostream>

using namespace std;
char buffer[280];
int pos;

int main(){
	int tstcase;
	cin>>tstcase;
	while(tstcase --){
		do {
			cin.getline(buffer,280);
		} while(buffer[0] == 0);

		if(tstcase)
			cout<<endl;
	}

	return 0;
}

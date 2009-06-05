#include<iostream>
#include<string>

using namespace std;

string forward[108];
string backward[108];
int flen, blen;

string current;

int main(){
    int num;
    string cmd;    
    
    cin>>num;
    
    while(num--){
		current = "http://www.acm.org/";
		blen = 0;
		flen = 0;
		for(;;){
			cin>>cmd;
			if(cmd[0] == 'V'){ // Visit
				backward[blen ++] = current;
				flen = 0;
				cin>>current;
				cout<< current <<endl;
			} else if(cmd[0] =='B'){ // Back
				if(blen == 0){
					cout << "Ignored" <<endl;
				} else {
					forward[flen ++] = current;
					current = backward[--blen];
					cout<< current <<endl;
				}
			} else if(cmd[0] =='F'){ // Forward
				if(flen ==0){
					cout << "Ignored" <<endl;
				} else {
					backward[blen ++] = current;
					current = forward[--flen];
					cout<< current <<endl;
				}
			} else { // Quit
				break;
			}
			
		}
		
		if(num)
			cout<<endl;
	}
    
    return 0;
}

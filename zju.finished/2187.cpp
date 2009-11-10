#include<iostream>
#include<cstring>
using namespace std;

char matrix[12][12];
int R,C;

void fun(){
	int i,j;
	int t;
	for(i=0;i<R;i++){
		cin>>matrix[i];
	}
	R--,C--;
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			t = matrix[i][j];
			t += matrix[i+1][j] + matrix[i][j+1]+matrix[i+1][j+1];
			t /= 4;
			matrix[i][j] = t;
		}
		matrix[i][C] = 0;
		cout<<matrix[i]<<endl;
	}
}

int main(){
	char buffer[12];
	
	cin>>buffer;
	while(strcmp(buffer,"ENDOFINPUT") !=0){
		cin>>R>>C;
		fun();
		cin>>buffer;

		cin>>buffer;
	}

	return 0;
}

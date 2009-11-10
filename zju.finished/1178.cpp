#include<iostream>

//    1,2,3,4
//	从第一页开始，每页的1,4留给最大的两个，2,3留给最小的两个，没有的话补全.
//   即   pos[1] = n/4 *4 + 4  pos[3]=n/4*4 + 3
//		 pos[2] = n/4*4 +1    pos[3]=n/4*4 + 2


using namespace std;
int num;
int data[120];
int front[2], back[2];

void fun(){
	int t = (num-1)/4;
	t = (t+1)*4;
	int i;
	for(i=0;i<num;i++){
		data[i] = i+1;
	}
	for(i=num;i<t;i++)
		data[i] = 0;
	int low = 0, hi = t-1;
	int sno = 1;
	while(low <= hi){
		front[0] = data[hi--];
		front[1] = data[low++];
		back[0] = data[low++];
		back[1] = data[hi--];
		cout<<"Sheet "<<sno<<", front: ";
		if(front[0])
			cout<<front[0];
		else
			cout<<"Blank";
		cout<<", "<<front[1]<<endl;
		if(back[0]+back[1]){
			cout<<"Sheet "<<sno++<<", back : ";
			if(back[0])
				cout<<back[0];
			else
				cout<<"Blank";
			cout<<", ";
			if(back[1])
				cout<<back[1];
			else 
				cout<<"Blank";
			cout<<endl;
		}
	}
}

int main(){
	
	cin>>num;
	while(num){
		cout<<"Printing order for "<<num<<" pages:"<<endl;
		fun();

		cin>>num;
	}

	return 0;
}

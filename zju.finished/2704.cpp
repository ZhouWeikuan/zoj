#include<iostream>
#include<map>
/*
	如果s,r是一个符合条件的，则 []s,()s,(s),[s],s(),s[],rs 均符合条件
*/
using namespace std;
char buf[100004];
map<int,int> tab;
map<int,int>::iterator iter;

int match(int a, int b){
	if(buf[a] == '(' && buf[b] ==')')
		return 1;
	if(buf[a] == '[' && buf[b] ==']')
		return 1;
	return 0;
}

void fun(){
	int i;
	int t;
	int a,b;
	int start=0, end=0;
    tab.clear();
	for(i=0;buf[i];i++){
		if(match(i,i+1)){
			a = i, b = i+1;
			t = 1;
			do {
				t = 0;
				if(buf[b+1] && match(b+1,b+2)){
					b = b + 2;
					t = 1;
				}
				if(a>0 &&match(a-1, b+1)){
					a = a-1;
					b = b+ 1;
					t = 1;
				}
                if(a >0 && (iter = tab.find(a-1)) != tab.end()){
                    a = iter->second;
                    tab.erase(iter);
                }

			} while(t);
            tab[b] = a;
			if(b -a > end - start){
				end = b; start = a;
			}

			i = b;
		}
	}

	if(start != end)
		for(i = start ; i <= end; i++){
			printf("%c",buf[i]);
		}
	printf("\n\n");
}


int main(){
	
	while(cin.getline(buf,100004)){
		fun();
		cin.getline(buf,100004);
	}

	return 0;
}

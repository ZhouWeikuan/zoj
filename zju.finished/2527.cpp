#include<iostream>
#include<map>
#include<algorithm>

using namespace std;
enum {
    SIZ = 1008,
};
map<int,int>::iterator it;
map<int,int> s[SIZ];
int v[SIZ];
int num;

void fun(){
	int i,j,d,cnt;
    int ret = 0;
	for(i=1;i<num;i++){
		for(j=i-1;j>=0;j--){
            d = v[i] - v[j];
            it=s[j].find(d);
            if(it == s[j].end()){
                cnt = 2;
            } else {
                cnt = 1 + it->second;
            }
            it=s[i].find(d);
            if(it==s[i].end() || it->second < cnt){
                s[i].insert(make_pair(d,cnt));
                if(cnt > ret)
                    ret = cnt;
            }
		}
	}
	cout<<ret<<endl;
}

int main(){
	int i;

	while(cin>>num){
		for(i=0;i<num;i++){
            s[i].clear();
			cin>>v[i];
		}
        sort(v, v+num);
		fun();
	}
	return 0;
}

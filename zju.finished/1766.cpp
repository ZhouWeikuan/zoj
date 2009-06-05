#include<iostream>
#include<map>
#include<set>
#include<cctype>

using namespace std;
struct cmp{
	int operator()(const string &a, const string &b){
		return strcasecmp(a.c_str(), b.c_str())< 0;
	}
};

typedef map<string, int, cmp> mymap;
mymap words;
int top;
char buf[100];

int main(){
	top = 0;
	int i= 0;
	volatile int t;

	while((buf[i]=cin.get())!=EOF){
		if(isalnum(buf[i])){
			if(isupper(buf[i])){
				buf[i] -= 'A' - 'a';
			}
			i++;

		} else if(i>0){
			buf[i] = 0;
			string s(buf,buf+i);
			mymap::iterator it = words.find(s);
			if(it == words.end()){
				words[s] ++;
				t = 1;
			} else {
				t = ++ it->second;
			}
			if(t>top)
				top = t;
			i = 0;
		}
	}
	set<string, cmp> s;
	for(mymap::iterator it=words.begin();
		it != words.end();
		it++){
		if(it->second == top){
			s.insert(it->first);
		}
	}
	cout<<top<<" occurrences"<<endl;
	for(set<string,cmp>::iterator iter = s.begin();
		iter!=s.end();iter++){
		cout<<(*iter)<<endl;

	}
	return 0;
}

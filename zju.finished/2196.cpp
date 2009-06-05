#include<iostream>
#include<cstring>
#include<string>
#include<stack>

using namespace std;
char buf[1024];
int num;

int judge(int s, int e){
	stack<char> save;
	int t;
	while(s < e){
		while(buf[s]!= '<'){
			if(buf[s] == '>')
				return 0;
			s++;
		}
		s++;
		if(s >=e )
			goto end;
		if(buf[s] =='/'){
			s ++;
			if(save.empty() || buf[s] != save.top()){
				return 0;
			}
			s++;
			save.pop();
			if(s>=e || buf[s]!='>')
				return 0;
		} else if(buf[s] =='A' || buf[s]=='B'||buf[s]=='I'){
			save.push(buf[s]);
			t = ++s;
			while(buf[s] != '>'){
				if(s>=e || buf[s] =='<')
					return 0;
				s++;
			}
			if(save.top() == 'A'){
				if(strncmp(&buf[t]," HREF=http://",13)!=0)
					return 0;
				if(strncmp(&buf[s-4],".com>",5)!=0)
					return 0;
			}else {
				if(s - t > 1)
					return 0;
			}
		} else {
			return 0;
		}
		s ++;
	}
end:
	if(save.empty())
		return 1;
	return 0;
}

int parse(){
	if(strncmp(buf,"<HTML><BODY>",12) !=0)
		return 0;
	if(strncmp(&buf[num-14],"</BODY></HTML>",14)!=0)
		return 0;
	return judge(12,num-14);
}

int main(){
	int tstcase,t;
	const char *ans[2] = {"No Syntax Included","Syntax Included"};
	cin>>tstcase;
	
	cin.getline(buf,1024);
	while(tstcase --){
		cin.getline(buf,1024);
		num = strlen(buf);
		t = parse();
		cout<<ans[t]<<endl;
	}

	return 0;
}

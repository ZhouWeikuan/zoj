#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
const string delim = "|     ";
struct Dir {
	string name;
	vector<string> filelist;
	vector<int> subdir;
};

Dir save[200];
int start,root;
int getDir(){
	save[start].filelist.clear(); 
	save[start].subdir.clear();
	return start ++;
}
void scandir(Dir &d){
	static string s;
	int t;
	cin>>s;
	while(s!="]"){
		if(s[0] == 'f'){
			d.filelist.push_back(s);
		} else {
			t = getDir();
			save[t].name = s;
			d.subdir.push_back(t);
			scandir(save[t]);
		}
		cin>>s;
	}
}
void printlevel(int l){
	while(l --){
		cout<<delim;
	}
}

void output(Dir &d, int level){
	sort(d.filelist.begin(),d.filelist.end(),less<string>() );
	printlevel(level);
	cout<<d.name<<endl;
	int i;
	for(i=0;i<d.subdir.size();i++){
		output( save[d.subdir[i]],level+1);
	}
	for(i=0;i<d.filelist.size();i++){
		printlevel(level);
		cout<<d.filelist[i]<<endl;
	}
}

int main(){
	int tstcase = 0;
	string s;
	
	cin>>s;
	while(s!="#"){
		if(tstcase ++ )
			cout<<endl;
		start = 0; root= getDir();
		save[root].name = "ROOT";
		while(s!="*"){
			if(s[0] == 'f'){
				save[root].filelist.push_back(s);
			} else { // directory
				int t = getDir();
				save[t].name = s;
				save[root].subdir.push_back(t);
				scandir(save[t]);
			}
			cin>>s;
		}
		cout<<"DATA SET "<<tstcase<<":"<<endl;
		output(save[root],0);

		cin>>s;
	}

	return 0;
}

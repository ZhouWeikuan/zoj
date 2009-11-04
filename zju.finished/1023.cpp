#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<deque>

using namespace std;
struct Student {
	int region;
	double score;
	int school;
	int volnum;
	vector<int> college;
};
Student stud[154];

struct Node {
	int index;
	int volnum;
	double score;
};

struct University{	
	struct MyComp{	
		int operator ()(const Node &a, const Node &b){
			return a.score < b.score;
		}
	};

	int region;
	int num;	
	priority_queue<Node, vector<Node>, MyComp > q;
};

University school[52];
queue<int> reg;
int studnum,schnum;

int main(){
	int tstcase;
	cin>>tstcase;
	while(tstcase --){
		cin>>studnum>>schnum;
		int i,n,t;
		for(i=0;i<studnum;i++){
			cin>>stud[i].region>>stud[i].score>>n;
			stud[i].school = -1;
			stud[i].volnum = -1;
			stud[i].college.clear();
			while(n--){
				cin>>t; t--;
				stud[i].college.push_back(t);
			}
		}
		for(i=0;i<schnum;i++){
			cin>>school[i].region>>school[i].num;
			while(!school[i].q.empty()){
				school[i].q.pop();
			}
		}
		Node one;
		for(i=0;i<studnum;i++){
			one.index = i;
			for(t=0; t<stud[i].college.size();t++){
				n = stud[i].college[t];
				if(school[n].region == stud[i].region){
					one.score = stud[i].score *10.0/7.0;
				} else {
					one.score = stud[i].score;
				}
				one.volnum = t;
				school[n].q.push(one);
			}
		}
		for(i=0;i<schnum;i++){
			if(! school[i].q.empty())
				reg.push(i);
		}
		
		int pred,v;
		University *u;
		while(!reg.empty()){
			n = reg.front(); reg.pop();
			u = &school[n];
			while(u->num && !u->q.empty()){
				t = u->q.top().index;
				v = u->q.top().volnum;
				u->q.pop();
				if(stud[t].school==-1){
					stud[t].school = n;
					stud[t].volnum = v;
					u->num --;
				} else if(stud[t].volnum > v){
					pred = stud[t].school;
					stud[t].school = n;
					stud[t].volnum = v;
					if(school[pred].num ++ == 0){
						reg.push(pred);
					}
					u->num --;
				}
			}
		}

		for(i=0;i<studnum;i++){
			n = stud[i].school;
			if(n == -1){
				cout<<"not accepted\n";
			} else {
				cout<<(n+1)<<"\n";
			}
		}
		
		
		if(tstcase)
			cout<<endl;
	}
	return 0;
}

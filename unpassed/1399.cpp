#include<iostream>
#include<vector>

using namespace std;
int num, arrtime;
vector<int> tree[20];

int calc(const vector<int> & vec){
	int n, j;
	n = arrtime % vec.back();
	for(j=0;j<vec.size();j++){
		if(n <= vec[j]){
			return vec[j] - n;
		}
	}
	return 0;
}

void fun(){
	int ret = 99999999,t;
	for(int i=0; i<num; i++){
		t = calc(tree[i]);
		if(t < ret)
			ret = t;
	}
	printf("%d\n", ret);
}

int main(){
	char buf[200];
	int v, p; char ch;

	scanf("%s",buf);
	while(strcmp(buf,"ENDOFINPUT")!=0){
		scanf("%d ",&num);
		for(int i=0;i<num;i++){	
			tree[i].clear();
            tree[i].push_back(0);
            p = 0;
			do {
				scanf("%d%c",&v,&ch);
                p += v;
				tree[i].push_back(p);
			}while(ch!='\n');
		}
		scanf("%d ",&arrtime);
		scanf("%s ",buf); // END
        fun();
		scanf("%s ",buf); // START or ENDOFINPUT
	}

	return 0;
}


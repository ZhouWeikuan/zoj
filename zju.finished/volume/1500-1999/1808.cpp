#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<string> sym;

int fun(vector<int> &v, int n){    
	if(v.size()<=1)
	   return 0;
	vector<int> zero;
	vector<int> one;
	int i;
	for(i=0;i<v.size(); i++){
        if(sym[v[i]][n] == '0'){
            zero.push_back(v[i]);
        } else if( sym[v[i]][n] =='1'){
            one.push_back(v[i]);
        } else {
            return 1;
        }
    }
	
	if(fun(zero,n+1))
	   return 1;
	
	return fun(one,n+1);
}

int main(){
	string s;	
	vector<int> point;
	int i;
	int tstcase = 1;
	
	cin>>s;
	while(s[0] !='9'){
        i = 0;
        while(s[0] != '9'){
            sym.push_back(s);
            point.push_back(i++);
            cin>>s;
        }        
        i = fun(point,0);
        cout<< "Set " << tstcase ++ <<" is ";
        if(i){
            cout<<"not ";
        }
        cout<<"immediately decodable" <<endl;
        
        sym.clear();
        point.clear();
        cin>>s;
    }
	
	return 0;
}

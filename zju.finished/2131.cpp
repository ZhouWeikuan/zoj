#include<iostream>
//×¢ÒâËÑË÷Ìõ¼þ 
using namespace std;
enum {
	Size = 7,
};
char mat[Size+3][Size+3];

int readIn(){
	if(cin>>mat[0])
		;
	else
		return 0;
	for(int i=1;i<=Size;i++){
		cin>>mat[i];
	}
	return 1;
}
int move[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int search(int a, int b, char ch, int d){
	int ret = 0;
	int x = a +move[d][0], y =b+ move[d][1];
	while(x>=0 && x<8 && y>=0 && y<8 && mat[x][y] == ch){
		ret ++;
		x += move[d][0], y += move[d][1];
	}
	d += 2;
	d %= 4;
	x =a+ move[d][0], y =b+ move[d][1];
	while(x>=0 && x<8 && y>=0 && y<8 && mat[x][y] == ch){
		ret ++;
		x += move[d][0], y += move[d][1];
	}
	return ret;
}
inline void swap(int a, int b, int x, int y){
	char ch;
	ch = mat[a][b];
	mat[a][b] = mat[x][y];
	mat[x][y] = ch;
}
int op(int a, int b){
	int ret, v= 0,t,s;
	//right
	if(b<Size && mat[a][b] != mat[a][b+1]){
		swap(a,b,a,b+1);
		t = search(a,b,mat[a][b],0);
		v += (t>=2)?t:0;
		t = search(a,b,mat[a][b],1);
		v += (t>=2)?t:0;
		if(v >0)
			v++;
		s= v; v = 0;
		
		t = search(a,b+1,mat[a][b+1],0);
		v += (t>=2)?t:0;
		t = search(a,b+1,mat[a][b+1],1);
		v += (t>=2)?t:0;
		if(v)
			v++;
		v += s;
		swap(a,b,a,b+1);
	}
	ret = v; v=0;
	//down
	if(a< Size && mat[a][b]!=mat[a+1][b]){
		swap(a,b,a+1,b);
		t = search(a,b,mat[a][b],0);
		v += (t>=2)?t:0;
		t = search(a,b,mat[a][b],1);
		v += (t>=2)?t:0;
		if(v >0)
			v++;
		s= v; v = 0;

		t = search(a+1,b,mat[a+1][b],1);
		v += (t>=2)?t:0;
		t = search(a+1,b,mat[a+1][b],2);
		v += (t>=2)?t:0;
		if(v)
			v++;
		v += s;
		swap(a,b,a+1,b);
	}
	ret = ret<v?v:ret;
	return ret;
}

int fun(){
	int i,j, v =0,t;
	for(i=0;i<=Size;i++){
		for(j=0;j<=Size;j++){
			t = op(i,j);
			if(v < t)
				v = t;
		}
	}
	return v;
}

int main(){
	
	while(readIn()){
		cout<<fun()<<endl;
	}

	return 0;
}

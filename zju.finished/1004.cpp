#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<cstdio>

using namespace std;
map<char, int> table;

int smap[1024];
char source[1024];
char dest[1024];
int slen;
int dlen;

char stackop[2048];
int  pos;

char stackele[2048];
int  epos;

void calc(int i, int j){
	int t;
	if(j == dlen){		
		for(t =0 ; t < pos; t++){
			cout<<stackop[t]<<" ";
		} 
		cout<<endl;
		return;
	}
	if(i > slen){
		return;
	}

	if(source[i] ==	dest[j]){		
		
		stackop[pos ++] 	= 'i';
		stackele[epos ++ ]	=	source[i];			
		calc(i+1,j);
		epos --;
		pos --;		
		
		/*　以前有　*/ 
		if(epos && stackele[epos-1] == dest[j]){
			stackop[pos++] = 'o';
			epos --;
			calc(i,j+1);
			stackele[epos ++] = dest[j];
			pos --;
		}  
		return;
	}
	/* Stackop[pos] !=   */	
	/*　以后有？ */
	
	stackop[pos++]		=	'i';
	stackele[epos++]	=	source[i];
	calc(i+1,j);
	epos --;
	pos --;	
	
	/*　以前有　*/
	if(epos && stackele[epos-1] == dest[j] ){
		stackop[pos++] = 'o';
		epos --;
		calc(i,j+1);
		stackele[epos ++] = dest[j];
		pos --;
	}
}

void fun(){
    int i;
    char alpha;
    map<char,int>::iterator iter;
    
    for(i=slen-1; i>= 0 ; i--){
		alpha = source[i];
		iter = table.find( alpha );
		if(iter != table.end()){
			smap[i]	= table[alpha];
		} else {
			smap[i] = 0;
		}
		table[alpha] = i;
	}	
	
	calc(0,0);		
}

int main(){    
       
    while(cin>> source >> dest){
		slen	=	strlen(source);
		dlen	=	strlen(dest);
		table.clear();
		epos	=	pos		=	0;
		cout<<"["<<endl;
		if(slen == dlen)
			fun();
		cout<<"]"<<endl;
	}
    
    return 0;
}

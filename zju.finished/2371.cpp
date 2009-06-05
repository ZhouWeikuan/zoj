#include<iostream>
#include<vector>

using namespace std;
enum {
    CAP = 40,
};
struct BigInt {
	int pos;
	int dat[CAP];
	void conv(string &s);
	void mult(BigInt &, int m);
	void operator -=(BigInt &);
	void output();
	void div(int m);
};
void BigInt::conv(string &s){
	pos = s.length();
	for(int i=0;i<pos;i++){
		dat[i] = s[pos-1-i] - '0';
	}
}
void BigInt::mult(BigInt &d, int m){
	int i,carry = 0;
	d.pos = pos;
	for(i=0;i<pos;i++){
		d.dat[i] = dat[i] * m + carry;
		if(d.dat[i] > 9){
			carry = d.dat[i] /10;
			d.dat[i] %= 10;
		} else {
			carry = 0;
		}
	}
	if(carry){
		d.dat[d.pos++] = carry;
	}
    /*
    if(d.pos > CAP){
        cerr<<"out of CAP!"<<endl;
    }*/
}
void BigInt::output(){
	int i;
	for(i=pos-1;i>=0;i--){
		cout<<dat[i];
	}
}
void BigInt::operator -=(BigInt &r){
	if(pos < r.pos){
		pos = 0;
		return;
	}
	int i,carry = 0;
	for(i=0;i<r.pos;i++){
		carry += r.dat[i];
		if(dat[i] <carry){
			dat[i] += 10 - carry;
			carry = 1;
		} else {
			dat[i] -= carry;
			carry = 0;
		}
	}
	while(carry && i < pos){
        if(dat[i] < carry){
            dat[i] += 10 - carry;
            carry = 1;
        } else {
            dat[i] -= carry;
            carry = 0;
        }
        i++;
	}
	i = pos - 1;
	while(i>=0 && dat[i]==0){
		i --;
	}
	pos = i + 1;
}
void BigInt::div(int m){
	int i = pos - 1;
	if(dat[i] < 2){
		pos --;
	}
	int carry = 0;
	while(i>=0 ){
		carry *= 10;
		carry += dat[i];
		dat[i] = carry / 2;
		carry %= 2;
		i--;
	}
}

BigInt duo[100],tri[100];
int dpos,tpos;
BigInt one;
void init(){
	dpos = tpos = 0;
	string s("1");
	duo[0].conv(s);
	tri[0].conv(s);
	while(duo[dpos].pos <= 20){
		duo[dpos].mult(duo[dpos+1],2);
		dpos ++;
	}
	while(tpos < dpos + 3){
		tri[tpos].mult(tri[tpos+1],3);
		tpos ++;
	}
	one.conv(s);
}

void fun(string & s){
	if(s.length()==1 && s[0] =='1'){
		cout<<"{ }"<<endl;
		return;
	}
		
	BigInt cur;
	cur.conv(s);
	cur -= one;
	int t = 0 ;
	vector<int> v;

	while(cur.pos){
		if(cur.dat[0] % 2 ){
			v.push_back(t);
		}
		cur.div(2);
		t ++;
	}
	cout<<"{ ";
	tri[v[0]].output();
	for(t =1 ; t<v.size(); t++){
		cout<<", ";
		tri[v[t]].output();
	}
	cout<<" }"<<endl;
}


int main(){
	string s;

	init();

	while(cin>>s){
        if(s[0] =='0')
            break;
		fun(s);
	}

	return 0;
}

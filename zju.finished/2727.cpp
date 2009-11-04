#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Node {
	string name;
	int year;
	int price;
};

Node book[108];
struct sort_name{
	int operator()(const Node &a, const Node &b){
		int t= a.name > b.name;
		if(t)
			return t;
		if(a.year != b.year)
			return a.year > b.year;
		return a.price > b.price;
	}
};
struct sort_year{
	int operator()(const Node &a, const Node &b){
		if(a.year != b.year)
			return a.year > b.year;
		int t= a.name > b.name;
		if(t )
			return t;
		return a.price > b.price;
	}
};
struct sort_price{
	int operator()(const Node &a, const Node &b){
		if(a.price != b.price)
			return a.price > b.price;
		int t = a.name > b.name;
		if(t) return t;
		return a.year > b.year;
	}
};

int main(){
	int num;
	int i;
	int tstcase = 0;
	string sortmethod;
	
	while(cin>>num && num){
		if(tstcase ++ ){
			cout<<endl;
		}
		for(i=0;i<num;i++){
			cin>>book[i].name>>book[i].year>>book[i].price;
		}
		cin>>sortmethod;
		if(sortmethod=="Name"){
			sort(book,book+num, sort_name());
		} else if(sortmethod == "Year") {
			sort(book,book+num, sort_year());
		} else { // sortmethod == "Price"
			sort(book,book+num, sort_price());
		}
		for(i=num-1;i>=0;i--){
			cout<<book[i].name<<" "<<book[i].year<<" "<<book[i].price<<endl;
		}
	}
}

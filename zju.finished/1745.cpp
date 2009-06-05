#include<iostream>

using namespace std;
struct Node {
    int pos;
    int dis;
};
int target;

void fun(){
    Node one,two;
    Node *pred,*cur, *t;
    pred = &one;
    cur = &two;
    pred->pos = 0; pred->dis = pred->pos - target;
    if(pred->dis < 0){
        pred->dis = -pred->dis;
    }
    while(cin>>cur->pos){
        cur->dis = cur->pos - target;
        if(cur->dis < 0){
            cur->dis = -cur->dis;
        }
        cout<<"Moving from "<<pred->pos
            <<" to "<<cur->pos<<": ";
        if(cur->pos == target){
            cout<<"found it!"<<endl;
            return;
        }else if(pred->dis == cur->dis){
            cout<<"same."<<endl;
        }else if(cur->dis > pred->dis){
            cout<<"colder."<<endl;
        } else {
            cout<<"warmer."<<endl;
        }

        t = pred; pred = cur; cur = t;
    }
}

int main(){
    int tstcase = 0;

    while(cin>>target){
        if(target == 5280){
            break;
        }
        if(tstcase ++ ){
            cout<<endl;
        }
        fun();
    }

	return 0;
}

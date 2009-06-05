#include<iostream>

using namespace std;
int width;

void fun(){
    int h = 0,w =0;
    int curh =0, curw=0;
    int x,y;

    cin>>x>>y;
    while(x > 0 && y > 0){
        if(curw + x > width){
            if(w < curw){
                w = curw;
            }
            h += curh;
            curw = x;
            curh = y;
        } else {
            if(curh < y)
                curh = y;
            curw += x;
        }
        cin>>x>>y;
    }
    if(w < curw)
        w = curw;
    h += curh;
    cout<<w<<" x "<<h<<endl;
}

int main(){
    
    cin>>width;
    while(width){
        fun();
        cin>>width;
    }

	return 0;
}

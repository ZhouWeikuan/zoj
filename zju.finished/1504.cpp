#include<iostream>
#include<set>

// 距离相等，则它们的平方也相等
using namespace std;
struct Slot {
    int x;
    int y;
};
struct Node {
    int num;
    int ptr[80];
};
Slot slot[80];
Node tree[30];
int n;

void readIn(){
    int base = 0,i,j;
    char ch;
    int x = 0,y = 0;
    int t;
    for(i=0;i<26;i++)
        tree[i].num = 0;

    for(i=1;i<=n;i++){
        for(j=0;j <i;j++){
            cin>>ch;
            slot[base + j].x =  x + j * 2; 
            slot[base + j].y = y;
            t = ch - 'a';
            tree[t].ptr[ tree[t].num++ ] = base + j;
        }
        x -= 1;
        y -= 1;
        base += i;
    }
}

int getDis(int a, int b){
    int x, y;
    x = slot[a].x - slot[b].x;
    x *= x;
    y = slot[a].y - slot[b].y;
    y *= y;
    x += 3*y;
    return x;
}
int checkfor(Node &one){
    int i,j,k;
    int s1,s2,s3;
    if(one.num <= 2)
        return 0;
    for(i=0;i<one.num;i++){
        for(j=i+1;j<one.num;j++){
            for(k=j+1;k<one.num;k++){
                s1 = getDis(one.ptr[i], one.ptr[j]);
                s2 = getDis(one.ptr[i], one.ptr[k]);
                if(s1!=s2)
                    continue;
                s3 = getDis(one.ptr[j], one.ptr[k]);
                if(s3 == s2)
                    return 1;
            }
        }
    }
    return 0;
}

void fun(){
    set<char> tab;
    for(int i=0;i<26;i++){
        if(checkfor(tree[i])){
            tab.insert('a' + i);
        }
    }

    if(tab.size() == 0){
        cout<<"LOOOOOOOOSER!"<<endl;
        return;
    }
    for(set<char>::iterator it = tab.begin();
            it!=tab.end();
            it++){
        cout<<(*it);
    }
    cout<<endl;
}

int main(){
    
    cin>>n;
    while(n){
        readIn();
        fun();
        cin>>n;
    }

	return 0;
}

#include<iostream>
#include<set>
#include<stack>

using namespace std;
set<char> tree[600];
set<char>::iterator iter;
char genbuf[300];
int cur ;

int mergeSet(set<char> &s, char *str){
    int ret = 1;
    s.clear();
    while(*str!='}'){
        s.insert(*str);
        ret ++;
        str ++;
    }
    return ret;
}

int pred(char c){
    switch(c){
    case '(':
    case ')':
        return 10;
        break;
    case '*':
        return 5;
        break;
    case '+':
    case '-':
        return 1;
        break;
    }
    return 0;
}

void execute(stack<int> &st, char op){
    int one = cur ++;
    int a,b;
    b = st.top(); st.pop();
    a = st.top(); st.pop();
    tree[one].clear();
    switch(op){
    case '+':
        tree[one].insert(tree[a].begin(), tree[a].end());
        tree[one].insert(tree[b].begin(), tree[b].end());
        break;
    case '-':
        for(iter = tree[a].begin(); iter!= tree[a].end(); iter++){
            if( tree[b].find(*iter) == tree[b].end()){
                tree[one].insert(*iter);
            }
        }
        break;
    case '*':
        for(iter = tree[a].begin(); iter!= tree[a].end(); iter++){
            if( tree[b].find(*iter) != tree[b].end()){
                tree[one].insert(*iter);
            }
        }
        break;
    default:
        cerr<<"This can't happen!"<<endl;
    }
    st.push(one);
}
void fun(){
    int i = 0;
    stack<int> num;
    stack<char> op;
    cur = 0;

    while(genbuf[i]){
        if(genbuf[i] =='{'){
            int t = mergeSet(tree[cur], &genbuf[i+1]);
            i += t;
            num.push(cur);
            cur ++;
        } else {
            if(genbuf[i] =='('){
                op.push(genbuf[i]);
            }else if(genbuf[i]==')'){
                char o = op.top();
                op.pop();
                while(o != '('){
                    execute(num, o);
                    o = op.top();
                    op.pop();
                }
            } else {
                while(op.size() > 0){
                    char o = op.top();
                    op.pop();
                    if( o!='(' && pred(o) >= pred(genbuf[i])){
                        execute(num, o);
                    } else {
                        op.push(o);
                        break;
                    }
                }
                op.push(genbuf[i]);
            }
        }
        i ++;
    }

    while(op.size() > 0){
        char o = op.top(); op.pop();
        execute(num, o);
    }
    int t = num.top(); num.pop();
    cout<<"{";
    for(set<char>::iterator it = tree[t].begin();
            it != tree[t].end();
            it++){
        cout<< (*it);
    }
    cout<<"}"<<endl;

}

int main(){

    while(cin.getline(genbuf, 300)){
        if(genbuf[0] ==0)
            break;
        fun();
    }

	return 0;
}

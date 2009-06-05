#include<iostream>
#include<vector>
using namespace std;
struct Node {
    bool mark;
    int  num;
    vector<Node *> cld;
    Node(){
        cld.clear();
    }
    void free();
};
void Node::free(){
    for(int i=0; i<cld.size(); i++){
        cld[i]->free();
        delete cld[i];
        cld[i] = 0;
    }
    cld.clear();
}

Node a,b, *tree;
char input[3008];

int match(Node *a, Node *b){
    if(a->cld.size() != b->cld.size() || a->num != b->num){
        return 0;
    }
    int s = a->cld.size(), i;
    for(i=0; i<s; i++){
        b->cld[i]->mark = false;
    }
    bool m;
    for(i=0; i<s; i++){
        m = false;
        for(int j=0; j<s; j++){
            if(b->cld[j]->mark ==true )
                continue;
            if(match(a->cld[i], b->cld[j])){
                b->cld[j]->mark = true;
                m = true;
                break;
            }
        }
        if(m == false){
            return 0;
        }
    }
    return 1;
}

int build_tree(Node *t, char *&s){
    t->num = 1;
    while(*s){
        if(*s == '1'){
            break;
        } else {
            s++;
            tree = new Node;
            t->cld.push_back(tree);
            t->num += build_tree(tree, s);
        }
    }
    s++;
    return t->num;
}

int main(){
    int tstcase ;
    const char *ans[2] = {"different","same"};
    char *s;
    scanf("%d",&tstcase);
    while(tstcase --){
        scanf("%s", input);
        s = input;
        build_tree(&a, s);
        scanf("%s", input);
        s = input;
        build_tree(&b, s);
        printf("%s\n", ans[match(&a, &b)]);
        a.free(); b.free();
    }
    return 0;
}


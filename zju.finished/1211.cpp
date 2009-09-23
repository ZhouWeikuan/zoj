#include<iostream>
#include<map>
using namespace std;
struct Node {
    Node *par;
    string path;
    map<string, Node*> son;
    Node(){
        par = 0;
        path = "root";
    }
    Node(Node *p, const string & name){
        par = p;
        path = p->path + "\\" + name;
    }
};

Node root, *cur;

void up(){
    printf("Command: up\n");
    if (cur->par != 0){
        cur = cur->par;
    } else {
        printf("Cannot move up from root directory\n");
    }
}

void mkdir(const string &arg){
    printf("Command: mkdir   %s\n", arg.c_str());
    if (cur->son.find(arg) != cur->son.end()){
        printf("Subdirectory already exists\n");
        return;
    }
    Node *p = new Node(cur, arg);
    cur->son[arg] = p;
}

void cd(const string &arg){
    printf("Command: cd      %s\n", arg.c_str());
    if (cur->son.find(arg) == cur->son.end()){
        printf("Subdirectory does not exist\n");
        return;
    }
    cur = cur->son[arg];
}

void dir(){
    printf("Command: dir\n");
    printf("Directory of %s:\n", cur->path.c_str());
    if (cur->son.empty()){
        printf("No subdirectories\n");
        return;
    }
    int t = 0, n = 0;
    for (map<string,Node*>::iterator it=cur->son.begin(); it!=cur->son.end(); ++it){
        if (n && n%10 == 0) {
            printf("\n");
            t = 0;
            n = 0;
        }
        ++n;
        while(t&0x07){
            printf(" ");
            ++t;
        }
        printf("%s", it->first.c_str());    
        t += it->first.length();
    }
    printf("\n");
}

int main(){
    string cmd, arg;
    root.par = 0; root.path = "root";
    root.son.clear();
    cur = &root;
    printf("Problem 5 by team x\n");
    while(cin>>cmd){
        if (cmd == "up"){
            up();
        } else if (cmd == "mkdir"){
            cin>>arg;
            mkdir(arg);
        } else if (cmd == "cd"){
            cin>>arg;
            cd(arg);
        } else if (cmd == "dir"){
            dir();
        }
    }
    printf("End of problem 5 by team x\n");

    return 0;
}


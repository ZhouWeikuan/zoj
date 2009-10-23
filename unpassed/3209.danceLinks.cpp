#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
enum {
    SIZ = 32,
};

struct Node {
    Node *l, *r, *u, *d;
    int c, s;
    Node(){
        l = r = u = d = this;
        c = 0;
    }
};

Node col[SIZ];
Node root;

void remove(Node *c){
    c->r->l = c->l; 
    c->l->r = c->r;
    for (Node *i=c->d; i!=c; i=i->d){
        for (Node *j=i->r; j!=i; j=j->r){
            j->d->u = j->u; j->u->d = j->d;
            --col[j->c].s;
        }
    }
}

void restore(Node *c){
    for (Node *i=c->u; i!=c; i=i->u){
        for (Node *j=i->l; j!=i; j=j->l){
            ++col[j->c].s;
            j->d->u = j; j->u->d = j;
        }
    }
    c->r->l = c; c->l->r = c;
}

void init(){
    int Row = 6, Col = 7;
    int mat[6][7] = {
        {0, 0, 1, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 1},
    };
    root.u = root.d = root.l = root.r = &root;
    root.c = root.s = -1;
    // for column header
    for (int i=0; i<Col; ++i){
        col[i].u = col[i].d = &col[i];
        col[i].c = i; col[i].s = 0;
        root.l->r = &col[i]; col[i].l = root.l;
        root.l = &col[i]; col[i].r = &root;
    }
    // for each row
    Node *head = 0;
    for (int i=0; i<Row; ++i){
        head = 0;
        for (int j=0; j<Col; ++j){
            if (!mat[i][j]) continue;
            Node *p = new Node();
            p->c = j; p->s = 0;
            // insert to column header
            col[j].u->d = p; p->u = col[j].u;
            col[j].u = p; p->d = &col[j];
            ++col[j].s;
            // insert to row
            if (head == 0){
                head = p;
            } else {
                head->l->r = p; p->l = head->l;
                head->l = p; p->r = head;
            }
        }
    }
}

vector<int> v[SIZ];

void output(int d){
    for (int i=0; i<d; ++i){
        for (int j=0; j<v[i].size(); ++j){
            if (j) printf(" ");
            printf("%c", v[i][j] + 'A');
        }
        printf("\n");
    }
}

void search(int deep){
    if (root.r == &root){
        // find the answer;
        output(deep);
        return;
    }
    Node *c = root.r;
    remove(c);
    v[deep].clear();
    v[deep].push_back(c-col);
    for (Node *r=c->d; r!=c; r=r->d){
        for (Node *j=r->r; j!=r; j=j->r){
            remove(&col[j->c]);
            v[deep].push_back(j->c);
        }
        search(deep+1);
        for (Node *j=r->l; j!=r; j=j->l){
            restore(&col[j->c]);
            v[deep].pop_back();
        }
    }

    restore(c);
}

int main(){

    init();
    search(0);

    return 0;
}


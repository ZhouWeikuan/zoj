#include<algorithm>
#include<cstring>
#include<cctype>
#include<map>
#include<set>
#include<string>
/*  Suffix Tree is good to find Longest Repeated Substring, and its variants
 *  1) longest repeated substring, find the deepest internal node,
 *  2) longest repeated substring with at least k occurrences, find the deepest internal node
 *              with at least k desendants
 *  3) consecutive longest repeated substring, find the deepest internal node,
 *              and its desendants has difference with at most the depth.
 */
using namespace std;

enum {
    ALP = 27,
    SIZ = 50004,
    INC = SIZ/20,
};
int maxlen;

inline int getPos(char c) {
    c = tolower(c);
    return c -'a';
}
struct Node {
    Node * suff; // suffix link
    Node * tro[ALP]; //  suffix object
    int    trs[ALP]; //  start of each transition
    int    tre[ALP]; //  end  of each transition
};

struct suffixTree {
    static Node * next;
    static Node * getNode();
    static void putNode(Node *p);

    Node root, empty;
    char *tree;
    int TEND;
    void create(char *);
    void clear(Node *p);
    Node *update(Node *s, int k, int i, int&nk);
    bool test_and_split(Node *s, int k, int p, int t, Node *&ns);
    Node *canonize(Node *s, int k, int i, int &nk);
    void output(int, Node *);
    void clrs(int prelen, Node *); // consecutive longest repeated substring
};
Node * suffixTree::next = 0;

void suffixTree::putNode(Node *p){
    p->suff = next;
    next = p;
}

Node * suffixTree::getNode(){
    Node *p;
    if (next == 0){
        p = (Node*)malloc(sizeof(Node)*INC);
        for (int i=0; i<INC; ++i)
            p[i].suff = &p[i+1];
        p[INC-1].suff = 0;
        next = p;
    }
    p = next; next = next->suff;
    memset(p, 0, sizeof(*p));
    return p;
}

void suffixTree::clear(Node *p) {
    for (int i=0; i<ALP; ++i){
        if (p->tro[i] == 0) continue;
        clear(p->tro[i]);
        putNode(p->tro[i]);
    }
}

bool suffixTree::test_and_split(Node *s, int k, int p, int t, Node *&ns){
    if (k <= p){
        int v = getPos(tree[k]);
        Node *ts = s->tro[v];
        int tk = s->trs[v];
        int tp = s->tre[v];
        if (t == getPos(tree[tk+p-k+1])){
            ns = s; return true;
        }
        if (maxlen < p - tk){
            maxlen = p - tk + 1;
        }
        Node *r = getNode();
        v = getPos(tree[tk]);
        s->tro[v] = r;
        s->trs[v] = tk;
        s->tre[v] = tk+p-k;

        v = getPos(tree[tk+p-k+1]);
        r->tro[v] = ts;
        r->trs[v] = tk+p-k+1;
        r->tre[v] = tp;
        ns = r; return false;
    }
    if (s->tro[t] == 0){
        ns = s; return false;
    }
    ns = s; return true;
}

Node * suffixTree::update(Node *s, int k, int i, int &nk){
    bool end_point;
    Node *oldr = &root, *r, *nr;
    int pos = getPos(tree[i]);
    end_point = test_and_split(s, k, i-1, pos, r);
    while(!end_point){
        nr = getNode();
        r->tro[pos] = nr;
        r->trs[pos] = i;
        r->tre[pos] = TEND;
        if (oldr != &root){
            oldr->suff = r;
        }
        oldr = r;
        s = canonize(s->suff, k, i-1, nk);
        k = nk;
        end_point = test_and_split(s, k, i-1, pos, r);
    }
    if (oldr != &root) {
        oldr->suff = s;
    }
    nk = k;
    return s;
}

Node *suffixTree::canonize(Node *s, int k, int p, int &nk){
    if (p < k){
        nk = k; return s;
    }
    int pos = getPos(tree[k]);
    Node *ts = s->tro[pos];
    int tk = s->trs[pos];
    int tp = s->tre[pos];
    while(tp - tk <= p - k){
        k = k + tp - tk + 1;
        s = ts;
        if (k <= p){
            pos = getPos(tree[k]);
            ts = s->tro[pos];
            tk = s->trs[pos];
            tp = s->tre[pos];
        }
    }
    nk = k; 
    return s;
}

void suffixTree::create(char *_t){
    tree = _t;
    TEND = strlen(tree);
    tree[TEND] = 'a' + ALP - 1; // append with a character that never appears
    tree[TEND+1] = 0;
    memset(&root, 0, sizeof(root));
    memset(&empty, 0, sizeof(empty));
    empty.suff = &empty;
    for (int i=0; i<ALP; ++i){
        empty.tro[i] = &root;
        empty.trs[i] = 0;
        empty.tre[i] = 0;
    }
    root.suff = &empty;
    Node *s = &root; 
    int k = 0, i = -1, nk;
    while(tree[i+1]){
        ++i;
        s = update(s, k, i, nk);
        s = canonize(s, nk, i, k);
    }
}

void suffixTree::output(int tab, Node *p){
    for (int i=0; i<ALP; ++i){
        if (p->tro[i] == 0) continue;
        int j = 0;
        while( j < tab){
            printf("  ");
            ++j;
        }
        printf("%p -> (%d,%d) -> %p\n", p, p->trs[i], p->tre[i], p->tro[i]);
        output(tab+1, p->tro[i]);
    }
}

int clrs_ans = 0;
int ptr[ALP], pn;

void suffixTree::clrs(int prelen, Node *p){
    int i;
    bool leaf = true;
    for (i=0; i<ALP; ++i){
        if (p->tro[i] == 0) continue;
        leaf = false;
        clrs(prelen + p->tre[i] - p->trs[i] + 1, p->tro[i]);
    }
    if (!leaf && prelen > clrs_ans){
        pn = 0;
        for (i=0; i<ALP; ++i){
            if(p->tro[i]==0) continue;
            ptr[pn++] = p->trs[i];
        }
        sort(ptr, ptr+pn);
        int t, j;
        for (i=0; i<pn; ++i){
            j = upper_bound(ptr+i, ptr+pn, ptr[i]+prelen) - ptr - 1;
            if (j>i&&ptr[j]-ptr[i]>clrs_ans){
                clrs_ans = ptr[j] - ptr[i];
            }
        }
    }
}

char buf[SIZ];

int main(){
    int tn;
    scanf("%d", &tn);
    suffixTree st;
    while(tn-- > 0){
        scanf("%s", buf); 
        maxlen = 1;
        st.create(buf);
        // printf("maxlen = %d\n", maxlen);
        clrs_ans = 0;
        // st.output(0, &st.root);
        st.clrs(0, &st.root);
        printf("%d\n", clrs_ans);
        st.clear(&st.root);
    }
    return 0;
}


#include<stdio.h>

enum {
    MaxSize = 100,
};

typedef struct {
    int l;
    int w;
    int h;
} Node ;

Node box[MaxSize];
int mark[MaxSize];
int pos;
int num;

/* In Reverse Order */
int comp(const Node *b, const Node *a){
    if(a->l != b->l)
        return a->l - b->l;
    if(a->w != b->w)
        return a->w - b->w;
    return a->h - b->h;        
}

void remove_dup(){
    int i,j =0;
    for(i=1;i<pos;i++){        
        if(box[i].l != box[j].l || box[i].h != box[j].h || box[i].w != box[j].w){
            if(i != j){
                j++;
                box[j] = box[i];                
            }
        }
    } 
    j++;
    pos = j;
}

int lessthan(const Node *a, const Node *b){
    return (a->l < b->l) && (a->w < b->w);
}

int fun(){
    int i,j;
    int t;
    int sum = 0;
    
    for(i=0;i<pos;i++){
        mark[i] = box[i].h;
        for(j=i-1;j>=0;j--){
            if(lessthan(&box[i], &box[j])){
                t = box[i].h + mark[j];
                if(mark[i] < t){
                    mark[i] = t;
                }
            }
        }
        if(mark[i] > sum)
            sum = mark[i];
    }
    return sum;
}

void expand(Node *p){
    int i;
    if(p->h != p->w){
        box[pos].l = p->w;
        box[pos].w = p->h;
        box[pos].h = p->l;
        pos ++;
    }
    if(p->h != p->l) {
        box[pos].l = p->l;
        box[pos].w = p->h;
        box[pos].h = p->w;
        pos ++;
    }
}

int main(){
    int i;
    int x,y,z;
    int t;
    
    int tstcase = 0;
    
    scanf("%d",&num);    
    while(num){
        pos = 0;
        for(i=0;i<num;i++){
            scanf("%d %d %d",&x, &y, &z);
            if(z > x){
                t = x; x = z; z = t;
            }
            if( y > x){
                t = y; y = x; x = t;
            }
            if(z > y){
                t = y ; y =z ; z= t;
            }
            box[pos].l = x;
            box[pos].w = y;
            box[pos].h = z;
            pos ++;
            expand(&box[pos-1]);
        }
        qsort(box,pos,sizeof(Node),comp);
        remove_dup();
        printf("Case %d: maximum height = %d\n", ++tstcase, fun());
        
        scanf("%d",&num);    
    }
    
    return 0;
}

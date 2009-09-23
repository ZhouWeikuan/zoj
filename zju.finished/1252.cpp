#include<iostream>
using namespace std;
enum {
    SIZ = 104,
    DIV = 0,
    EVL = 1,
    HUM = 2,
};

bool timing; // true for day, false for night;
bool use[6];
int man[6];

bool isDivine(int p){
    return man[p]==DIV;
}
bool isEvil(int p){
    return man[p]==EVL;
}
bool isHuman(int p){
    return man[p]==HUM;
}
bool isLying(int p){
    return (man[p] == EVL || (man[p]==HUM && !timing));
}
bool isDay(int p){
    return timing;
}
bool isNight(int p){
    return !timing;
}

struct Node {
    int self, obj;
    bool neg;
    bool (*func)(int);
};

int num;
Node tree[60];
char buf[100];
int sm[6], st, ans;

bool good(Node &o){
    bool f = o.func(o.obj);
    if (o.neg) f = !f;
    if (isLying(o.self)){
        f = !f;
    }
    return f;
}

bool finish(){
    for (int i=0; i<num; ++i){
        if (!good(tree[i])){
            return false;
        }
    }
    return true;
}

void merge(){
    for (int i=0; i<5; ++i){
        if (!use[i]) continue;
        if (sm[i] != man[i]) sm[i] = -1;
    }
}

void check(){
    if (ans >= 2) return;
    bool a, b;
    timing = true;
    a = finish();
    timing = false;
    b = finish();
    if (a || b){
        ++ans;
        int tt = 0;
        if (ans == 1){
            memcpy(sm, man, sizeof(man));
            if (a) tt |= 2;
            if (b) tt |= 1;
            st |= tt;
        } else {
            merge();
            if (a) tt |= 2;
            if (b) tt |= 1;
            st |= tt;
        }
        tt = 0;
        for (int i=0; i<5; ++i){
            if (!use[i] || sm[i]==-1) continue;
            ++tt;
        }
        if (tt || st!=3) ans = 1;
        else ans = 2;
    }
}

void dfs(int d){
    if (d >= 5){
        check();
        return;
    }
    if (!use[d]){
        dfs(d+1);
    } else {
        for (int i=0; i<3; ++i){
            man[d] = i;
            if (ans < 2)
                dfs(d+1);
        }
    }
}

void fun(){
    ans = 0;
    st = 0;
    memset(man, 0, sizeof(man));
    dfs(0);
    if (ans == 0 || st == 0){
        printf("This is impossible.\n");
    } else if (ans > 1 && st == 3){
        printf("No facts are deducible.\n");
    } else {
        const char *type[3] = {
            "divine", "evil", "human"
        };
        for (int i=0; i<5; ++i){
            if (!use[i] || sm[i] < 0) continue;
            printf("%c is %s.\n", 'A'+i, type[sm[i]]);
        }
        if (st == 1){
            printf("It is night.\n");
        } else if (st == 2){
            printf("It is day.\n");
        }
    }
}

void proc(Node &o){
    char *p, *s, *t;
    const char *del = ": .";
    o.neg = false;
    p = strtok(buf, del);
    o.self = *p - 'A';
    p = strtok(NULL, del);
    s = strtok(NULL, del);
    if (strcmp(s, "am") == 0){
        o.obj = o.self;
    } else if (strcmp(p, "it") == 0){ // it is
        o.obj = o.self;
    } else { // A is
        o.obj = *p - 'A';
    }
    p = strtok(NULL, del);
    if (strcmp(p, "not") == 0){
        o.neg = true;
        p = strtok(NULL, del);
    }
    if (strcmp(p, "divine") == 0){
        o.func = isDivine;
    } else if (strcmp(p, "evil") == 0){
        o.func = isEvil;
    } else if (strcmp(p, "human") == 0){
        o.func = isHuman;
    } else if (strcmp(p, "lying") == 0){
        o.func = isLying;
    } else if (strcmp(p, "day") == 0){
        o.func = isDay;
    } else { // night;
        o.func = isNight;
    }
    use[o.self] = use[o.obj] = true;
}

int readIn(){
    scanf("%d ", &num);
    if (num == 0) return 0;
    memset(use, false, sizeof(use));
    for (int i=0; i<num; ++i){
        gets(buf);
        proc(tree[i]);
    }
    return 1;
}

int main(){
    int tn = 1;
    while(readIn() > 0){
        printf("Conversation #%d\n", tn++);
        fun();
        printf("\n");
    }

    return 0;
}


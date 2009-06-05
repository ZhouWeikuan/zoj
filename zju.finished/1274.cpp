#include<iostream>
#include<string>
#include<map>
using namespace std;

char *nA[12] = {
    "A", "A#", "B", "C", "C#", "D",
    "D#", "E", "F", "F#", "G","G#"
};
char *nB[12] = {
    "A", "Bb", "B", "C", "Db", "D",
    "Eb", "E", "F", "Gb", "G","Ab"
};
map<string, int> tab;
char buf[12];
int tree[3];

void init(){
    int i;
    string s;
    for(i=0; i<12; i++){
        s = nA[i];
        tab.insert(make_pair(s, i));
        s = nB[i];
        tab.insert(make_pair(s, i));
    }
}

bool Major(int a, int b, int c){
    a = tree[a];
    b = tree[b];
    c = tree[c];
    return ((b-a+12)%12 == 4 && (c-b+12)%12==3);
}
bool Minor(int a, int b, int c){
    a = tree[a];
    b = tree[b];
    c = tree[c];
    return ((b-a+12)%12==3 && (c-b+12)%12==4);
}
void fun(){
    printf(" is ");
    if(Major(0,1,2)){
        printf("a %s Major chord.", nA[tree[0]]);
    } else if(Major(1,2,0)){
        printf("a %s Major chord.", nA[tree[1]]);
    } else if(Major(2,0,1)){
        printf("a %s Major chord.", nA[tree[2]]);
    } else if(Minor(0,1,2)){
        printf("a %s Minor chord.", nA[tree[0]]);
    } else if(Minor(1,2,0)){
        printf("a %s Minor chord.", nA[tree[1]]);
    } else if(Minor(2,0,1)){
        printf("a %s Minor chord.", nA[tree[2]]);
    } else {
        printf("unrecognized.");
    }
    printf("\n");
}

int readIn(){
    int i;
    string s;
    for(i=0; i<3; i++){
        if(scanf("%s", buf)<0)
            return 0;
        printf("%s%s", (i?" ":""),buf);
        buf[0] = toupper(buf[0]);
        s = buf;
        tree[i] = tab[s];
    }
    sort(tree, tree+3);
    return 1;
}
int main(){
    init();
    while(readIn()>0){
        fun();
    }
    return 0;
}


#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Rect{
    int x,y;
    void norm(){
        if(x > y){
            swap(x, y);
        }
    }
};
vector<Rect> face;
int edge[3];
bool trim(int a, int b){
    int cnt = 0;
    for(int i=0; cnt<2&&i<face.size();i++){
        if(face[i].x == edge[a] && face[i].y == edge[b]){
            cnt++;
            face[i].x = face[i].y = -1;
        }
    }
    return (cnt==2);
}
int fun(){
    int i;
    map<int, int> tab;
    for(i=0; i<face.size(); i++){
        tab[face[i].x]++;
        tab[face[i].y]++;
    }
    i = 0;
    for(map<int, int>::iterator it=tab.begin(); it!=tab.end(); it++){
        if(it->second%4!=0) return 0;
        while(it->second){
            edge[i++] = it->first;
            it->second -= 4;
        }
    }
    return trim(0,1)&&trim(0,2)&&trim(1,2);
}
int readIn(){
    Rect r;
    if(scanf("%d%d", &r.x, &r.y)<0)
        return 0;
    face.clear();
    r.norm();
    face.push_back(r);
    for(int i=1; i<6; i++){
        scanf("%d%d", &r.x, &r.y);
        r.norm();
        face.push_back(r);
    }
    return 1;
}
int main(){
    const char *ans[2] = {"IMPOSSIBLE", "POSSIBLE"};
    while(readIn() > 0){
        printf("%s\n", ans[fun()]);
    }
    return 0;
}

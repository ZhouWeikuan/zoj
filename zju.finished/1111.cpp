#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
enum {
    SIZ = 5,
};
const char cStr[] = "JQKA";
int getVal(char c){
    int i;
    if (isdigit(c)){
        return c-'0';
    }
    for (i=0; cStr[i] && cStr[i]!=c; ++i)
        ;
    if (cStr[i]) return 11 + i;
}
char buf[10];
struct Card {
    int val;
    char type;
    bool read(){
        if (scanf("%s", buf) <= 0) return false;
        type = buf[1];
        val = getVal(buf[0]);
        return true;
    }
    bool operator <(const Card&o)const{
        return val < o.val;
    }
};
struct Node {
    Card car[5];
    vector<int> vec;
    bool read(){
        for (int i=0; i<5; ++i){
            if(!car[i].read())
                return false;
        }
        sort(car, car+5);
        vec.clear();
        return true;
    }
    int cmp(const Node&o){
        int i;
        for (int i=0; i<vec.size()&&i<o.vec.size(); ++i){
            if (vec[i] != o.vec[i])
                return vec[i] - o.vec[i];
        }
        return 0;
    }
    int calcMost(){
        int m = 0, v=1;
        for(int i=0; i<4; ++i){
            if (car[i].val == car[i+1].val){
                ++v;
            }else {
                v = 1;
            }
            if (m < v) m = v;
        }
        return m;
    }
    bool StraightFlush(){
        for(int i=0; i<4; ++i){
            if(car[i].type!=car[i+1].type || car[i].val+1 != car[i+1].val)
                return false;
        }
        vec.push_back(10);
        vec.push_back(car[4].val);
        return true;
    }
    bool FourKind(){
        int v = calcMost();
        if (v < 4)
            return false;
        vec.push_back(9);
        if (car[0].val != car[1].val)
            vec.push_back(car[1].val);
        else if(car[3].val != car[4].val)
            vec.push_back(car[3].val);
        return true;
    }
    bool FullHouse(){
        int v = calcMost();
        if (v != 3) return false;
        if (car[0].val==car[1].val && car[1].val != car[2].val){
            vec.push_back(8);
            vec.push_back(car[2].val);
            vec.push_back(car[1].val);
            return true;
        } else if (car[3].val==car[4].val && car[2].val!=car[3].val){
            vec.push_back(8);
            vec.push_back(car[2].val);
            vec.push_back(car[3].val);
            return true;
        }
        return false;
    }
    bool Flush(){
        int i;
        for (i=0; i<4; ++i)
            if (car[i].type != car[i+1].type) return false;
        vec.push_back(7);
        for (i=4; i>=0; --i){
            vec.push_back(car[i].val);
        }
        return true;
    }
    bool Straight(){
        for(int i=0; i<4; ++i){
            if (car[i].val+1!=car[i+1].val) return false;
        }
        vec.push_back(6);
        vec.push_back(car[4].val);
        return true;
    }
    bool ThreeKind(){
        int v = calcMost();
        if (v != 3) return false;
        vec.push_back(5);
        if (car[0].val == car[1].val){
            vec.push_back(car[1].val);
        }else if(car[1].val == car[2].val){
            vec.push_back(car[1].val);
        }else if(car[2].val == car[3].val){
            vec.push_back(car[3].val);
        }else if(car[3].val == car[4].val){
            vec.push_back(car[3].val);
        }
        return true;
    }
    bool TwoPair(){
        int v = calcMost();
        if (v!=2) return false;
        vec.push_back(4);
        if (car[0].val == car[1].val){
            if (car[2].val==car[3].val){
                vec.push_back(car[3].val);
                vec.push_back(car[0].val);
                vec.push_back(car[4].val);
                return true;
            }else if(car[3].val==car[4].val){
                vec.push_back(car[3].val);
                vec.push_back(car[0].val);
                vec.push_back(car[2].val);
                return true;
            }
        } else if(car[1].val==car[2].val && car[3].val==car[4].val){
            vec.push_back(car[4].val);
            vec.push_back(car[2].val);
            vec.push_back(car[0].val);
            return true;
        }
        vec.clear();
        return false;
    }
    bool Pair(){
        int v = calcMost();
        if (v!=2) return false;
        int i;
        for (i=0; i<3; ++i){
            if (car[i].val == car[i+1].val)
                break;
        }
        vec.push_back(3);
        for (int j=4; j>=0; --j){
            if (j==i||j==i+1) continue;
            vec.push_back(car[j].val);
        }
        return true;
    }
    bool HighCard(){
        vec.push_back(2);
        for (int i=4; i>=0; --i)
            vec.push_back(car[i].val);
        return true;
    }

    void rank(){
        vec.clear();
        if (StraightFlush()){
        }else if(FourKind()){
        }else if(FullHouse()){
        }else if(Flush()){
        }else if(Straight()){
        }else if(ThreeKind()){
        }else if(TwoPair()){
        }else if(Pair()){
        }else if(HighCard()){
        }
    }
};

Node b, w;

void fun(){
    b.rank();
    w.rank();
    int t = b.cmp(w);
    if (t > 0){
        printf("Black wins.\n");
    } else if (t < 0){
        printf("White wins.\n");
    } else {
        printf("Tie.\n");
    }
}

int readIn(){
    if (!b.read())
        return false;
    if (!w.read())
        return false;
    return true;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}


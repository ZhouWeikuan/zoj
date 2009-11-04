#include<cstdio>
#include<map>
#include<vector>
#include<cstring>

using namespace std;
struct metaObject {
    char from;
    char end;
    char type; // -1 for any, 0 for single, 1 for range, 2 for range not;
    char stick; // 0 for null, 1 for *, 2 for +
};
enum {
    SIZ = 84
};
vector<metaObject> pat;
char buf[SIZ];
int pos;

void parse_range(int &i, metaObject &o){
    o.type = 1;
    i ++;
    if(buf[i] =='^'){
        i++; o.type ++;
    }
    if(buf[i] =='\\'){
        i++;
    }
    o.from = buf[i];
    i += 2;
    if(buf[i] =='\\'){
        i++;
    }
    o.end = buf[i];
    if(o.end < o.from){
        int t = o.end; o.end = o.from; o.from = t;
    }
    i++;
}

char trim_one(int &i){
    if(buf[i] =='.'){
        return -1;
    }
    if(buf[i] == '\\'){
        i++;
        return buf[i];
    }
    return buf[i];
}
void parse(){
    int i= 0,t;
    char ch;
    metaObject obj;
    pat.clear();
    while(buf[i]){
        memset(&obj,0,sizeof(obj));
        if(buf[i]=='['){
            parse_range(i,obj);
        } else {
            ch = trim_one(i);
            obj.from = obj.end = ch;
            if(ch < 0)
                obj.type = -1;
        }
        i++;
        t = 0;
        while(buf[i] == '*' || buf[i] == '+'){
            if(buf[i] =='*'){
                if(t ==0)
                    t = 1;
            } else {
                if(t ==0)
                    t = 2;
            }
            i++;
        }
        if(t == 1){
            obj.stick = 1;
        } else if(t > 1){
            obj.stick = 2;
        }

        pat.push_back(obj);
    }
}

map<int,int> tab;
map<int,int>::iterator iter;

int match(metaObject &o, char ch){
    if(o.type < 0){
        return ch!=0;
    }
    if(o.type == 0){
        return ch==o.from;
    }
    if(o.type == 1){
        return (ch<=o.end)&&(ch>=o.from);
    }
    return ch && (ch<o.from || ch>o.end);
}
// 0 正常终止， -1,不正常终止
//a for metaobject, b for buf
int calc(int a, int b){
    if(a>= pat.size()){
        return 0;
    }
    if(b > pos){
        return -1;
    }
    int key = (a<<8) +b;
    int val = -1;
    iter = tab.find(key);
    if(iter != tab.end() ){
        return iter->second;
    }
    metaObject & o = pat[a];
    if(o.stick == 0){
        if(match(o, buf[b])){
            val = calc(a+1,b+1); 
            if(val >=0)
                val ++;
        } else {
            val = -1;
        }
    } else if(o.stick == 1){
        val = calc(a+1,b);

        if(match(o,buf[b])){
            int t = calc(a+1,b+1);
            if(t>=0)
                t++;
            if(t > val)
                val = t;
            t = calc(a,b+1);
            if(t >=0)
                t++;
            if(t>val)
                val = t;
        }
    } else {
        if(match(o,buf[b])){
            val = calc(a+1,b+1);
            if(val >= 0)
                val++;
            int t = calc(a, b+1);
            if(t >=0)
                t++;
            if(t > val)
                val = t;
        }
    }
    return tab[key] = val;
}

void fun(){
    int start = 0, len=0;
    int t,i;
    tab.clear();
    for(i=0;i < pos;i++){
        t = calc(0,i);
        if(t > len){
            start = i;
            len = t;
            break;
        }
    }
    while(buf[start + len-1] == 0){
        len --;
    }
    if(len <=0){
        printf((char*)buf);
        printf("\n");
        return;
    }
    for(i=0;i<start;i++)
        printf("%c",buf[i]);
    printf("(");
    for(i=0;i<len;i++)
        printf("%c",buf[start+i]);
    printf(")");
    for(i=start+len;i<pos;i++)
        printf("%c",buf[i]);
    printf("\n");
}

int main(){

    fgets((char*)buf,SIZ,stdin);
    pos = strlen((char*)buf);
    if(buf[pos-1] =='\n')
        buf[--pos] = 0;
    while(strcmp((char*)buf,"end")!=0){
        parse();
        fgets((char*)buf,SIZ,stdin);
        pos = strlen((char*)buf);
        if(buf[pos-1] =='\n')
            buf[--pos] = 0;

        fun();

        fgets((char*)buf,SIZ,stdin);
        pos = strlen((char*)buf);
        if(buf[pos-1] =='\n')
            buf[--pos] = 0;

    }

	return 0;
}

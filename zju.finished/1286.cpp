#include<iostream>
using namespace std;
enum {
    SIZ = 80,
};
char buf[SIZ];

int slump(char *s){
    int ans = 0;
    if(s[0] !='D' && s[0] != 'E')
        return -1;
    if(s[1] != 'F')
        return -1;
    int i = 2;
    while(s[i]== 'F'){
        i++;
    }
    if(s[i] == 'G'){
        ans = i + 1;
    } else {
        ans = slump(&s[i]);
        if(ans == -1)
            return -1;
        ans += i;
    }
    return ans;
}
size_t slimp(char *s){
    int ans = 0;
    if(s[0] != 'A')
        return -1;
    if(s[1] =='H')
        return 2;
    if(s[1] =='B'){
        ans = slimp(&s[2]);
        if(ans < 0)
            return -1;
        ans += 2;
        if(s[ans] == 'C'){
            return ++ans;
        }
        return -1;
    }
    ans = slump( &s[1]);
    if(ans < 0)
        return -1;
    ans += 1;
    if(s[ans] == 'C')
        return ++ ans;
    return -1;
}

int slurpys(char *s){
    int len = strlen(s);
    int ans;
    ans = slimp(s);
    ans += slump(&s[ans]);
    if(ans == len)
        return 1;
    return 0;
}

int fun(){
    if(slurpys(buf)){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main(){
    int t;
    cin>>t;
    printf("SLURPYS OUTPUT\n");
    while(t --){
        cin>>buf;
        fun();
    }
    printf("END OF OUTPUT\n");
    
	return 0;
}

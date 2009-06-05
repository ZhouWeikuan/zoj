#include<iostream>
#include<cstring>
#include<map>

using namespace std;
map<int,int> cata;
char preorder[28];
char postorder[28];
int forknum;
int maxlen;

int calc(int m, int k){
    int key = (m<<8) + k;
    if(k>m)
        return 0;
    if(cata.end() != cata.find(key)){
        return cata[key];
    }
    if(k > m-k){
        k = m-k;
    }
    int sum = 1;
    int i;
    for(i=1;i<=k;i++){
        sum *= (m - k + i);
        sum /= i;
    }
    cata[key] = sum;
    return sum;
}
/*find the match in postorder*/
int match(char c,int s, int e){
    int i;
    for(i=s;i<e;i++){
        if(postorder[i] == c){
            return (i-s + 1);
        }
    }
    return -1;
}

int parse(int s, int e, int ps, int pe){
    int ret = 1;
    int i,j,k = 0;
    if(e-s != pe -ps)
        return 0;
    if(e - s ==1){
        return 1;
    }
    if(preorder[s] != postorder[pe-1])
        return 0;
    s++;    
    pe --;
    while(s < e){
        i = match(preorder[s],ps,pe);        
        if(i == -1){
            return 0;
        }
        k++;
        ret *= parse(s,s+i,ps,ps+i);
        if(ret ==0)
            return 0;
        s+= i;
        ps+=i;
    }
    ret *= calc(forknum,k);
    return ret;
}

int main(){
    int num;
    
    cin>>forknum;
    while(forknum){        
        cin>>preorder>>postorder;
        maxlen=strlen(preorder);
        
        num = parse(0,maxlen,0,maxlen);
        cout<<num<<endl;
        
        cin>>forknum;
    }
    
    return 0;
}

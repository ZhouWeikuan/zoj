#include<iostream>
#include<cstring>

using namespace std;
char minstr[200];

void convert(char *s, int n){//convert s[] to mininum expression and saved in minstr[]
    memmove(minstr, s, n);
    memmove(minstr + n, s, n);
    int i = 0, j =1, k = 0;
    int t = 0;
    while(k < n && i< n && j < n){
        if(minstr[i + k] == minstr[j + k]){
            k ++;
        }else if(minstr[i + k] < minstr[j + k]){
            t = i;
            j += k + 1;
            k = 0;
        } else { // >
            t = j;
            i += k + 1;
            if(i == j){
                j++;
            }
            k = 0;
        }
    }
    memmove(minstr, minstr+t,n);
    minstr[n] = 0;
}

int main(){
    
    while(cin>>minstr){
        convert(minstr, strlen(minstr));
        cout<<minstr<<endl;
    }

}

#include<iostream>

using namespace std;
char input[100];

int leftRun(int cur){
    while(cur >= 0){
        switch(input[cur]){
        case '.':
            return 2;
        case '/':
        case '\\':
        case '|':
            return 0;
        case '_':
            break;
        }
        cur --;
    }
    return 2;
}

int rightRun(int cur){
    while(input[cur]){
        switch(input[cur]){
        case '.':
            return 2;
        case '/':
        case '\\':
        case '|':
            return 0;
        case '_':
            break;
        }
        cur ++;
    }
    return 2;
}

int get_score(int cur){
    int t;

    switch(input[cur]){
    case '.':
        return 2;
    case '_':
        return 0;
    case '/':
        return leftRun(cur-1);
    case '\\':
        return rightRun(cur+1);
    case '|':
        t = 0;
        t += leftRun(cur-1);
        t += rightRun(cur+1);
        t /= 2;
        return t;
    }

    return 0;
}

int fun(){
    int i;
    int score = 0;
    for(i=0; input[i]; i++){
        score += get_score(i);
    }
    score *= 50;
    score /= i;
    return score;
}

int main(){

    cin>>input;
    while(input[0] != '#'){
        cout<<fun()<<endl;
        
        cin>>input;
    }

	return 0;
}

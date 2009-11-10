#include<cstdio>

using namespace std;
int num;
double dis;
char buf[20];

int get_time(){
    if(buf[0] == '-')
        return -1;
    int h = buf[0] - '0';
    int m = buf[2] - '0';
    m *= 10;
    m += buf[3] - '0';

    int s = buf[5] - '0';
    s *= 10;
    s += buf[6] - '0';
    h *= 60;
    m += h;
    m *= 60;
    s += m;
    return s;
}

int get_total(){
    int ret = 0;
    int t;
    for(int i=0;i<num;i++){
        scanf("%s", buf);
        t = get_time();
        if(t > 0 && ret >= 0){
            ret += t;
        } else {
            ret = -1;
        }
    }
    return ret;
}

void fun(){
    int sec = get_total();
    double t;
    if(sec <= 0){
        printf("-\n");
        return;
    }
    
    t   = sec / dis;
    sec = (int) t;
    t   -= sec;
    if(t >= 0.5)
        sec ++;
    int min = sec / 60;
    sec %= 60;
    printf("%d:%02d min/km\n", min, sec);
}

int main(){
    int t;
    scanf("%d%lf", &num, &dis);
    while(scanf("%d",&t) > 0){
        printf("%3d: ", t);
        fun();
    }
	return 0;
}

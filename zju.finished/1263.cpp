#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
enum {
    SIZ = 104,
    DAY = 24*60*60,
    YEAR = 365*DAY,
};

struct tm  s, e;
int unit_num;
char unit_str[SIZ];
int mDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int readTime(struct tm &o){
    if (scanf("%d%d%d%d%d%d", &o.tm_year, &o.tm_mon, 
            &o.tm_mday, &o.tm_hour, &o.tm_min, &o.tm_sec) < 0)
            return -1;
    --o.tm_mon;
    return 0;
}

bool isLeap(int y){
    return (y%400==0) || (y%100!=0 && y%4==0);
}
time_t sec_in_year(struct tm &t){
    time_t ret = 0;
    int m = 0;
    while(m < t.tm_mon){
        ret += DAY * mDays[m];
        if (m==1 && isLeap(t.tm_year)) ret += DAY;
        ++m;
    }
    ret += (t.tm_mday - 1) * DAY;
    ret += t.tm_hour * 60 * 60;
    ret += t.tm_min * 60;
    ret += t.tm_sec;
    return ret;
}

time_t diff(struct tm &a, struct tm &b){
    time_t ret = sec_in_year(b) - sec_in_year(a);
    int y = a.tm_year;
    while(y < b.tm_year){
        ret += YEAR;
        if (isLeap(y)) ret += DAY;
        ++y;
    }
    return ret;
}

void fun(){
    if (strcmp(unit_str, "second") == 0){
        time_t d = diff(s, e);
        d /= unit_num;
        printf("%d\n", d);
        return;
    } 
    if (s.tm_sec) s.tm_min++, s.tm_sec = 0;
    e.tm_sec = 0;
    if (strcmp(unit_str, "minute") == 0){
        time_t d = diff(s, e);
        d /= 60;
        d /= unit_num;
        printf("%d\n", d);
        return ;
    } 
    if (s.tm_min) s.tm_hour++, s.tm_min = 0;
    e.tm_min = 0;
    if (strcmp(unit_str, "hour") == 0){
        time_t d = diff(s, e);
        d /= 60 * 60;
        d /= unit_num;
        printf("%d\n", d);
        return ;
    }
    if (s.tm_hour) s.tm_mday++, s.tm_hour = 0;
    e.tm_hour = 0;
    if (strcmp(unit_str, "day") == 0){
        time_t d = diff(s, e);
        d /= 24*60*60;
        d /= unit_num;
        printf("%d\n", d);
        return ;
    } 
    if (s.tm_mday > 1) s.tm_mon++, s.tm_mday = 1;
    e.tm_mday = 1;
    if (strcmp(unit_str, "month") == 0){
        time_t d = 0;
        while (s.tm_year < e.tm_year){
            d += 12;
            ++s.tm_year;
        }
        d += (e.tm_mon - s.tm_mon);
        d /= unit_num;
        printf("%d\n", d);
        return ;
    } 
    if (s.tm_mon) s.tm_year++, s.tm_mon = 0;
    e.tm_mon = 0;
    if (strcmp(unit_str, "year") == 0){
        time_t d = 0;
        while (s.tm_year < e.tm_year){
            ++d;
            ++s.tm_year;
        }
        d /= unit_num;
        printf("%d\n", d);
    } else {
        printf("unknown\n");
    }
}

int readIn(){
    if (readTime(s) < 0) return 0;
    readTime(e);
    scanf("%d%s", &unit_num, unit_str);
    return 1;
}

int main(){
    while(readIn() > 0){
        fun();
    }

    return 0;
}


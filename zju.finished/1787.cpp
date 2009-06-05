#include<cstdio>
#include<cstdlib>

using namespace std;
struct Box {
    short l;
    short m;
};
enum {
    SIZ = 10004,
};
Box box[SIZ];
int num;
int sum[SIZ],top;

int cmp(const Box *a, const Box *b){
    if(a->l == b->l)
        return a->m - b->m;
    return a->l - b->l;
}

int find(int low,int high, int v){
	if(high <= low)
		return -1;
	int mid;
	while(low < high){
		mid = (low + high)/2;
		if(sum[mid] <= v){ //lower
			low = mid + 1;
		} else { //higher
			high = mid;
		}
	}
	while(sum[mid] > v){
		mid--;
	}
	while(sum[mid] <= v){
		mid++;
	}
	return mid;
}

int fun(){
	int i,t;
	top = -1;
	sum[++top] = box[0].m;
	for(i=1;i<num;i++){
		if(sum[top] <= box[i].m){
			sum[++top] = box[i].m;
		} else {
			t = find(0,top+1, box[i].m);	
			sum[t] = box[i].m;
		}
	}
	return ++top;
}



int main(){
    
    scanf("%d ", &num);
    while(num > 0){
        for(int i=0;i<num;i++){
            scanf("%d%d ",&box[i].l, &box[i].m);
        }
        qsort(box, num, sizeof(Box), 
                (int(*)(const void*,const void*))cmp);

        printf("%d\n", fun());

        scanf("%d ", &num);
    }
    printf("*\n");

	return 0;
}

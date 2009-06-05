#include<stdio.h>
/***************************************************************
Algorithm Complexity O(nlogn) 
****************************************************************/

int array[20] = { 3, 2, 4, 1, 7, 6, 8, 5,9,10,11,12};
int num= 12;
int bis[20];
int pos = 0;

int insert(int e){
	int mid, hi,low;
	hi = pos;
	low = 0;
	
	/* find the k that bis[k] < e , bis[k+1] >e || k+1 == pos */
	while(hi > low){
		mid = (hi+low)/2;
		if(bis[mid] > e){
			hi = mid;
		} else if(bis[mid] < e){
			low = mid + 1;
		} else { /* bis[mid] == e, no process here */
		}
	}
	if(hi == low)
		mid = hi;
	
	if(mid < pos && bis[mid] < e){
		mid ++;
	}
	if(mid == pos){
		bis[pos++] = e;
	} else {
		bis[mid] = e;
	}	
}

int getmax(){
	int i;
	int t;
	bis[pos++] = array[0];
	
	for(i=1;i<num;i++){
		insert(array[i]);		
	}
}

int main(){
	
	getmax();
	printf("%d\n", pos);
		
}

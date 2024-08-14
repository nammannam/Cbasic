#include<stdio.h>
#define MAX (255)


int checkArr(int A[], int B[], int m, int n){
//	if(m != n){
//		return 0;
//	}else if(m == n){
//		int i, check = 0; // FLAG
//		for(i = 0 ; i < m; i++){
//			if(*(ptr1 + i ) == *(ptr2 + i)){		
//				check++;
//			}
//		}
//		if(check == m){
//			return 1;
//		}else{
//			return 0;
//		}
//	}
//	
	if(m != n)
		return 0;
		
		int i;
		for(i = 0 ; i < m ; i++)
			if(A[i] != B[i]) return 0;
			
		return 1;
	
	
}


int main(){
	int n,m;
	printf("Nhap so phan tu mang 1 va 2: ");
	scanf("%d %d", &m,&n);
//	int a1[m], a2[n]; //SAI
	
	int a1[MAX], a2[MAX];
	
	
	int i;
	printf("Nhap phan tu mang 1: ");
	for(i = 0 ; i < m ; i++)
		scanf("%d", &a1[i]);
	printf("Nhap phan tu mang 2: ");	
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a2[i]);
	
	printf("KET QUA: %d",checkArr(a1, a2, m, n));
	
	return 0;
}

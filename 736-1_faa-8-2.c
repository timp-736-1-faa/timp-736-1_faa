#define SWAP(a , b) if(a != b) a = a ^ b , b = b ^ a , a = a ^ b;

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void ArrPyraArr(int* massiv , int n){
	int indfir = n/2;
	while( (--indfir) >= 0){
		if( massiv[indfir * 2 + 1] <= massiv[indfir * 2 + 2]){
			if(massiv[indfir] > massiv[indfir * 2 + 1])
				SWAP( massiv[indfir] , massiv[indfir * 2 + 1])
		}
		else
			if(massiv[indfir] > massiv[indfir * 2 + 2])
				SWAP(massiv[indfir] , massiv[indfir * 2 + 2])
	}
}    

void HeapSort(int* massiv , int n){
	int index = 0;
	while( (--n) > 0){
		SWAP(massiv[0] , massiv[n])
		ArrPyraArr(massiv , n-1);
	}
}
	
int main(){
	int n;
	scanf("%d" , &n);
	int *a = malloc(n*sizeof(int));
	for( int i = 0; i < n; ++i)
		scanf("%d" , &a[i]);
	ArrPyraArr(a , n);
	HeapSort( a , n);
	for(int i = 0; i < n; ++i)
		printf(" %d" , a[i]);
	printf("\n");

}

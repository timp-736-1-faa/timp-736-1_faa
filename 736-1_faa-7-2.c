#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void shellcomb(int* massiv , int n){
        int buff;
        int max;
        int indexmax;
        for(int i = n/2; i >= 1; i /= 2){
                for(int j = 0 ; j < n; ++j){
                        max = massiv[j];
                        for(int d = j; d+i < n; d +=i){
                                if(max < massiv[d+i])
                                        buff = massiv[j] , massiv[j] = massiv[d+i] , max = massiv[d+i] , massiv[d+i] = buff;

                        }
                }
        }
}


int main(){
	int n;
        scanf("%d" , &n);
        int *b = malloc(sizeof(int)*n);
        for(int i = 0; i < n; ++i)
                scanf("%d" , &b[i]);
        shellcomb(b , n);
        for(int i = 0; i < n; i++)
                printf("%d " , b[i]);
        printf("\n");
}

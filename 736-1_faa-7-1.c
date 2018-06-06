#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void combsort(int* massiv , int n){
        const float step = 1.247330950103979f;
        int buff = 0;
        for(int i = n ;i >= 1 ;i = i/step)
                for(int j = 0 ; j+i < n; ++j){
                        if(massiv[j] < massiv[j+i])
                                buff = massiv[j+i] , massiv[j+i] = massiv[j] , massiv[j] = buff;
                }
}

int main(){
	 int n;
        scanf("%d" , &n);
        int *a = malloc(sizeof(int)*n);
        for(int i = 0; i < n; ++i)
                scanf("%d" , &a[i]);
        combsort(a , n);
        for(int i = 0; i < n; i++)
                printf("%d " , a[i]);
        free(a);
        printf("\n");
}

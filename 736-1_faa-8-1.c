#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void hoarcomb(int *a , int first , int last){
	int mediane = a[(first + last)/2];
	int indfi = first - 1;
	int buff;
	int indla = last + 1;
	while(1){
		do{
			indfi++;
	
		}while(a[indfi] < mediane);	
		do{
			indla--;
		
		}while(a[indla] > mediane);
		if(indfi >= indla)
			break;
		buff = a[indfi] , a[indfi] = a[indla] , a[indla] = buff;
	}
	if(first < indla) hoarcomb(a , first , indla);
	if(indfi < last) hoarcomb(a , indla + 1 , last);	
}

int main(){
	int n;
	scanf("%d" , &n);
	int *a = malloc(n*sizeof(int));
	for(int i = 0; i < n; i++)
		scanf("%d" , &a[i]);
	hoarcomb(a , 0 , n-1);
	for(int i =0; i < n; ++i)
		printf("%d " , a[i]);
	free(a);
	printf("\n");
}

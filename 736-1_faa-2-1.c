#include <stdio.h>

int main()
{
	int x;
	int max= -2147483647;
	int n;
	scanf("%d",&n);
	for (int i=0; i<n;++i)
	{
		scanf("%d",&x);
		if(x>max)
		{		
			max=x;
		}
	};
	printf("%d\n",max);
	return 0;
}

#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	double x;
	double sum=0;
	scanf("%d",&n);
	for (int i=1; i<=n;++i)
	{
		scanf("%lf",&x);
		sum+=(i%2)*x*x;
	}
	printf("%.20lf\n",sum);
	return 0;
} 

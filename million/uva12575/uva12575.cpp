#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	double A,B;
	double pi = acos(-1.0);
	while( kase-- ){
		
		scanf("%lf %lf",&A,&B);
		if( A == 0.0 && B == 0.0 ){
			printf("0.00 0.00\n");
			continue;
		}

		double radian;
		double F = sqrt(A*A+B*B);

		for(radian = atan(A/B) ; radian <= 2*pi ; radian += pi/2 )
			if( fabs(A*sin(radian)+B*cos(radian)-F) < 0.01 && radian >= 0 )
				break;

		printf("%.2lf %.2lf\n",radian,F);

	}
	
	return 0;
}
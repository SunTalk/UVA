#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	double x,y,r;
	while( kase-- ){
		scanf("%lf %lf %lf", &x, &y, &r);
		double dis = sqrt(x*x + y*y);
		printf("%.2lf %.2lf\n", r-dis, r+dis);
	}

	return 0;
}
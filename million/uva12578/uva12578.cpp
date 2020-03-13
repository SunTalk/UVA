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

	double L,W,R;
	double pi = acos(-1.0);
	while( kase-- ){

		scanf("%lf",&L);
		W = L*0.6;
		R = L*0.2;
		double red = R*R*pi;
		double green = L*W - red;
		printf("%.2lf %.2lf\n",red,green);

	}

	return 0;
}
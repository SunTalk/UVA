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

	int num;
	double start,end;
	while( kase-- ){

		scanf("%d",&num);
		scanf("%lf %lf",&start,&end);
		double tmp,ans = 0.0;
		for(int i = 1 ; i <= num ; i++ ){
			scanf("%lf",&tmp);
			ans += 2.0*(num+1-i)*tmp;
		}

		ans = (num*start + end - ans)/(num+1);
		printf("%.2lf\n",ans);
		if( kase ) printf("\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11479"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);

	int Case = 1;
	long long tri[5];

	while( kase-- ){

		scanf("%lld %lld %lld",&tri[0],&tri[1],&tri[2]);
		sort(&tri[0],&tri[3]);
		
		printf("Case %d: ",Case++ );
		if( tri[0]+tri[1] > tri[2] ){
			if( tri[0] == tri[1] && tri[1] == tri[2] )
				printf("Equilateral\n");
			else if( tri[0] == tri[1] || tri[1] == tri[2] )
				printf("Isosceles\n");
			else
				printf("Scalene\n");
		}
		else
			printf("Invalid\n");

	}

	return 0;
}
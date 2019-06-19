#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11764"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE,Case = 1;
	scanf("%d",&CASE);

	int num,tmp,re;
	int A,B;
	while( CASE-- ){
		scanf("%d",&num);
		
		A = B = 0;
		scanf("%d",&re);
		for(int i = 1 ; i < num ; i++ ){
			scanf("%d",&tmp);
			if( tmp > re )
				A++;
			if( tmp < re )
				B++;
			re = tmp;
		}
		printf("Case %d: %d %d\n",Case++,A,B );
	}

	return 0;
}
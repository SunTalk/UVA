#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11854"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int tri[5];

	while( ~scanf("%d %d %d",&tri[0],&tri[1],&tri[2]) && tri[0] ){
		sort(&tri[0],&tri[3]);
		if( tri[0]*tri[0]+tri[1]*tri[1] == tri[2]*tri[2] )
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
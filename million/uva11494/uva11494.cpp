#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11494"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int x,y,x2,y2;

	while( ~scanf("%d %d %d %d",&x,&y,&x2,&y2) && x ){
		if( x == x2 && y == y2 )
			printf("0\n");
		else if( abs(x-x2) == abs(y-y2) || x == x2 || y == y2 )
			printf("1\n");
		else
			printf("2\n");
	}

	return 0;
}
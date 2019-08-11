#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11044"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int x,y;

	while( kase-- ){
		scanf("%d %d",&x,&y);
		printf("%d\n", (x/3)*(y/3) );
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11936"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int tri[5];

	while( kase-- ){

		scanf("%d %d %d",&tri[0],&tri[1],&tri[2]);
		sort(&tri[0],&tri[3]);

		if( tri[0] + tri[1] > tri[2] )
			printf("OK\n");
		else
			printf("Wrong!!\n");

	}

	return 0;
}
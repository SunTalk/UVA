#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10963"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);

	int num,check;
	int a,b;
	bool ans;

	while( kase-- ){

		scanf("%d",&num);
		ans = true;

		scanf("%d %d",&a,&b);
		check = a-b;

		for(int i = 1 ; i < num ; i++ ){
			scanf("%d %d",&a,&b);
			if( a-b != check )
				ans = false;
		}

		if( ans )
			printf("yes\n");
		else
			printf("no\n");
		
		if( kase )
			printf("\n");

	}

	return 0;
}
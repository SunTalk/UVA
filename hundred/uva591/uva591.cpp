#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "591"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number,i;
	int total,ans;
	int Case = 1;

	while( ~scanf("%d",&number) && number ){
		int block[number];
		ans = total = 0;

		for( i = 0 ; i < number ; i++ ){
			scanf("%d",&block[i]);
			total = total + block[i];
		}

		total = total/number;

		for( i = 0 ; i < number ; i++ ){
			if(block[i] > total)
				ans = ans + block[i] - total;
		}

		printf("Set #%d\n",Case );
		Case++;
		printf("The minimum number of moves is %d.\n\n",ans );

	}

	return 0;
}
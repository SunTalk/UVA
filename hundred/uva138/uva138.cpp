#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "138"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	// for(long long i = 2 ; i < 100000000 ; i++ ){
	// 	long long k = i*(i+1)/2;
	// 	if( sqrt(k) == (long long)sqrt(k) )
	// 		printf("%10lld%10lld\n", (long long)sqrt(k),i );
	// }

	printf("         6         8\n");
	printf("        35        49\n");
	printf("       204       288\n");
	printf("      1189      1681\n");
	printf("      6930      9800\n");
	printf("     40391     57121\n");
	printf("    235416    332928\n");
	printf("   1372105   1940449\n");
	printf("   7997214  11309768\n");
	printf("  46611179  65918161\n");

	return 0;
}
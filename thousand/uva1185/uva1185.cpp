#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[MAXN+10];

int main(int argc, char const *argv[])
{

	double ans = 0.0;
	for(int i = 1 ; i < MAXN+5 ; i++ ){
		ans += log10(i);
		table[i] = int(ans)+1;
	}

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){
		scanf("%d",&num);
		printf("%d\n",table[num]);
	}

	return 0;
}
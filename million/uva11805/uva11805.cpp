#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d", &kase);
	int CASE = 1;
	int N,K,P;

	while( ~scanf("%d %d %d",&N,&K,&P) ){
		int ans = (K+P)%N;
		printf("Case %d: %d\n", CASE++, ans==0?N:ans);
	}

	return 0;
}
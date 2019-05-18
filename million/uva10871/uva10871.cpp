#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10871"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000

bool isPrime(int k){
	for(int i = 2 ; i <= sqrt(k) ; i++ )
		if( k%i == 0 )
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int table[MAXN+5];
	int num;

	while( CASE-- ){

		scanf("%d",&num);
		table[0] = 0;
		for(int i = 1 ; i <= num ; i++ ){
			scanf("%d",&table[i]);
			table[i] = table[i] + table[i-1];
		}

		bool check = false;
		pair<int ,int> ans;
		for(int i = 2 ; i <= num ; i++ ){
			for(int j = 0 ; j+i <= num ; j++ ){
				if( isPrime(table[j+i]-table[j]) ){
					check = true;
					ans.first = j;
					ans.second = j+i;
					break;
				}
			}
			if( check )
				break;
		}
		
		if( check ){
			printf("Shortest primed subsequence is length %d:",ans.second-ans.first);
			for(int i = ans.first ; i < ans.second ; i++ )
				printf(" %d",table[i+1]-table[i] );
			printf("\n");
		}
		else
			printf("This sequence is anti-primed.\n");


	}

	return 0;
}
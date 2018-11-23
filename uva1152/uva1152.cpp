#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1152"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define Max_size 100005

int HashNumber(int k){
	return abs(k) % Max_size;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int A[4005], B[4005], C[4005], D[4005];
	int times, number, i, j, k;
	int seat,mix;
	vector<int> table[Max_size];

	scanf("%d",&times);

	while( times-- ){

		scanf("%d",&number);
		for( i = 0 ; i < number ; i++ )
			scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i] );

		for( i = 0 ; i < number ; i++ ){
			for( j = 0 ; j < number ; j++ ){
				mix = A[i] + B[j];
				seat = HashNumber(mix);
				table[seat].push_back(mix);
			}
		}

		int ans = 0;
		for( i = 0 ; i < number ; i++ ){
			for( j = 0 ; j < number ; j++ ){
				mix = ( C[i] + D[j] ) * (-1);
				seat = HashNumber(mix);
				for( k = 0 ; k < table[seat].size() ; k++ ){
					if( table[seat][k] == mix )
						ans++;
				}
			}
		}

		for( i = 0 ; i < Max_size ; i++ )
			table[i].clear();

		printf("%d\n",ans );
		if( times != 0 )
			printf("\n");

	}

	return 0;
}

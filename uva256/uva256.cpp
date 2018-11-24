#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "256"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number;
	int ans,i,j;
	string two[3] = {"00","01","81"};
	string four[5] = {"0000","0001","2025","3025","9801"};
	string six[5] = {"000000","000001","088209","494209","998001"};
	string eight[9] = {"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"};
	while( ~scanf("%d",&number) ){

		if( number == 2 ){
			for( i = 0 ; i < 3 ; i++ )
				cout << two[i] << endl;
			// for( i = 0 ; i < 10 ; i++ ){
			// 	ans = i * 10;
			// 	for( j = 0 ; j < 10 ; j++ ){
			// 		ans = ans + j;
			// 		if( (i+j)*(i+j) == ans )
			// 			printf("%02d\n",ans );
			// 		ans = ans - j;
			// 	}
			// }
		}
		else if( number == 4 ){
			for( i = 0 ; i < 5 ; i++ )
				cout << four[i] << endl;
			// for( i = 0 ; i < 100 ; i++ ){
			// 	ans = i * 100;
			// 	for( j = 0 ; j < 100 ; j++ ){
			// 		ans = ans + j;
			// 		if( (i+j)*(i+j) == ans )
			// 			printf("%04d\n",ans );
			// 		ans = ans - j;
			// 	}
			// }
		}
		else if( number == 6 ){
			for( i = 0 ; i < 5 ; i++ )
				cout << six[i] << endl;
			// for( i = 0 ; i < 1000 ; i++ ){
			// 	ans = i * 1000;
			// 	for( j = 0 ; j < 1000 ; j++ ){
			// 		ans = ans + j;
			// 		if( (i+j)*(i+j) == ans )
			// 			printf("%06d\n",ans );
			// 		ans = ans - j;
			// 	}
			// }
		}
		else if( number == 8 ){
			for( i = 0 ; i < 9 ; i++ )
				cout << eight[i] << endl;
			// for( i = 0 ; i < 10000 ; i++ ){
			// 	ans = i * 10000;
			// 	for( j = 0 ; j < 10000 ; j++ ){
			// 		ans = ans + j;
			// 		if( (i+j)*(i+j) == ans )
			// 			printf("%08d\n",ans );
			// 		ans = ans - j;
			// 	}
			// }
		}

	}

	return 0;
}
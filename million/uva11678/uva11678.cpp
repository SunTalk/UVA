#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11678"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int one,two;
	int tmp,i,j;
	vector<int> A,B;

	while( ~scanf("%d %d",&one,&two) ){
		if( one == 0 && two == 0 )
			break;
		A.clear();
		B.clear();

		for( i = 0 ; i < one ; i++ ){
			scanf("%d",&tmp);
			if( A.empty() || tmp != A.back() )
				A.push_back(tmp);
		}
		for( i = 0 ; i < two ; i++ ){
			scanf("%d",&tmp);
			if( B.empty() || tmp != B.back() )
				B.push_back(tmp);
		}

		i = j = 0;
		int ans_a = 0;
		int ans_b = 0;

		while(1){
			if( i == A.size() ){
				ans_b = ans_b + B.size() - j;
				break;
			}
			if( j == B.size() ){
				ans_a = ans_a + A.size() - i;
				break;
			}
			if( A[i] > B[j] ){
				ans_b++;
				j++;
			}
			else if( A[i] < B[j] ){
				ans_a++;
				i++;
			}
			else{
				i++;
				j++;
			}
		}

		printf("%d\n",min(ans_a,ans_b) );


	}


	return 0;
}
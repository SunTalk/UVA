#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10107"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	vector <long long> number;
	long long input,i;

	scanf("%lld",&input);
	printf("%lld\n",input );
	number.push_back(input);
	int size = 1;
	while( ~scanf("%lld",&input) ){

		if( input < number[0] )
			number.insert(number.begin(),input);
		else if( input > number[size-1] )
			number.push_back(input);
		else{
			for( i = 0 ; i < number.size() ; i++ ){
				if( input < number[i]  ){
					number.insert(number.begin()+i,input);
					break;
				}
			}
		}

		size++;

		if( size%2 == 0 )
			printf("%lld\n", (number[size/2]+number[size/2-1])/2 );
		else
			printf("%lld\n", number[size/2] );

	}

	return 0;
}
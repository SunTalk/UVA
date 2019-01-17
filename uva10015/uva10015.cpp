#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10015"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

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

	vector <int> Prime;
	Prime.push_back(0);
	int i = 2;
	while( Prime.size() < 3505 ){
		if( isPrime(i) )
			Prime.push_back(i);
		i++;
	}
	
	vector<int> one;
	vector<int> two;

	int people,eat,j;
	
	while( ~scanf("%d",&people) && people ){

		int ans = 0;
		for( i = 2 ; i <= people ; i++ ){
			ans = (ans + Prime[people-i+1]) % i;
		}
		printf("%d\n",ans+1 );
		
		/* brute force AC 7.430s
		one.clear();
		for( i = 1 ; i <= people ; i++ )
			one.push_back(i);

		int tmp = people;
		eat = 1;
		while( tmp != 1 ){
			j = Prime[eat]%tmp;
			two.clear();
			for( i = 0 ; i < one.size()-1 ; i++ ){
				two.push_back(one[j]);
				j++;
				if( j == one.size() )
					j = 0;
			}
			tmp--;
			eat++;

			if( tmp == 1 )
				break;

			j = Prime[eat]%tmp;
			one.clear();
			for( i = 0 ; i < two.size()-1 ; i++ ){
				one.push_back(two[j]);
				j++;
				if( j == two.size() )
					j = 0;
			}
			tmp--;
			eat++;

		}

		if( one.size() == 1 )
			printf("%d\n",one[0] );
		else
			printf("%d\n",two[0] );
		printf("\n");
		*/

	}

	return 0;
}
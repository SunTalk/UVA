#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "151"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number,i;

	while( ~scanf("%d",&number) && number ){
		
		queue <int> city;
		for( i = 1 ; i <= number ; i++ )
			city.push(i);
		
		int ans = 1;
		while(1){

			if( city.front() != 13 ){
				city.pop();
				for( i = 1 ; i < ans ; i++ ){
					city.push(city.front());
					city.pop();
				}
			}
			else{
				if( city.size() == 1 ){
					printf("%d\n",ans );
					break;
				}
				ans++;
				while( !city.empty() )
					city.pop();
				for( i = 1 ; i <= number ; i++ )
					city.push(i);

			}

		}

	}

	return 0;
}
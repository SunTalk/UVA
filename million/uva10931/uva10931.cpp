#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int num;
	while( ~scanf("%d", &num) && num ){
		int ans = 0;
		string str = "";
		while( num ){
			if( num&1 ){
				str = '1' + str;
				ans++;
			}
			else str = '0' + str;
			num >>= 1;
		}
		cout << "The parity of " << str << " is " << ans << " (mod 2)." <<endl ;
	}

	return 0;
}
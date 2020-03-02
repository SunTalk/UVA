#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 40
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int Fib[MAXN+10];
	Fib[0] = Fib[1] = 1;
	for(int i = 2; i < MAXN+5 ; i++)
		Fib[i] = Fib[i-1]+Fib[i-2];

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){

		scanf("%d",&num);
		printf("%d = ",num);

		string ans = "";
		for(int i = MAXN ; i > 0 ; i-- ){
			if( Fib[i] <= num ){
				ans += "1";
				num -= Fib[i];
			}
			else if( ans.size() > 0 ){
				ans += "0";
			}
		}
		cout << ans << " (fib)" << endl;

	}

	return 0;
}
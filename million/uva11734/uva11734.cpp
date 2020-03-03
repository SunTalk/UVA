#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d\n",&kase);
	string str,judge;

	for(int K = 1 ; K <= kase ; K++ ){

		printf("Case %d: ",K);
		getline(cin,str);
		getline(cin,judge);

		if( str == judge ){
			printf("Yes\n");
			continue;
		}

		stringstream ss(str);
		string tmp,ans = "";

		while( ss >> tmp ) ans += tmp;

		if( ans == judge ) printf("Output Format Error\n");
		else printf("Wrong Answer\n");

	}

	return 0;
}
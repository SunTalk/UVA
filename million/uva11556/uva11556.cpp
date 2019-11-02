#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{

	long long a,b,tmp;
	while( cin >> a >> b ){
		tmp = 1;
		if( a <= (tmp<<(b+1))-1 ) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}
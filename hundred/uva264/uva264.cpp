#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{

	int num;
	int term,sum;

	while( ~scanf("%d",&num) ){

		term = sum = 1;
		while( term < num )
			term += ++sum;

		int A = 1 + term - num;
		int B = sum - A + 1;
		if( sum%2 )
			printf("TERM %d IS %d/%d\n", num, A, B );
		else
			printf("TERM %d IS %d/%d\n", num, B, A );

	}

	return 0;
}
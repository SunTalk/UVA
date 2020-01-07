#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int table[10];
	string str;

	while( getline(cin,str) ){

		stringstream ss(str);
		int idx = 8;
		while( ss >> table[idx--] );

		bool first = true;
		for(int i = 8 ; i >= 0 ; i-- ){
			if( table[i] == 0 ) continue;
			if( !first ){
				if( table[i] < 0 ) printf(" - ");
				else printf(" + ");
				table[i] = abs(table[i]);
			}
			if( table[i] == -1 && i != 0 )
				printf("-");
			else if ( table[i] != 1 || i == 0 )
				printf("%d", table[i]);
			if( i > 0 ) printf("x");
			if( i > 1 ) printf("^%d",i);
			first = false;
		}

		if( first ) printf("0");
		printf("\n");

	}

	return 0;
}
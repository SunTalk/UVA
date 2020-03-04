#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int table[MAXN+10];

int main(int argc, char const *argv[])
{

	string str;

	while( cin >> str && str != "." ){

		memset(table, 0, sizeof(table));

		int k = table[0] = -1;
		for(int i = 1 ; i < str.size() ; i++ ){
			while( k >= 0 && str[k+1] != str[i] )
				k = table[k];
			if( str[k+1] == str[i] ) k++;
			table[i] = k;
		}

		int len = str.size() - table[str.size()-1] - 1;
		if( str.size()%len == 0 ) printf("%d\n", str.size()/len);
		else printf("1\n");

	}

	return 0;
}
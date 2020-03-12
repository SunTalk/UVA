#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	string a,b;
	int A[MAXN],B[MAXN];

	while( getline(cin,a) ){
		getline(cin,b);

		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));

		for(int i = 0 ; i < a.size() ; i++ )
			A[a[i]-'a']++;
		for(int i = 0 ; i < b.size() ; i++ )
			B[b[i]-'a']++;


		for(int i = 0 ; i < 26 ; i++ )
			if( min(A[i],B[i]) )
				for(int j = 0 ; j < min(A[i],B[i]) ; j++ )
					printf("%c",'a'+i);
		printf("\n");

	}

	return 0;
}
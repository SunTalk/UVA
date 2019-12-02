#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 30
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

struct matrix{
	int m,n;
}M[MAXN],A,B;
stack <matrix> S;

int main(int argc, char const *argv[])
{

	int num;
	char k;
	scanf("%d\n",&num);
	for(int i = 0 ; i < num ; i++ ){
		scanf("%c",&k);
		scanf("%d %d\n",&M[k-'A'].m,&M[k-'A'].n);
	}

	string str;
	while( cin >> str ){

		while( !S.empty() )
			S.pop();

		bool flag = true;
		int ans = 0;
		for(int i = 0 ; i < str.size() ; i++ ){

			if( str[i] == ')' && S.size() > 1 ){
				B = S.top();
				S.pop();
				A = S.top();
				S.pop();
				if( A.n != B.m ){
					flag = false;
					break;
				}
				ans += A.m*A.n*B.n;
				A.n = B.n;
				S.push(A);
			}
			else if( 'A' <= str[i] && str[i] <= 'Z' )
				S.push(M[str[i] - 'A']);
		}

		if( flag ) printf("%d\n",ans);
		else printf("error\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	map <int,int> M;
	int N[] = {2, 3, 5, 7, 13, 17, 31, 61, 89};
	for(int i = 0 ; i < 9 ; i++ )
		M[N[i]] = 1;

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){
		scanf("%d,",&num);
		printf("%s\n",M[num]?"Yes":"No");
	}

	return 0;
}
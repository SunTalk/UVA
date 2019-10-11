#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000
int table[MAXN+10];

int main(int argc, char const *argv[])
{

	string str;
	int num;
	int lhs,rhs;
	int kase = 1;

	while( cin >> str ){

		memset(table, 0, sizeof(table));
		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] == '1' )
				table[i+1]++;
			table[i+1] += table[i];
		}

		printf("Case %d:\n",kase++);
		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d",&lhs,&rhs);
			if( rhs < lhs )
				swap(lhs,rhs);
			int tmp = table[rhs+1]-table[lhs];
			if( tmp == 0 || tmp == rhs-lhs+1 )
				printf("Yes\n");
			else
				printf("No\n");
		}


	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num,money;
	char word;
	map <char,int> table;
	string str;

	while( kase-- ){

		scanf("%d\n",&num);
		table.clear();
		for(int i = 0 ; i < num ; i++ ){
			scanf("%c %d\n",&word,&money);
			table[word] = money;
		}

		scanf("%d\n",&num);
		int ans = 0;
		for(int i = 0 ; i < num ; i++ ){
			getline(cin,str);
			for(int j = 0 ; j < str.size() ; j++ )
				ans += table[str[j]];
		}

		printf("%.2lf$\n",((double)ans/100));

	}

	return 0;
}
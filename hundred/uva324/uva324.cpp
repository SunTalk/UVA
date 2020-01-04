#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[MAXN][10];

string build(string str, int n){

	int overflow = 0;
	string ans = "";
	for(int i = str.size()-1 ; i >= 0 ; i-- ){
		int tmp = str[i]-'0';
		tmp *= n;
		tmp += overflow;
		char c = tmp%10 + '0';
		ans = c + ans;
		overflow = tmp/10;
	}

	while( overflow > 0 ){
		char c = overflow%10 + '0';
		ans = c + ans;
		overflow /= 10;
	}

	for(int i = 0 ; i < ans.size() ; i++ )
		table[n][ans[i]-'0']++;

	return ans;
}

int main(int argc, char const *argv[])
{

	string str = "1";

	memset(table, 0, sizeof(table));
	for(int i = 1 ; i < MAXN ; i++ )
		str = build(str,i);

	int num;
	while( ~scanf("%d",&num) && num ){
		printf("%d! --\n",num);
		for(int i = 0 ; i < 10 ; i++ ){
			if( i == 5 ) printf("\n");
			if( i%5 == 0 )printf("   ");
			else printf("    ");
			printf("(%d)%5d", i, table[num][i]);
		}
		printf("\n");
	}

	return 0;
}
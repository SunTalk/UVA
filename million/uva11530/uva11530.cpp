#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	getchar();
	string str;

	int table[30];
	table[0] = table[3] = table[6] = table[9]  = table[12] = table[15] = table[19] = table[22] = 1;
	table[1] = table[4] = table[7] = table[10] = table[13] = table[16] = table[20] = table[23] = 2;
	table[2] = table[5] = table[8] = table[11] = table[14] = table[17] = table[21] = table[24] = 3;
	table[18] = table[25] = 4;

	for(int K = 1 ; K <= kase ; K++ ){

		printf("Case #%d: ",K);

		getline(cin,str);
		// cout << "-" << str << "-" << endl;
		int ans = 0;
		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] == ' ' ) ans++;
			else ans += table[(str[i]-'a')];
		}

		printf("%d\n",ans);
	}

	return 0;
}
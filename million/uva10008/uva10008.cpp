#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10008"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct ALPHABET{
	char alphabet;
	int num;

	ALPHABET(){
		num = 0;
	}

	bool operator<( ALPHABET &rhs){
		if( num == rhs.num )
			return alphabet < rhs.alphabet;
		return num > rhs.num;
	};

};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	scanf("%d\n",&num);
	string str;
	ALPHABET table[26];

	while( num-- ){
		getline(cin,str);
		transform(str.begin(), str.end(),str.begin(),::toupper);
		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] >= 'A' && str[i] <= 'Z' ){
				table[str[i]-'A'].num++;
				table[str[i]-'A'].alphabet = str[i];
			}
		}
	}

	sort(&table[0],&table[26]);

	for(int i = 0 ; i < 26 ; i++ )
		if( table[i].num > 0 )
			printf("%c %d\n",table[i].alphabet,table[i].num );

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

bool is_cool(string str){
	int alph[30];
	memset(alph,0,sizeof(alph));
	for(int i = 0 ; i < str.size() ; i++ )
		alph[str[i]-'a']++;
	sort(alph,alph+26);

	int check = 0;
	for(int i = 0 ; i < 26 ; i++ ){
		if( alph[i] ) check++;
		if( alph[i] == alph[i+1] && alph[i] )
			return false;	
	}

	if( check > 1 ) return true;
	return false;

}

int main(int argc, char const *argv[])
{

	int num;
	int kase = 1;
	string str;

	while( ~scanf("%d",&num) ){

		int ans = 0;
		for(int i = 0 ; i < num ; i++ ){
			cin >> str;
			if( is_cool(str) )
				ans++;
		}
		printf("Case %d: %d\n",kase++,ans);

	}

	return 0;
}
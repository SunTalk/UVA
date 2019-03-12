#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10776"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

string word;
int lengh;

void Set( vector <char> ans , int k ){
	
	int i;
	char tmp;
	
	if( ans.size() == lengh ){
		for( i = 0 ; i < lengh ; i++ )
			printf("%c",ans[i] );
		printf("\n");
		return;
	}

	for( i = k ; i < word.size() ; i++ ){
		ans.push_back(word[i]);
		Set( ans , i+1 );
		ans.pop_back();
		while( word[i] == word[i+1] && i+1 < word.size() )
			i++;
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int i,j;

	while( cin >> word >> lengh ){

		for( i = 1 ; i < word.size() ; i++ ){
			j = i-1;
			while( j != -1 && word[j] > word[j+1] ){
				swap(word[j],word[j+1]);
				j--;
			}
		}
		
		vector <char> ans;
		Set(ans,0);
	
	}

	return 0;
}
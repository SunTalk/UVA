#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10776"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	USE_CPPIO();

	string word;
	int lengh;
	int alphbat[30];

	while( cin >> word >> lengh ){

		int size,seat,i,j;
		size = word.size();

		memset(alphbat,0,sizeof(alphbat));

		for( i = 0 ; i < size-1 ; i++ ){
			for( j = i+1 ; j < size ; j++ ){
				if( word[i] > word[j] )
					swap(word[i],word[j]);
			}
		}

		cout << word << endl;
		// for( i = 0 ; i < size ; i++ ){
		// 	seat = word[i]-'a';
		// 	alphbat[seat]++;
		// }



		


	}


	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11491"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int digits,erase;
	int notwant,i;
	string num;

	while( ~scanf("%d %d",&digits,&erase) ){
		if( digits == 0 && erase == 0 )
			break;

		cin >> num;
		int tmp;
		notwant = 0;

		stack <int> check;
		check.push(num[0]-'0');

		for( i = 1 ; i < digits ; i++ ){
			tmp = num[i] - '0';
			while( tmp > check.top() && notwant != erase ){
				check.pop();
				notwant++;
				if( check.size() == 0 )
					break;
			}
			check.push(tmp);
		}

		for( i = notwant ; i < erase ; i++ )
			check.pop();

		vector <int> ans;
		tmp = check.size();
		for( i = 0 ; i < tmp ; i++ ){
			ans.push_back(check.top());
			check.pop();
		}


		for( i = ans.size()-1 ; i >= 0 ; i-- )
			printf("%d",ans[i] );
		printf("\n");

	}

	return 0;
}
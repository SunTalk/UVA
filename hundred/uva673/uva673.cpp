#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "673"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	char Arithmetic;
	getchar();

	stack <char> check;
	char tmp;
	bool ans = true;
	while( ~scanf("%c",&Arithmetic) ){

		if( Arithmetic == '\n' ){
			if( ans && check.empty() )
				printf("Yes\n");
			else
				printf("No\n");
			ans = true;
			while( !check.empty() )
				check.pop();
		}
		else if( Arithmetic == '(' || Arithmetic == '[' ){
			check.push(Arithmetic);
		}
		else if( Arithmetic == ')' ){
			if( check.empty() ){
				ans = false;
				continue;
			}
			tmp = check.top();
			check.pop();
			if( tmp != '(' )
				ans = false;
		}
		else if( Arithmetic == ']' ){
			if( check.empty() ){
				ans = false;
				continue;
			}
			tmp = check.top();
			check.pop();
			if( tmp != '[' )
				ans = false;
		}

	}

	return 0;
}
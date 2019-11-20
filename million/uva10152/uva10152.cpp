#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int num;
	string str;
	stack <string> origin;
	stack <string> after;

	while( kase-- ){

		scanf("%d\n",&num);
		while( !origin.empty() ) origin.pop();
		while( !after.empty() ) after.pop();

		for(int i = 0 ; i < num ; i++ ){
			getline(cin, str);
			origin.push(str);
		}
		for(int i = 0 ; i < num ; i++ ){
			getline(cin, str);
			after.push(str);
		}

		for(int i = 0 ; i < num ; i++ ){
			if( origin.top() == after.top() )
				after.pop();
			origin.pop();
		}

		while( !after.empty() ){
			cout << after.top() << endl;
			after.pop();
		}
		cout << endl;

	}

	return 0;
}
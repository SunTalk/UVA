#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "481"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000

int LIS[MAXN+5][2];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	vector <int> table;
	memset(LIS,0,sizeof(LIS));

	scanf("%d",&num);
	table.push_back(num);
	LIS[0][1] = num;
	LIS[0][0] = 0;
	int k = 1;

	while( ~scanf("%d",&num) ){
		LIS[k][1] = num;
		if( num > table.back() ){
			table.push_back(num);
			LIS[k++][0] = table.size()-1;
		}
		else{
			*lower_bound(table.begin(), table.end(),num) = num;
			LIS[k++][0] = lower_bound(table.begin(), table.end(),num)-table.begin();
		}
	}

	int check = table.size()-1;
	stack <int> ans;
	for(int i = k-1 ; i >= 0 ; i-- ){
		if( LIS[i][0] == check ){
			ans.push(LIS[i][1]);
			check--;
		}
	}

	printf("%d\n-\n",table.size() );
	while( !ans.empty() ){
		printf("%d\n",ans.top() );
		ans.pop();
	}

	return 0;
}
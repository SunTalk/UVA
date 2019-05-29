#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1594"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> table;

void change(){
	int tmp = table[0];
	for(int i = 0 ; i < table.size() ; i++ ){
		if( i+1 == table.size() )
			table[i] = abs(table[i]-tmp);
		else
			table[i] = abs(table[i+1]-table[i]);
	}
}

bool is_zero(){
	for(int i = 0 ; i < table.size() ; i++ )
		if( table[i] != 0 )
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	map <vector<int> ,int> M;
	int num,tmp;

	while( CASE-- ){

		scanf("%d",&num);
		table.clear();
		M.clear();

		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&tmp);
			table.push_back(tmp);
		}

		while( !is_zero() ){
			change();
			tmp = M.size();
			M[table] = 1;
			if( tmp == M.size() )
				break;
		}

		if( is_zero() )
			printf("ZERO\n");
		else
			printf("LOOP\n");

	}

	return 0;
}
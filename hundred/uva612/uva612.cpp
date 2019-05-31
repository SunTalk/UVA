#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "612"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct DNA{
	string str;
	int id,num;
	bool operator<(DNA &k){
		if( num == k.num )
			return id < k.id;
		return num < k.num;
	};
};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int len,num;
	DNA tmp;
	vector <DNA> table;

	while( CASE-- ){
		
		scanf("%d %d",&len,&num);
		table.clear();
		for(int i = 0 ; i < num ; i++ ){
			cin >> tmp.str;
			tmp.id = i;
			tmp.num = 0;
			for(int j = 0 ; j < tmp.str.size() ; j++ )
				for(int k = j+1 ; k < tmp.str.size() ; k++ )
					if( tmp.str[k] < tmp.str[j] )
						tmp.num++;
			table.push_back(tmp);
		}
		sort(table.begin(), table.end());

		for(int i = 0 ; i < num ; i++ )
			cout << table[i].str << endl;
		if( CASE )
			cout << endl;


	}

	return 0;
}
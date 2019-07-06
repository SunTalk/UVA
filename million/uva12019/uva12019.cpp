#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12019"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	map < pair<int,int> , string > table;

	pair<int,int> tmp;
	int k = 5;
	for(int i = 1 ; i <= 12 ; i++ ){
		tmp.first = i;
		for(int j = 1 ; j <= month[i-1] ; j++ ){
			tmp.second = j;
			table[tmp] = day[k];
			k = (k+1)%7 ;
		}
	}

	int num;
	scanf("%d",&num);

	while( num-- ){
		scanf("%d %d",&tmp.first,&tmp.second);
		cout << table[tmp] << endl;
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

string mon[12] = {
	"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
	"JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

string week[7] = {
	"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
};

int days[12] = {
	31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31
};

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	string M,D;

	while( kase-- ){

		cin >> M >> D ;
		int A = find(mon, mon+12, M) - mon;
		int B = find(week, week+7, D) - week;
		int ans = 0;
		for(int i = 0 ; i < days[A] ; i++ )
			if( (B+i)%7 == 5 || (B+i)%7 == 6 )
				ans++;
		printf("%d\n",ans);
		
	}

	return 0;
}
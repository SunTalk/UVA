#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "412"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool isrp(int a, int b){

	if( a == 1 || b == 1 )
		return true;

	while(1){
		int t = a%b;
		if(t == 0) {
			break;
		}
		else{
			a = b;
			b = t;
		}
	}

	if( b > 1 )
		return false;
	else
		return true;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int table[55];

	while( ~scanf("%d",&num) && num ){

		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);

		int hit = 0;
		for(int i = 0 ; i < num ; i++ )
			for(int j = i+1 ; j < num ; j++ )
				if( isrp(table[i],table[j]) )
					hit++;

		double a = hit;
		double b = (num*(num-1))/2;
		double ans = a/b;
		ans = 6/ans;
		ans = sqrt(ans);

		if( hit )
			printf("%.6lf\n",ans );
		else
			printf("No estimate for this data set.\n");
		
	}

	return 0;
}
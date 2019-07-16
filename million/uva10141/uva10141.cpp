#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10141"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int n,p;
	int kase = 0;
	string str,tmp,k;
	double price,pri;
	int have,hav;

	while( ~scanf("%d %d\n",&n,&p) && n ){
		
		for(int i = 0 ; i < n ; i++ )
			getline(cin,k);

		have = -1;
		for(int i = 0 ; i < p ; i++ ){
			getline(cin,tmp);
			scanf("%lf %d\n",&pri,&hav);

			for(int j = 0 ; j < hav ; j++ )
				getline(cin,k);

			if( hav > have || ( hav == have && pri < price ) ){
				str = tmp;
				have = hav;
				price = pri;
			}

		}

		if( kase )
			printf("\n");
		printf("RFP #%d\n", ++kase );
		cout << str << endl;

	}

	return 0;
}
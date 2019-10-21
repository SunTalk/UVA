#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{

	char type;
	string tele;
	int day,evening,night;
	int shour,smin,ehour,emin;

	double ChargingStep[5][3] = {
		{0.10, 0.06, 0.02},
		{0.25, 0.15, 0.05},
		{0.53, 0.33, 0.13},
		{0.87, 0.47, 0.17},
		{1.44, 0.80, 0.30}
	};

	while( cin >> type && type!='#' ){
		
		cin >> tele >> shour >> smin >> ehour >> emin ;
		smin += shour*60;
		emin += ehour*60;
		day = evening = night = 0;

		do{
			if( 480 <= smin && smin < 1080 )
				day++;
			else if( 1080 <= smin && smin < 1320 )
				evening++;
			else
				night++;
			smin++;
			if( smin == 1440 )
				smin = 0;
		}while( smin != emin );

		while( tele.size() != 10 )
			tele = " "+tele;
		double ans = ( day*ChargingStep[type-'A'][0]+
					   evening*ChargingStep[type-'A'][1]+
					   night*ChargingStep[type-'A'][2]
					);

		cout << tele ;
		printf("%6d%6d%6d%3c%8.2lf\n",day,evening,night,type,ans);

	}

	return 0;
}
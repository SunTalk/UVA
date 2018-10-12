#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "579"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double hours,minutes;
	char garbage;
	double angle;

	while( ~scanf("%lf%c%lf",&hours,&garbage,&minutes) ){
		if( hours == 0 && minutes == 0 )
			break;
		hours = hours*30;
		hours = hours + minutes/2;
		minutes = minutes*6;
		angle = abs(hours - minutes);
		if(angle>180)
			angle = 360 - angle;

		printf("%.3lf\n",angle );

	}



	return 0;
}
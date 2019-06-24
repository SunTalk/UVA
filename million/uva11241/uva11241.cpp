#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11241"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

double TH(double T, double H) {
    double e = (H-T)/0.5555+10;
    return -273.16 + 1.0/(1/273.16-log(e/6.11)/5417.7530);
}
double TD(double T, double D) {
    double e = 6.11*exp(5417.7530*(1/273.16-1/(D+273.16)));
    double h = 0.5555*(e-10);
    return T+h;
}
double DH(double D, double H) {
    double e = 6.11*exp(5417.7530*(1/273.16-1/(D+273.16)));
    double h = 0.5555*(e-10);
    return H-h;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char a,b;
	double A,B;
	double T,D,H;
	bool t,d,h;

	while( ~scanf("%c %lf %c %lf\n",&a,&A,&b,&B) && a != 'E'  ){

		t = d = h = false;

		if( a == 'T' )
			t = true,T = A;
		if( a == 'D' )
			d = true,D = A;
		if( a == 'H' )
			h = true,H = A;
		if( b == 'T' )
			t = true,T = B;
		if( b == 'D' )
			d = true,D = B;
		if( b == 'H' )
			h = true,H = B;

		if( t && h )
			D = TH(T,H);
		if( t && d )
			H = TD(T,D);
		if( d && h )
			T = DH(D,H);

		printf("T %.1lf D %.1lf H %.1lf\n", T, D, H);

	}

	return 0;
}
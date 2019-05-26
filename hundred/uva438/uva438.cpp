#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "438"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define PI 3.141592653589793
double dis(double x1, double y1,double x2,double y2){

	double x = x1-x2;
	double y = y1-y2;
	double tmp = sqrt(x*x + y*y);
	return tmp;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double x1,y1,x2,y2,x3,y3;

	while( cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ){

		double a = dis(x1,y1,x2,y2);
		double b = dis(x2,y2,x3,y3);
		double c = dis(x1,y1,x3,y3);

		double k = (a+b+c)/2;
		double area = sqrt(k*(k-a)*(k-b)*(k-c));

		double ans = (a*b*c)*PI/(2*area);

		printf("%.2lf\n",ans );


	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "477"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double rectangle[15][4];
	double circles[15][3];
	char symbol;
	int tmp,i = 0;
	memset(rectangle,0,sizeof(rectangle));
	memset(circles,0,sizeof(circles));

	while( ~scanf("%c",&symbol) ){

		if( symbol == 'r' )
			scanf("%lf %lf %lf %lf",&rectangle[i][0],&rectangle[i][1],&rectangle[i][2],&rectangle[i][3]);
		else if( symbol == 'c' )
			scanf("%lf %lf %lf",&circles[i][0],&circles[i][1],&circles[i][2]);
		else if( symbol == '*' )
			break;

		getchar();
		i++;
	}

	tmp = i;
	double x,y;
	int point=1;
	while( ~scanf("%lf %lf",&x,&y) ){

		if( x == 9999.9 && y == 9999.9 )
			break;
		bool check = 0;
		for( i = 0 ; i < tmp ; i++ ){
			if( x > rectangle[i][0] && x < rectangle[i][2] && y <rectangle[i][1] && y > rectangle[i][3] ){
				printf("Point %d is contained in figure %d\n", point,i+1);
				check = 1;
			}
			if( (x-circles[i][0])*(x-circles[i][0])+(y-circles[i][1])*(y-circles[i][1]) < circles[i][2]*circles[i][2] ){
				printf("Point %d is contained in figure %d\n", point,i+1);
				check = 1;
			}
		}
		if( check == 0 )
			printf("Point %d is not contained in any figure\n",point );

		point++;
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005
#define F(x) (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u)

int main(int argc, char const *argv[])
{

	int p,q,r,s,t,u;
	double L,R,MID;

	while( ~scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) ){
		
		L = 0.0,R = 1.0;
		for(int i = 0 ; i < MAXN ; i++ ){
			MID = (L+R)/2;
			if( F(MID) > 0.0 ) L = MID;
			else R = MID;
		}

		if( fabs(F(MID)-0.0) > 1e-10 ) printf("No solution\n");
		else printf("%.4lf\n",MID);

	}

	return 0;
}
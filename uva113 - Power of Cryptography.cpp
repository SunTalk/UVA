#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	double K,P,N;

	while(scanf("%lf %lf",&N,&P) != EOF){
		K=pow(P,(1/N));
		printf("%.0lf\n",K);
	}

	return 0;
}

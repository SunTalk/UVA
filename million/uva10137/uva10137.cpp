#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

double table[MAXN+5];

int main(int argc, char const *argv[])
{

	int num;
	double sum,avg,a,b;

	while( ~scanf("%d", &num) && num ){

		sum = 0;
		for(int i = 0 ; i < num ; i++ ){
			scanf("%lf",&table[i]);
			sum += table[i]*100;
		}

		avg = sum/num;
		avg = floor(avg+0.5)/100.0;
		a = 0,b = 0;

		for(int i = 0 ; i < num ; i++ ){
			if( table[i] > avg )
				a += (table[i] - avg);
			else
				b += (avg - table[i]);
		}

		printf("$%.2lf\n",min(a,b));

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "443"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[6000];
	table[0] = 0;
	table[1] = 1;

	int p2,p3,p5,p7;
	p2 = p3 = p5 = p7 = 1;

	for(int i = 1 ; i < 5842 ; i++ ){

		while( table[p2]*2 <= table[i] )
			p2++;
		while( table[p3]*3 <= table[i] )
			p3++;
		while( table[p5]*5 <= table[i] )
			p5++;
		while( table[p7]*7 <= table[i] )
			p7++;

		int m = table[p2]*2;
		if( m > table[p3]*3 )
			m = table[p3]*3;
		if( m > table[p5]*5 )
			m = table[p5]*5;
		if( m > table[p7]*7 )
			m = table[p7]*7;

		table[i+1] = m;

	}

	int num,k;
	char str[4][3] = { "th", "st", "nd", "rd"};
	while( ~scanf("%d",&num) && num ){

		k = num%10;
		if( num%100 == 11 || num%100 == 12 || num%100 == 13 )
			k = 0;
		if( k > 3 )
			k = 0;

		printf("The %d%s humble number is %d.\n", num, str[k], table[num]);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10035"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int one,two,i;
	int num_o[12],num_t[12];
	int carry;

	while( ~scanf("%d %d",&one,&two) ){

		if( one == 0 && two == 0)
			break;
		
		memset(num_o,0,sizeof(num_o));
		memset(num_t,0,sizeof(num_t));
		carry = 0;

		for( i = 0 ; i < 12 ; i++ ){
			num_o[i] = one%10;
			num_t[i] = two%10;
			one = one/10;
			two = two/10;
		}

		for( i = 0 ; i < 11 ; i++ ){
			if( num_o[i] + num_t[i] > 9 ){
				carry++;
				num_o[i+1]++;
			}
		}

		if( carry == 0 )
			printf("No carry operation.\n");
		else if( carry == 1 )
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", carry);

	}

	return 0;
}
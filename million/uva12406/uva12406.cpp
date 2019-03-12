#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12406"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

long long Need_start[18];

long long Times(int k){

	if( k == 0 )
		return 1;
	else if( k%2 == 0 )
		return Times(k/2)*Times(k/2);
	else
		return Times(k/2)*Times(k/2)*2;

}

void Need(){
	Need_start[0]=0;
	Need_start[1]=1;
	for(int i=2;i<18;i++)
		Need_start[i] = Times(i)-1;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long table[140000];
	int digit[16];
	int i,j,k=1;
	memset(digit,-1,sizeof(digit));
	memset(table,0,sizeof(table));

	while( k < 140000 ){
		i = 0;
		digit[i] = digit[i] + 1 ;

		while( digit[i] == 2 ){//digit is two degree
			digit[i] = 0;
			i++;
			digit[i]++;
		}

		j=15;
		while( digit[j] < 0 ){// find the hightest digit
			j--;
		}

		while( j >= 0 ){// save this number
			table[k] = table[k] * 10;
			if( digit[j] == 1 )
				table[k] = table[k] + 2;
			else if( digit[j] == 0 )
				table[k] = table[k] + 1 ;
			j--;
		}
		table[k] = table[k] * 10; //we need the number can %2 == 0
		table[k] = table[k] + 2;

		k=k+1;
	}

	// for(i=0;i<140000;i++)
	// 	printf("%lld\n",table[i] );


	int number;
	scanf("%d",&number);
	int need_digit,have_digit;
	long long one,two;
	long long max,min;
	int Case=1;
	Need();

	// for(int i=0;i<18;i++)
	// 	printf("%lld\n",Need_start[i] );

	// printf("%lld\n", Times(15));

	for( i = 0 ; i < number ; i++ ){
		scanf("%d %d",&need_digit,&have_digit);
		two = Times(have_digit);
		one = need_digit;

		if(need_digit==1 && have_digit==1){
			printf("Case %d: 2\n",Case );
			Case++;
			continue;
		}

		max = 0;
		min = 33333333333333333;

		// printf("%lld %lld\n",Need_start[one-1],Need_start[one] );

		for( j = Need_start[one-1]  ; j < Need_start[one] ; j++){
			if( table[j]%two == 0 ){
				if( table[j] > max )
					max = table[j];
				if( table[j] < min )
					min = table[j];
			}
		}

		printf("Case %d:",Case );
		Case++;
		if( min != 33333333333333333 )
			printf(" %lld",min);
		if( max != 0 && max != min )
			printf(" %lld",max );

		if( min == 33333333333333333 && max == 0 )
			printf(" impossible");
		printf("\n");

	}


	return 0;
}
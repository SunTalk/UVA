#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10018"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int Count;

long long Plus(long long number){
	Count++;
	long long tmp,num;
	tmp = 0;
	num = number;
	int i;
	for( i = 0 ; i < 15 ; i++ ){
		tmp = tmp*10;
		tmp = tmp + num%10;
		num = num/10;
		if( num == 0 )
			break;
	}
	
	if( number == tmp && Count != 1)
		return number;
	else
		return Plus(number+tmp);

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times,i;
	scanf("%d",&times);

	long long number;

	for( i = 0 ; i < times ; i++ ){

		scanf("%lld",&number);
		Count = 0;
		number = Plus(number);
		printf("%d %lld\n",Count-1,number );

	}
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "374"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

// b^p % m
int bigmode(int b,int p, int m){

	b = b%m;
	if( p == 1 )
		return b;
	int tmp = bigmode(b,p/2,m);
	tmp = (tmp*tmp)%m;
	if( p%2 == 1 )
		return (b * tmp)%m;
	else
		return tmp;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int b,p,m;
	while( ~scanf("%d %d %d",&b,&p,&m) ){
		printf("%d\n",bigmode(b,p,m) );
	}

	return 0;
}
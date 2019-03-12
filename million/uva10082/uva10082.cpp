#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10082"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char button[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
	char alphbat;
	bool check;
	while( ~scanf("%c",&alphbat) ){
		check = 0;
		for( int i = 0 ; i < sizeof(button) ; i++ )
			if( alphbat == button[i]){
				printf("%c",button[i-1] );
				check = 1;
			}
		if( check == 0 )
			printf("%c",alphbat );
		
	}

	return 0;
}
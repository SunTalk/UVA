#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11219"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int ND,NM,NY;
	int BD,BM,BY;
	int Case = 1;

	while( kase-- ){
		
		printf("Case #%d: ",Case++ );

		scanf("%d/%d/%d",&ND,&NM,&NY);
		scanf("%d/%d/%d",&BD,&BM,&BY);

		if( BY > NY ){
			printf("Invalid birth date\n" );
		}
		else if( BY == NY ){
			if( BM > NM ){
				printf("Invalid birth date\n" );
			}
			else if( BM == NM ){
				if( BD > ND )
					printf("Invalid birth date\n" );
				else
					printf("0\n" );
			}
			else{
				printf("0\n" );
			}
		}
		else{
			if( BM > NM ){
				if( NY-BY-1 > 130 )
					printf("Check birth date\n" );
				else
					printf("%d\n", NY-BY-1 );
			}
			else if( BM == NM ){
				if( BD > ND ){
					if( NY-BY-1 > 130 )
						printf("Check birth date\n" );
					else
						printf("%d\n", NY-BY-1 );
				}
				else{
					if( NY-BY > 130 )
						printf("Check birth date\n" );
					else
						printf("%d\n", NY-BY );
				}
			}
			else{
				if( NY-BY > 130 )
					printf("Check birth date\n" );
				else
					printf("%d\n", NY-BY );
			}
		}

	}

	return 0;
}
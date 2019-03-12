#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10038"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number,i,j;
	int one,two;
	int List[3005];
	bool check;

	while( ~scanf("%d",&number) ){

		memset(List,0,sizeof(List));

		scanf("%d",&one);
		for( i = 0 ; i < number-1 ; i++ ){
			scanf("%d",&two);
			List[i] = abs(one-two);
			one = two;
		}

		for( i = 1 ; i < number-1 ; i++ ){
			j = i-1;
			while( List[j] > List[j+1] && j != -1 ){
				swap(List[j],List[j+1]);
				j--;
			}
		}

		check = 1;
		for( i = 0 ; i < number-1 ; i++ ){
			if( List[i] != i+1 ){
				check = 0;
				break;
			}
		}

		if( check == 1 )
			printf("Jolly\n");
		else
			printf("Not jolly\n");

	}

	return 0;
}
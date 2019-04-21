#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10037"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE,num;
	scanf("%d",&CASE);
	int people[1005];
	int path[1005][3];

	while( CASE-- ){
		
		memset(people,0,sizeof(people));
		memset(path,-1,sizeof(path));

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&people[i+1]);

		sort(&people[1],&people[num+1]);
		int trip = 0;
		int ans = 0;

		while( num > 0 ){
			
			if( num == 1 ){
				ans = people[1];
				printf("%d\n", people[1]);
				break;
			}
			else if( num == 2 ){
				path[trip][0] = people[1];
				path[trip][1] = people[2];
				trip++;
				ans = ans + people[2];
				num = 0;
			}
			else if( num == 3 ){
				path[trip][0] = people[1];
				path[trip][1] = people[2];
				path[trip][2] = people[1];
				trip++;
				path[trip][0] = people[1];
				path[trip][1] = people[3];
				trip++;
				num = 0;
				ans = ans + people[1] + people[2] + people[3];
			}
			else{

				int A,B;
				A = people[1] + people[2]*2 + people[num];
				B = people[1]*2 + people[num-1] + people[num];

				if( A < B ){
					path[trip][0] = people[1];
					path[trip][1] = people[2];
					path[trip][2] = people[1];
					trip++;
					path[trip][0] = people[num-1];
					path[trip][1] = people[num];
					path[trip][2] = people[2];
					trip++;
					ans = ans + A;
				}
				else{
					path[trip][0] = people[1];
					path[trip][1] = people[num-1];
					path[trip][2] = people[1];
					trip++;
					path[trip][0] = people[1];
					path[trip][1] = people[num];
					path[trip][2] = people[1];
					trip++;
					ans = ans + B;
				}

				num = num - 2;

			}

		}

		printf("%d\n",ans );
		for(int i = 0 ; i < trip ; i++ ){
			printf("%d %d\n",path[i][0],path[i][1] );
			if( path[i][2] != -1 )
				printf("%d\n",path[i][2] );
		}
		if( CASE > 0 )
			printf("\n");

	}

	return 0;
}
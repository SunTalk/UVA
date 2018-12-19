#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11995"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	stack <int> S;
	queue <int> Q;
	priority_queue <int> PQ;

	bool check_s,check_q,check_pq;

	int number,i;
	int action,data;

	while( ~scanf("%d",&number) ){

		check_s = check_q = check_pq = true;

		for( i = 0 ; i < number ; i++ ){
			scanf("%d %d",&action,&data);

			if( action == 1 ){
				S.push(data);
				Q.push(data);
				PQ.push(data);
			}
			else{
				if( !S.empty() && data == S.top() && check_s == true )
					S.pop();
				else
					check_s = false;
				
				if( !Q.empty() && data == Q.front() && check_q == true )
					Q.pop();
				else
					check_q = false;

				if( !PQ.empty() && data == PQ.top() && check_pq == true )
					PQ.pop();
				else
					check_pq = false;

			}
			
		}

		if( check_s == false && check_q == false && check_pq == false )
			printf("impossible\n");
		else if( check_s == true && check_q == false && check_pq == false )
			printf("stack\n");
		else if( check_s == false && check_q == true && check_pq == false )
			printf("queue\n");
		else if( check_s == false && check_q == false && check_pq == true )
			printf("priority queue\n");
		else
			printf("not sure\n");

		while( !S.empty() )
			S.pop();
		while( !Q.empty() )
			Q.pop();
		while( !PQ.empty() )
			PQ.pop();

	}


	return 0;
}
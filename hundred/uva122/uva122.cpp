#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "122"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int i,j;
	string input,tmp;
	vector <pair<int,int>> ans;

	while( cin >> tmp ){
		input = input + tmp;
	}

	int len = input.size();
	
	for( i = 0 ; i < len ; i++ ){
		if( input[i] == '(' ){
			if( input[i+1] == ')' ){

				sort(ans.begin(),ans.end());
				bool check = true;
				priority_queue <int,vector<int>,greater<int>> PQ;
				
				if( ans.empty() || ans[0].first != 1 )
					check = false;
				else{
					PQ.push(2);
					PQ.push(3);
					for( j = 1 ; j < ans.size() ; j++ ){
						while( !PQ.empty() ){
							if( ans[j].first == PQ.top() ){
								PQ.push(ans[j].first*2);
								PQ.push(ans[j].first*2+1);
								PQ.pop();
								break;
							}
							else
								PQ.pop();
						}
						if( PQ.empty() ){
							check = false;
							break;
						}
					}
				}

				if( check ){
					for( j = 0 ; j < ans.size()-1 ; j++ )
						printf("%d ", ans[j].second);
					printf("%d\n",ans[j].second );
				}
				else
					printf("not complete\n");

				ans.clear();
			}
			else{

				int num = 0;
				int seat = 1;
				while( input[i] != ')' ){
					i++;
					if( input[i] >= '0' && input[i] <= '9' ){
						num = num*10;
						num = num + input[i]-'0';
					}
					if( input[i] == 'L' )
						seat = seat*2;
					if( input[i] == 'R' )
						seat = seat*2+1;
				}
				ans.emplace_back(seat,num);

			}

		}
		
	}

	return 0;
}
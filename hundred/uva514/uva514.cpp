#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{

	int num,tmp;
	vector<int> target;
	while( ~scanf("%d",&num) && num ){

		while(1){
			target.clear();
			scanf("%d",&tmp);
			if( tmp == 0 )
				break;
			target.push_back(tmp);
			for(int i = 1 ; i < num ; i++ ){
				scanf("%d",&tmp);
				target.push_back(tmp);
			}

			stack<int> check;
			int k = 0;
			for(int i = 1 ; i <= num ; i++ ){
				check.push(i);
				while( !check.empty() && k < num && check.top() == target[k] ){
					// printf("%d\n",target[k]);
					k++;
					check.pop();
				}
			}

			if( check.empty() )
				printf("Yes\n");
			else
				printf("No\n");

		}
		printf("\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

vector <int> table;
int ans[6];

void backtracking(int now,int k){

	if( k == 6 ){
		for(int i = 0 ; i < 6 ; i++)
			printf("%d%c",ans[i],i==5?'\n':' ');
		return;
	}
	for(int i = now ; i < table.size() ; i++ ){
		ans[k] = table[i];
		backtracking(i+1,k+1);
	}

}

int main(int argc, char const *argv[])
{

	int num,tmp;
	bool check = false;

	while( ~scanf("%d",&num) && num ){

		table.clear();
		for(int i = 0; i < num ; i++ ){
			scanf("%d",&tmp);
			table.push_back(tmp);
		}
		sort(table.begin(), table.end());

		if(check)
			printf("\n");
		check = true;
		backtracking(0,0);

	}

	return 0;
}
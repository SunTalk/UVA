#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 50000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

vector <int> Prime;
void build(){

	int table[MAXN+5];
	memset(table, 0, sizeof(table));
	for(int i = 2 ; i < MAXN ; i++ ){
		if( table[i] == 0 ){
			Prime.push_back(i);
			for(int j = i*i ; j < MAXN ; j += i )
				table[i] = 1;
		}
	}

}

int main(int argc, char const *argv[])
{

	Prime.clear();
	build();

	int num;
	vector <int> ans;

	while( ~scanf("%d", &num) && num ){

		printf("%d = ",num);

		ans.clear();
		if( num == 1 )
			ans.push_back(1);
		if( num < 0 ){
			ans.push_back(-1);
			num *= -1;
		}

		int k = 0;
		while( num != 1 && k < Prime.size() && num >= Prime[k] ){
			if( num%Prime[k] == 0 ){
				ans.push_back(Prime[k]);
				num /= Prime[k];
			}
			else{
				k++;
			}
		}
		if( num != 1 )
			ans.push_back(num);

		printf("%d",ans[0]);
		for(int i = 1 ; i < ans.size() ; i++ )
			printf(" x %d",ans[i]);
		printf("\n");

	}

	return 0;
}
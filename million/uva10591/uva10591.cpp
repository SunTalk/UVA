#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num;
	map <int,int> exist;
	for(int K = 1 ; K <= kase ; K++ ){

		exist.clear();
		scanf("%d",&num);
		int ori = num;
		int check = -1;
		while( check != exist.size() ){
			check = exist.size();
			int tmp = 0;
			while( num > 0 ){
				tmp += (num%10)*(num%10);
				num /= 10;
			}
			num = tmp;
			exist[num] = 1;
		}

		printf("Case #%d: %d is %s number.\n",K,ori,(num==1?"a Happy":"an Unhappy"));

	}

	return 0;
}
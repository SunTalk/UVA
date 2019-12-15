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

	for(int K = 1 ; K <= kase ; K++ ){

		printf("Case #%d: ",K);

		scanf("%d",&num);
		string str = "";

		if( num == 0 ) str = "0";

		while( num != 0 ){

			int tmp = num % -2;
			num /= -2;

			if( tmp < 0 ){
				num++;
				tmp *= -1;
			}

			char c = tmp+'0';
			str = c+str;

		}

		cout << str << endl;

	}

	return 0;
}
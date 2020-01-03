#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[] = {
	0, 2, 7, 5, 30,
	169, 441, 1872, 7632, 1740,
	93313, 459901, 1358657, 2504881
};

int main(int argc, char const *argv[])
{

	int num;
	while( ~scanf("%d",&num) && num )
		printf("%d\n",table[num]);

	return 0;
}
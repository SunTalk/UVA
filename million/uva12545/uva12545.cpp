#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	string one,two;
	int legal,o_z,z_o,ques;
	
	for(int k = 1 ; k <= kase ; k++ ){
		
		printf("Case %d: ",k);
		
		cin >> one >> two;
		legal = o_z = z_o = ques = 0;
		
		for(int i = 0 ; i < one.size() ; i++ ){
			if( one[i] == '1' ) legal++;
			if( two[i] == '1' ) legal--;
			if( one[i] == '1' && two[i] == '0' ) o_z++;
			if( one[i] == '0' && two[i] == '1') z_o++;
			if( one[i] == '?' ) ques++;
		}

		if( legal > 0 )
			printf("-1\n");
		else
			printf("%d\n",ques+max(o_z,z_o));

	}

	return 0;
}
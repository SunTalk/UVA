#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

vector <string> table[MAXN];
int now[10];
bool isuse[10];

void build(int k){

	if( k == 10 ){

		int A,B;
		A = 0;
		for(int i = 0 ; i < 5 ; i++ ){
			A *= 10;
			A += now[i];
		}
		B = 0;
		for(int i = 5 ; i < 10 ; i++ ){
			B *= 10;
			B += now[i];
		}

		if( A%B == 0 && A/B < MAXN ){
			string ans = "";
			char tmp;
			for(int i = 0 ; i < 10 ; i++ ){
				if( i == 5 ) ans = ans + " / ";
				tmp = now[i]+'0';
				ans += tmp;
			}
			ans = ans + " = ";
			if( A/B > 9 ){
				tmp = ((A/B)/10)+'0';
				ans += tmp ;
			}
			tmp = ((A/B)%10)+'0';
			ans += tmp;
			table[A/B].push_back(ans);
		}

		return;
	}

	for(int i = 0 ; i < 10 ; i++ ){
		if( !isuse[i] ){
			isuse[i] = true;
			now[k] = i;
			build(k+1);
			isuse[i] = false;
		}
	}

}

int main(int argc, char const *argv[])
{
	memset(isuse, 0, sizeof(isuse));
	build(0);

	int num;
	bool first = true;
	while( ~scanf("%d",&num) && num ){

		if( !first ) printf("\n");
		first = false;
		
		if( table[num].size() == 0 )
			printf("There are no solutions for %d.\n", num);
		else
			for(int i = 0 ; i < table[num].size() ; i++ )
				cout << table[num][i] << endl;

	}

	return 0;
}
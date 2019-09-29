#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "623"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 3000

struct BigNum {
	
	int num[MAXN+5];
	BigNum(){
		memset(num, 0, sizeof(num));
	};

	friend ostream &operator<<(ostream &out, const BigNum &rhs){
		bool start = false;
		string ans = "";
		for(int i = MAXN+5-1 ; i >= 0 ; i-- ){
			char tmp = (rhs.num[i]+'0');
			if( rhs.num[i] != 0 )
				start = true;
			if( start )
				ans += tmp;
		}
		out << ans;
		return out;
	}

	BigNum operator*(int &rhs){
		BigNum ans;
		for(int i = 0 ; i < MAXN+5 ; i++ )
			ans.num[i] = num[i]*rhs;
		int carry = 0;
		for(int i = 0 ; i < MAXN+5 ; i++ ){
			ans.num[i] += carry;
			carry = ans.num[i]/10;
			ans.num[i] %= 10;
		}
		return ans;
	}

}table[1005];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	table[0].num[0] = 1;
	for(int i = 1 ; i < 1005 ; i++ )
		table[i] = table[i-1]*i;

	int N;
	while( ~scanf("%d",&N) ){
		cout << N << "!\n" << table[N] << endl;
	}

	return 0;
}
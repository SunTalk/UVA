#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	long long num;
	string str;
	vector <long long> coe;

	while( ~scanf("%lld\n", &num) ){

		getline(cin,str);
		stringstream ss(str);

		coe.clear();
		long long tmp;
		while( ss >> tmp ){
			coe.push_back(tmp);
		}

		long long ans = 0;
		long long k = 1;
		long long x = 1;
		for(int i = coe.size()-2 ; i >= 0 ; i-- ){
			ans += (coe[i]*k*x);
			k++,x *= num;
		}
		cout << ans << endl;

	}

	return 0;
}
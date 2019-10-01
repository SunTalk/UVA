#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "263"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

string SUB(string lhs,string rhs){
	int carry = 0;
	int len = lhs.size();
	string ans = "";
	while( len-- ){
		int one,two;
		one = lhs[len]-'0';
		two = rhs[len]-'0';
		int tmp = one-two+carry;
		if( tmp < 0 ){
			tmp += 10;
			carry = -1;
		}
		else
			carry = 0;
		char c = (tmp+'0');
		ans = c+ans;
	}
	while( ans[0] == '0' && ans.size() > 1 )
		ans = ans.substr(1,ans.size()-1);
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	string A,B,tmp;
	map <string,int> table;

	while( cin >> str && str != "0" ){
		
		cout << "Original number was " << str << endl;
		int ans = 0;
		table.clear();
		int check = table.size();
		do{
			check = table.size();
			B = str;
			sort(B.begin(), B.end());
			A = B;
			reverse(A.begin(), A.end());
			str = SUB(A,B);
			while( B[0] == '0' && B.size() > 1 )
				B = B.substr(1,B.size()-1);
			cout << A << " - " << B << " = " << str << endl;
			ans++;
			table[str] = 1;
		}while( table.size() != check );
		printf("Chain length %d\n\n",ans);

	}

	return 0;
}
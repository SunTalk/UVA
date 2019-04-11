#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1203"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct Register{
	int number,times,adder;
	bool operator<(const Register rhs )const{
		if( times == rhs.times )
			return number > rhs.number;
		return times > rhs.times;
	}
};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	Register tmp;
	priority_queue <Register > PQ;

	while( cin >> str && str != "#" ){
		cin >> tmp.number >> tmp.adder ;
		tmp.times = tmp.adder;
		PQ.push(tmp);
	}

	int num;
	scanf("%d",&num);

	for(int i = 0 ; i < num ; i++ ){
		tmp = PQ.top();
		PQ.pop();
		printf("%d\n",tmp.number );
		tmp.times = tmp.times + tmp.adder;
		PQ.push(tmp);
	}

	return 0;
}
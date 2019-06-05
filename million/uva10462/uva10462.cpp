#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10462"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct EDGE{

	int a,b,len,id;
	bool operator<(const EDGE &rhs)const{
		return len > rhs.len;
	};

};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int point,num;
	vector <EDGE> table;
	priority_queue <EDGE> PQ;
	EDGE tmp;
	vector<int> USE;
	int SET[105];
	int Case = 1;
	int ans;

	while( CASE-- ){

		scanf("%d %d",&point,&num);
		table.clear();
		USE.clear();
		while( !PQ.empty() )
			PQ.pop();

		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d %d",&tmp.a,&tmp.b,&tmp.len);
			tmp.id = i;
			table.push_back(tmp);
		}

		for(int i = 0 ; i < num ; i++ )
			PQ.push(table[i]);
		for(int i = 1 ; i <= point ; i++)
			SET[i] = i;

		ans = 0;
		while( !PQ.empty() ){

			tmp = PQ.top();
			PQ.pop();

			while( SET[tmp.a] != tmp.a )
				tmp.a = SET[tmp.a];
			while( SET[tmp.b] != tmp.b )
				tmp.b = SET[tmp.b];

			if( tmp.a != tmp.b ){
				SET[tmp.a] = tmp.b;
				USE.push_back(tmp.id);
				ans += tmp.len;
			}
		}

		if( USE.size() == point-1 ){
			int ANS = INT_MAX;
			for(int i = 0 ; i < USE.size() ; i++ ){
				
				for(int j = 0 ; j < num ; j++ )
					if( table[j].id != USE[i] )
						PQ.push(table[j]);
				for(int j = 1 ; j <= point ; j++ )
					SET[j] = j;

				int tmp_ans = 0;
				vector<int> TMP_USE;
				while( !PQ.empty() ){

					tmp = PQ.top();
					PQ.pop();

					while( SET[tmp.a] != tmp.a )
						tmp.a = SET[tmp.a];
					while( SET[tmp.b] != tmp.b )
						tmp.b = SET[tmp.b];

					if( tmp.a != tmp.b ){
						SET[tmp.a] = tmp.b;
						TMP_USE.push_back(tmp.id);
						tmp_ans += tmp.len;
					}

				}

				if( tmp_ans < ANS && TMP_USE.size() == USE.size() )
					ANS = tmp_ans;
			}

			if( ANS == INT_MAX )
				printf("Case #%d : No second way\n",Case++);
			else
				printf("Case #%d : %d\n",Case++,ANS);

		}
		else
			printf("Case #%d : No way\n",Case++);

	}

	return 0;
}
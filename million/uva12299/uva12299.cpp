#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12299"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000

int *tree = new int[4*MAXN+5];
int *table = new int[MAXN+5];
int ans;

void build(int L,int R,int seat){
	
	if( L == R ){
		tree[seat] = table[L];
		return;
	}

	build(L,(L+R)/2,seat*2);
	build((L+R)/2+1,R,seat*2+1);
	tree[seat] = min(tree[seat*2],tree[seat*2+1]);
}

void query(int L, int R, int seat, int FL, int FR){

	if( FR < L || FL > R)
		return;
	if( L >= FL && R <= FR )
		ans = min(ans,tree[seat]);
	else{
		query(L,(L+R)/2,seat*2,FL,FR);
		query((L+R)/2+1,R,seat*2+1,FL,FR);
	}

}

void update(int L, int R, int seat, int F, int num){
	
	if( L == R && R == F ){
		tree[seat] = num;
		return;
	}

	int mid = (L+R)/2;

	if( F <= mid )
		update(L,mid,seat*2,F,num);
	else
		update(mid+1,R,seat*2+1,F,num);

	tree[seat] = min(tree[seat*2],tree[seat*2+1]);

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num,action;
	scanf("%d %d",&num,&action);

	memset(table,0,sizeof(table));
	memset(tree,0,sizeof(tree));

	for(int i = 0 ; i < num ; i++ )
		scanf("%d",&table[i]);
	build(0,num-1,1);

	vector <int> shift;
	string str;
	int a,b,tmp;

	while( action-- ){

		cin >> str;

		if( str[0] == 'q' ){

			tmp = 0;
			for(int i = 6 ; i < str.size() ; i++ ){
				if( str[i] == ',' ){
					a = tmp-1;
					tmp = 0;
				}
				else if( str[i] == ')' ){
					b = tmp-1;
					tmp = 0;
				}
				else{
					tmp = tmp*10;
					tmp = tmp+str[i]-'0';
				}
			}
			ans = INT_MAX;
			query(0,num-1,1,a,b);
			printf("%d\n",ans );

		}
		else{

			tmp = 0;
			shift.clear();
			for(int i = 6 ; i < str.size() ; i++ ){
				if( str[i] == ',' || str[i] == ')' ){
					shift.push_back(tmp-1);
					tmp = 0;
				}
				else{
					tmp = tmp*10 ;
					tmp = tmp + str[i]-'0' ;
				}
			}

			sort(shift.begin(), shift.end());

			tmp = table[shift[0]];

			for(int i = 0 ; i < shift.size() ; i++ ){
				if( i == shift.size()-1 )
					table[shift[i]] = tmp;
				else
					table[shift[i]] = table[shift[i+1]];
				update(0,num-1,1,shift[i],table[shift[i]]);
			}

		}

	}

	return 0;
}
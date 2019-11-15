#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000
#define DEVIATION 0.00000005

#define character 2
struct trie{
		
	int siz;
	int ans;
	int node[MAXN+5][character+5];
	int val[MAXN+5];

	void init(){
		siz = 1;
		ans = 0;
		memset(val, 0, sizeof(val));
		memset(node[0], 0, sizeof(node[0]));
	}

	int idx(char k){// change here if a-z
		return k-'0';
	}

	void insert(string str){
		int dep = 0;
		for(int i = 0 ; i < str.size() ; i++ ){
			int span = idx(str[i]);
			if( node[dep][span] == 0 ){
				memset(node[siz],0,sizeof(node[siz]));
				node[dep][span] = siz++;
			}
			dep = node[dep][span];
			val[dep] += (i+1);
			ans = max(ans,val[dep]);
		}
	}

}tree;

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int num;
	string str;

	while( kase-- ){
		
		tree.init();
		scanf("%d",&num);
		for(int i = 0; i < num ; i++ ){
			cin >> str;
			tree.insert(str);
		}

		printf("%d\n", tree.ans);

	}

	return 0;
}
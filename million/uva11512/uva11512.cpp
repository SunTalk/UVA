#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005
int check[MAXN+10];

int thesame(string a, string b){
	int k = 0;
	for(int i = 0 ; i < min(a.size(),b.size()) ; i++ ){
		if( a[i] == b[i] ) k++;
		else return k;
	}
	return k;
}

int main(int argc, char const *argv[])
{
	
	int kase;
	scanf("%d\n",&kase);
	string str,tmp;
	vector <string> table;

	while( kase-- ){

		cin >> str;
		
		table.clear();
		for(int i = 0 ; i < str.size() ; i++ ){
			tmp = str.substr(i,str.size()-i);
			table.push_back(tmp);
		}

		sort(table.begin(), table.end());
		memset(check,0,sizeof(check));

		int maxpos,maxsize = 0;
		for(int i = table.size()-1 ; i > 0 ; i-- ){
			check[i] = thesame(table[i],table[i-1]);
			maxsize = max(maxsize,check[i]);
		}
		
		int k = 0;
		int kk = -1;
		bool getans = false;
		for(int i = 0 ; i < table.size() ; i++ ){
			if( !getans && check[i] == maxsize ){
				k++;
				kk= i;
			}
			else if( k != 0 )
				break;
		}

		if( maxsize == 0 )
			cout << "No repetitions found!\n" ;
		else
			cout << table[kk].substr(0,check[kk]) << " " << k+1 <<endl;

	}

	return 0;
}
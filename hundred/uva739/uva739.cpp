#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int table[] = {
	0,1,2,3,0,1,2,0,0,2,
	2,4,5,5,0,1,2,6,2,3,
	0,1,0,2,0,2
};

int main(int argc, char const *argv[])
{

	string str;
	printf("         NAME                     SOUNDEX CODE\n");

	while( cin >> str ){

		string tmp = "";
		tmp += str[0];
		int cnt = 3;
		int last = table[str[0]-'A'];
		for(int i = 1 ; i < str.size() ; i++ ){
			if( cnt == 0 ) break;
			int c = table[str[i]-'A'];
			if( c != last && c > 0 ){
				char k = '0'+c;
				tmp += k;
				cnt--;
			}
			last = c;
		}
		while( cnt-- ) tmp += "0";

		str = "         " + str ;
		while( str.size() != 34 ) str += " ";
		str += tmp;
		cout << str << endl;

	}

	printf("                   END OF OUTPUT\n");

	return 0;
}
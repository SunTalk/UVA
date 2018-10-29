#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10391"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 120000

vector<string> word(N);

unsigned int BKDRHash(const char str[]){

	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str){
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF) % 1000 ;
}

struct table{
	table(){
		data = -1;
		next = NULL;
	}
	int data;
	table *next;
};

table *tmp, *arr[1005];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int i;
	unsigned int number;

	for( i = 0 ; i < 1005 ; i++ )
		arr[i] = new table;

	i = 0;
	while( cin >> word[i] ){
		
		number = BKDRHash(word[i].c_str());

		if( arr[number]->next == NULL ){
			arr[number]->data = i;
			table *Newnode;
			Newnode = new table;
			arr[number]->next = Newnode; 
		}
		else{
			tmp = arr[number];
			while( tmp->next != NULL )
				tmp = tmp->next;
			tmp->data = i;
			table *Newnode;
			Newnode = new table;
			tmp->next = Newnode;
		}

		i++;
	}

	int TMP = i;
	string one,two;
	int check,j;
	// printf("fuck\n");
	for( i = 0 ; i < TMP ; i++ ){
		for( j = 1 ; j < word[i].size() ; j++ ){
			check = 0;
			one = word[i].substr(0,j);
			two = word[i].substr(j,word[i].size());
			number = BKDRHash(one.c_str());
			tmp = arr[number];
			while( tmp->data != -1 ){
				if( one == word[tmp->data] ){
					check++;
					break;
				}
				tmp = tmp->next;
			}
			number = BKDRHash(two.c_str());
			tmp = arr[number];
			while( tmp->data != -1 ){
				if( two == word[tmp->data] ){
					check++;
					break;
				}
				tmp = tmp->next;
			}

			if( check == 2 ){
				cout << word[i] << endl;
				break;
			}
		}
	}

	return 0;
}
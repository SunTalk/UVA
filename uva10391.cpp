#include <bits/stdc++.h>

using namespace std;

unsigned int BKDRHash(const char str[]){

	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str){
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF)%1200 ;
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	printf("fuck\n");

	string tmp;
	int size = 0;
	unsigned int seat;

	string word[1200];

	while( cin >> tmp ){
		word[size] = tmp;
		seat = BKDRHash(tmp.c_str());
		
		size++;
	} // end while cin

	
	return 0;
}
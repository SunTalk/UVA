#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 34943

int main(int argc, char const *argv[])
{

	string str;
	unsigned int crc;

	while( getline(cin,str) && str!="#" ){

		crc = 0;
		for(int i = 0 ; i < str.size() ; i++)
			crc = ((crc<<8)+str[i])%MAXN;
		crc = MAXN-(crc<<16)%MAXN;
		printf("%02X %02X\n",crc>>8,crc&0xff);

	}

	return 0;
}
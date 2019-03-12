#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "102"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int BCG,BGC,CBG,CGB,GBC,GCB;
	int one[3],two[3],three[3];
	int ans,i,j;
	string order;

	while( scanf("%d",&one[0]) != EOF ){//BGC

		scanf("%d %d",&one[1],&one[2]);
		scanf("%d %d %d",&two[0],&two[1],&two[2]);
		scanf("%d %d %d",&three[0],&three[1],&three[2]);
		//BGC 012
		BCG=one[1]+one[2]+two[0]+two[1]+three[0]+three[2];
		BGC=one[1]+one[2]+two[0]+two[2]+three[0]+three[1];
		CBG=one[0]+one[1]+two[1]+two[2]+three[0]+three[2];
		CGB=one[0]+one[1]+two[0]+two[2]+three[1]+three[2];
		GBC=one[0]+one[2]+two[1]+two[2]+three[0]+three[1];
		GCB=one[0]+one[2]+two[0]+two[1]+three[1]+three[2];

		ans=BCG;
		order="BCG";
		if(ans>BGC){
			ans=BGC;
			order="BGC";
		}
		if(ans>CBG){
			ans=CBG;
			order="CBG";
		}
		if(ans>CGB){
			ans=CGB;
			order="CGB";
		}
		if(ans>GBC){
			ans=GBC;
			order="GBC";
		}
		if(ans>GCB){
			ans=GCB;
			order="GCB";
		}

		cout << order << " " << ans << endl;
	}

	return 0;
}
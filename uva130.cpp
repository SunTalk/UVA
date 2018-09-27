#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int people[101];	
	int totle,kill;
	int tmp_clear,tmp_kill;
	int ans,i,j;

	while(1){
		
		for(i=0;i<101;i=i+1){
			people[i]=0;
		}

		cin >> totle >> kill;
		
		if(totle==0 && kill==0) break;
		if(totle==1){
			cout << "1" << endl;
			continue;
		}

		for(i=1;i<=totle;i=i+1){
			people[i]=i;
		}

		tmp_kill=0;

		for(i=1;i<totle;i=i+1){

			for(j=0;j<kill;j=j+1){
				tmp_kill=tmp_kill+1;
				if(tmp_kill>totle){
					tmp_kill=tmp_kill-totle;
				}

				if(people[tmp_kill]==0){
					j=j-1;
					continue;
				}
			}

			people[tmp_kill]=0;

			if(i==totle-1){
				break;
			}

			tmp_clear=tmp_kill;
			
			for(j=0;j<kill;j=j+1){
				tmp_clear=tmp_clear+1;
				if(tmp_clear>totle){
					tmp_clear=tmp_clear-totle;
				}

				if(people[tmp_clear]==0){
					j=j-1;
					continue;
				}
			}
			
			people[tmp_kill]=people[tmp_clear];
			people[tmp_clear]=0;
		}

		for(i=0;i<=totle;i=i+1){
			if(people[i]!=0) ans=people[i];
		}

		ans=totle+2-ans;
		if(ans>totle) ans=1;

		cout << ans << endl;

	}



	return 0;
}

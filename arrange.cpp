#include <bits/stdc++.h>

using namespace std;

int catch_num(string tmp){

	int num = 0;
	string check;
	for(int i = 0 ; i < tmp.size()-3 ; i++ ){
		if( i+3 < tmp.size() )
			check = tmp.substr(i,3);
		else
			return 0;
		check = tmp.substr(i,3);
		if( check == "uva" ){
			for(int j = i+3 ; j < tmp.size() ; j++ ){
				if( tmp[j] >= '0' && tmp[j] <= '9' )
					num = num*10 + tmp[j]-'0';
				else
					break;
			}
			break;
		}
	}
	return num;
}

int catch_str(string tmp){
	string check;
	for(int i = 0 ; i < tmp.size()-3 ; i++ ){
		if( i+3 < tmp.size() )
			check = tmp.substr(i,3);
		else
			return 0;
		if( check == "[x]" || check == "[X]" )
			return 1;
		if( check == "[ ]" )
			return 2;
	}
	return 0;
}

int main(int argc, char const *argv[])
{

	freopen("README.md","r",stdin);
	// freopen("READMEk.md","w",stdout);
	
	string str;
	vector <string> finish;
	vector <string> not_finish;
	while( getline(cin,str) ){
		int f_or_nf = catch_str(str);
		if( f_or_nf == 1 )
			finish.push_back(str);
		if( f_or_nf == 2 )
			not_finish.push_back(str);
	}

	sort(finish.begin(),finish.end());
	sort(not_finish.begin(),not_finish.end());

	vector<int> num_nf;
	vector<int> num_f;

	for(int i = 0 ; i < finish.size() ; i++ )
		num_f.push_back(catch_num(finish[i]));
	for(int i = 0 ; i < not_finish.size() ; i++ )
		num_nf.push_back(catch_num(not_finish[i]));


	freopen("README.md","w",stdout);
	printf("# UVA\n\n");
	printf("## Not Finish\n\n");
	printf("* part one\n");
	for(int i = 0 ; i < not_finish.size() ; i++ ){
		if( num_nf[i] < 1000 ){
			if( not_finish[i][0] != '\t' )
				cout << "\t";
			cout << not_finish[i] << endl;
		}
	}
	printf("\n");
	printf("* part two\n");
	for(int i = 0 ; i < not_finish.size() ; i++ ){
		if( num_nf[i] >= 1000 && num_nf[i] < 10000 ){
			if( not_finish[i][0] != '\t' )
				cout << "\t";
			cout << not_finish[i] << endl;
		}
	}
	printf("\n");
	printf("* part three\n");
	for(int i = 0 ; i < not_finish.size() ; i++ ){
		if( num_nf[i] >= 10000 && num_nf[i] < 100000 ){
			if( not_finish[i][0] != '\t' )
				cout << "\t";
			cout << not_finish[i] << endl;
		}
	}
	printf("\n");

	printf("## Finish\n\n");
	printf("* part one\n");
	for(int i = 0 ; i < finish.size() ; i++ ){
		if( num_f[i] < 1000 ){
			if( finish[i][0] != '\t' )
				cout << "\t";
			cout << finish[i] << endl;
		}
	}
	printf("\n");
	printf("* part two\n");
	for(int i = 0 ; i < finish.size() ; i++ ){
		if( num_f[i] >= 1000 && num_f[i] < 10000 ){
			if( finish[i][0] != '\t' )
				cout << "\t";
			cout << finish[i] << endl;
		}
	}
	printf("\n");
	printf("* part three\n");
	for(int i = 0 ; i < finish.size() ; i++ ){
		if( num_f[i] >= 10000 && num_f[i] < 100000 ){
			if( finish[i][0] != '\t' )
				cout << "\t";
			cout << finish[i] << endl;
		}
	}
	printf("\n");

	return 0;
}
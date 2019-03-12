#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

	string num = argv[1];
	cout << "enter the broblem name" << endl;
	string name;
	getline(cin,name);
	
	freopen("README.md","a",stdout);
	cout << "* [ ] uva" << num << " - " << name << endl;

	return 0;
}
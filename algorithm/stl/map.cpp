#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> m;
	string a = "abc";
	string b = "bcd";
	string c = "cde";
	m[a] = 1;
	m[b] = 2;
	m[c] = 3;

	map<string, int>::iterator it;
	for(it=m.begin(); it!=m.end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
	return 0;
}


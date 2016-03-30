#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "string";

	if(s=="string") printf("==\n");

	char c = s[0];
	printf("%c\n",c);
	printf("%s",s.substr(0,3).c_str());

	return 0;
}


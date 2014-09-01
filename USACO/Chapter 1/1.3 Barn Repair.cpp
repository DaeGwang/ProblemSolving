/*
ID: eorhkd1
PROG: barn1
LANG: C++ 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(i, a) FOR(i,0,a)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) x.size()
#define PB push_back
#define VI vector<int>
#define VS vector<string>
#define VC vector<char>
 
int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int m, s, c;
	fin >> m >> s >> c;
	VI stall, gap;
	REP(i, c)
	{
		int s;
		fin >> s;
		stall.PB(s);
	}
	sort(ALL(stall));

	REP(i, SZ(stall)-1)
	{
		gap.PB(stall[i+1] - stall[i] - 1);
	}

	sort(ALL(gap));

	int sum = 0;

	if(SZ(gap) < m){
		fout << c << endl;
	}
	else{
		REP(i, SZ(gap) - m + 1)
		{
			sum += gap[i];
		}

		fout << c + sum << endl;
	}
	return 0;
}
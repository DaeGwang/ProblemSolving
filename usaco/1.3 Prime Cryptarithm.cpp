/*
ID: eorhkd1
PROG: crypt1
LANG: C++ 
*/


#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

#define FOR(i,n,m) for(int i=n; i<m; i++)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((int)(v).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define MP make_pair
#define VI vector<int>
typedef long long ll;

VI pool;

int chk(int num){
	REP(i, SZ(pool))
	{
		if(pool[i] == num) return 1;
	}
	return -1;
}
int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int n, num;
	fin >> n;
	REP(i,n)
	{
		fin >> num;
		pool.PB(num);
	}
	int max = 0;
	FOR(a,1,10)
	{
		if(chk(a)==-1) continue;
		FOR(b,1,10)
		{
			if(chk(b)==-1) continue;
			FOR(c,1,10)
			{
				if(chk(c)==-1) continue;
				FOR(d,1,10)
				{
					if(chk(d)==-1) continue;
					FOR(e,1,10)
					{
						if(chk(e)==-1) continue;
						int ma, mb, mc, md, me;
						ma = a * 100 + b * 10 + c;
						mb = d * 10 + e;
						mc = ma * e;
						md = ma * d;
						me = ma * mb;

						if(mc<100 || mc>999) continue;
						if(md<100 || md>999) continue;
						if(me<1000 || me>9999) continue;
						if(chk(mc-mc/10*10)==-1) continue;
						if(chk(mc/10-mc/100*10)==-1) continue;
						if(chk(mc/100)==-1) continue;
						if(chk(md-md/10*10)==-1) continue;
						if(chk(md/10-md/100*10)==-1) continue;
						if(chk(md/100)==-1) continue;
						if(chk(me-me/10*10)==-1) continue;
						if(chk(me/10-me/100*10)==-1) continue;
						if(chk(me/100-me/1000*10)==-1) continue;
						if(chk(me/ 1000)==-1) continue;
						max++;
					}
				}
			}
		}
	}
	fout << max << endl;
}
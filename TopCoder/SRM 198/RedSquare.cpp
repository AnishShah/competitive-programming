#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define sz(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (n); i++)

/*
 * SRM 198 DIV 2 500 Problem
 */
class RedSquare {
public:
	int countTheEmptyReds(int maxRank, int maxFile, vector <int> rank, vector <int> file) {
		int ans = 0;
		REP(k, sz(rank)){
			if((rank[k]+file[k])%2 == maxFile%2){
				ans++;
			}
		}
		return (maxRank*maxFile)/2 - ans;
	}
};
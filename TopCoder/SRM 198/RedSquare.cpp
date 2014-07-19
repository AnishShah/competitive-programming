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
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}


class RedSquare {
public:
	int countTheEmptyReds(int maxRank, int maxFile, vector <int> rank, vector <int> file) {
		int checkersboard[51][51];
		FOR(i, 1, maxRank){
			FOR(j, 1, maxFile){
				if(maxFile % 2 == 1){
					checkersboard[i][j] = ((i % 2 == 1) & (j % 2 == 0)) | ((i % 2 == 0) & (j % 2 == 1));
				}else{
					checkersboard[i][j] = ((i % 2 == 1) & (j % 2 == 1)) | ((i % 2 == 0) & (j % 2 == 0));
				} 
			}
		}
		REP(i, sz(rank)){
			checkersboard[rank[i]][file[i]] = 0;
		}
		int ans = 0;
		FOR(i, 1, maxRank){
			FOR(j, 1, maxFile){
				ans += checkersboard[i][j];
			}
		}
		return ans;
	}
};
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
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define CHECK(S, j) (S & (1 << j))
#define SET(S, j) (S |= (1 << 0000j))
#define SETALL(S, j) (S = (1 << j)-1)
#define UNSET(S, j) (S &= ~(1 << j))
#define TOGGLE(S, j) (S ^= (1 << j))
#define LL long long
#define PI acos(-1)
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}


class MedalTable {
public:
	vector <string> generate(vector <string> results) {
		map<string, pair<int, pair<int, int> > > m;
		REP(i, sz(results)){
			m[results[i].substr(0, 3)].first++;
			m[results[i].substr(4, 3)].second.first++;
			m[results[i].substr(8, 3)].second.second++;
		}
		vector<pair<int, pair<int, pair< int, string > > > > medals;
		tr(m, i){
			medals.pb(mp(-(*i).second.first, mp(-(*i).second.second.first, mp(-(*i).second.second.second, (*i).first))));
		}
		sort(all(medals));
		vector<string> ans;
		REP(i, sz(medals)){
			char tally[30];
			sprintf(tally, "%s %d %d %d", medals[i].second.second.second.c_str(), -medals[i].first, -medals[i].second.first, -medals[i].second.second.first);
			//cout << tally << endl;
			ans.pb(tally);
		}
		return ans;
	}
};
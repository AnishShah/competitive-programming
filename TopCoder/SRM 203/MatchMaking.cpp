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


class MatchMaking {
public:
	string makeMatch(vector <string> namesWomen, vector <string> answersWomen, vector <string> namesMen, vector <string> answersMen, string queryWoman) {
		vector<pair<string, string> > women, men;
		map<string, string> couple;
		REP(i, sz(namesWomen)){
			women.pb(mp(namesWomen[i], answersWomen[i]));
			men.pb(mp(namesMen[i], answersMen[i]));
		}
		sort(all(women));
		sort(all(men));	
		REP(i, sz(women)){
			vector<pair<int, string > > matches;
			REP(j, sz(men)){
				string answerWoman = women[i].second;
				string answerMan = men[j].second;
				int correct = 0;
				REP(k, sz(answerWoman)){
					if(answerWoman[k] == answerMan[k]){
						correct++;
					}
				}
				matches.pb(mp(-correct, men[j].first));
			}
			sort(all(matches));
			couple[women[i].first] = matches[0].second;
			women.erase(women.begin()+i);			
			REP(j, sz(men)){
				if(matches[0].second == men[j].first){
					men.erase(men.begin()+j);
					break;
				}
			}
			i--;
		}
		return couple[queryWoman];
	}
};
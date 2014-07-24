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
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define mp make_pair


class RegularSeason {
public:
	vector <string> finalStandings(vector <string> teams, int rounds) {
	    int probability[20][20];
	    map<int, string> teamNames;
	    REP(i, sz(teams)){
	        istringstream iss(teams[i]);
	        string tname;
	        iss >> tname;
	        teamNames[i] = tname;
	        REP(j, sz(teams)){
	            iss >> probability[i][j];
	        }
	    }
	    vector<pair<double, string> > scores;
	    REP(i, sz(teams)){
     	    double score = 0;
	        REP(j, sz(teams)){
	        	if(i!= j){
	            	score += probability[i][j]*1.0*rounds/100 + (100 - probability[j][i])*1.0*rounds/100;
	            }
	        }
	        scores.pb(mp(-score, teamNames[i]));
	    }
	    sort(all(scores));
	    vector<string> ans;
	    REP(i, sz(scores)){
	    	ostringstream oss;
	    	oss << scores[i].second << " " << (int)(-scores[i].first + 0.5);
	    	ans.pb(oss.str());
	    }
	    return ans;
	}
};
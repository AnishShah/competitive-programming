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
#define sz(c) (int)(c).size()
#define pb push_back
#define all(c) (c).begin(), (c).end()

/* SRM 195 DIV 2 500 Problem
 * 
 * To determine MFS - find the smallest `N` fans which are a valid
 * failure set, but the smallest `N+1` are not.
 *
 * To determine MFC - you can repeat the MFS algorithm but use the 
 * largest fans instead of the smallest fans.
 */
class FanFailure {
public:
	vector <int> getRange(vector <int> capacities, int minCooling) {
	    int MFS = 0, MFC = 0;
	    sort(all(capacities));
	    int total = accumulate(all(capacities), 0);
	    int i = 0;
	    while(total >= minCooling){
	        total -= capacities[i];
		i++;
	    }
	    MFS = i-1;
	    total = accumulate(all(capacities), 0);
	    i = sz(capacities)-1;
	    while(total >= minCooling){
	        total -= capacities[i];
		i--;
	    }
	    MFC = sz(capacities)-i-2;
	    vi ans;
	    ans.pb(MFS);
	    ans.pb(MFC);
	    return ans;    
	}
};

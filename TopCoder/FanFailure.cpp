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
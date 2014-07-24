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
#define REP(i, n) for(int i = 0; i < (n); i++)


class grafixCorrupt {
public:
	int selectWord(vector <string> dictionary, string candidate) {
		int m = 0, index = -1;
	    REP(i, sz(dictionary)){
	        int count = 0;
	        REP(j, sz(candidate)){
	            if(candidate[j] == dictionary[i][j]){
	                count++;
	            }
	        }
	        if(count > m && count != 0){
	            m = count;
	            index = i;
	        }
	    }
	    return index;
	}
};
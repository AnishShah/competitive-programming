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
#define sz(c) (int)(c.size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}

/* SRM 196 DIV 2 500 Problem
 * 
 * This is a brute force problem. First, check if the current counter for threshold satisfies both the 
 * condition.
 * If yes, return the current counter.
 * If not, increment the counter. 
 */
class ClapLight {
public:
	int threshold(vector <int> background) {
		int i = 1;
		while(i){
			int count = 0;
			for(int j = 0; j < sz(background); j++){
				if(background[j] < i){
					count++;
				}
			}
			bool correct = true;
			for(int j = 0; j < sz(background)-3; j++){
				if(background[j] < i && background[j+1] >= i && background[j+2] >= i && background[j+3] < i){
					correct= false; break;
				}
			}
			if(count*100.0/sz(background) > 50 && correct){
				return i;
			}
			i++;
		}
	}
};
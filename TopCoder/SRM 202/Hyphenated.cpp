#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
#include <ctime>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (n); i++)

class Hyphenated {
public:
	double avgLength(vector <string> lines) {
		int count = 0, words = 0;
		REP(i, sz(lines)){
			REP(j, sz(lines[i])){
				if(isalpha(lines[i][j])){
					count++;
					if(j == sz(lines[i])-1){
						words++;
					}else if(!isalpha(lines[i][j+1])){
						if(j+1 == sz(lines[i])-1){
							if(lines[i][j+1] == '-' && i != sz(lines)-1 && !isalpha(lines[i+1][0])){
								words++;
							}else if(!isalpha(lines[i][j+1])){
								cout << lines[i][j];
								words++;
								if(i != sz(lines)-1 && lines[i][j+1] =='-')
									words--;
							}
						}else{
							words++;
						}
					}
				}
			}
		}
		return count*1.0/words;
	}
};
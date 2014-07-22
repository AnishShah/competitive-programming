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
#define sz(c) (c).size()
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
#define REP(i, n) for(int i = 0; i < (n); i++)

class Aaagmnrs {
private:
	string toanagram(string s){
		transform(all(s), s.begin(), ::tolower);
    	sort(all(s));
    	while(s[0] == ' ')
    	    s = s.substr(1);
    	return s;
	}
public:
	vector <string> anagrams(vector <string> phrases) {
		set<string> s;
   		REP(i, sz(phrases)){
        	string temp = toanagram(phrases[i]);
        	if(present(s, temp)){
        	    phrases.erase(phrases.begin()+i);
        	    i--;
        	}else{
        	    s.insert(temp);
        	}
    	}
    	return phrases;
	}
};
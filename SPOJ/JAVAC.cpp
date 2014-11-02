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
#define tr(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define CHECK(S, j) (S & (1 << j))
#define SET(S, j) (S |= (1 << j))
#define SETALL(S, j) (S = (1 << j)-1)
#define UNSET(S, j) (S &= ~(1 << j))
#define TOGGLE(S, j) (S ^= (1 << j))
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}
#define modulo 1000000007
#define LL long long

int main(){
	string variable;
	while(getline(cin, variable)){
		if(!isalpha(variable[0]) || !islower(variable[0])){
			cout << "Error!" << endl;
		}else if(!isalpha(variable[sz(variable)-1])){
			cout << "Error!" << endl;
		}else if(variable.find('_') != -1){
		 	string ans = "";
		 	int i = 0;
		 	bool ok = true;
		 	while(i < sz(variable)){
		 		if(variable[i] == '_'){
		 			if(i > 0 && variable[i-1] == '_'){
		 				ok = false;
		 				break;
		 			}
		 		}else if(isupper(variable[i])){
		 			ok = false;
		 			break;
		 		}else if(i > 0 && variable[i-1] == '_'){
		 			ans += toupper(variable[i]);
		 		}else{
		 			ans += variable[i];
		 		}
		 		i++;
		 	}
		 	if(ok){
		 		cout << ans << endl;
		 	}else{
		 		cout << "Error!" << endl;
		 	}
		}else{
		 	string ans = "";
		 	int i = 0;
		 	while(i < sz(variable)){
				if(isupper(variable[i])){
					ans += '_';
					ans += tolower(variable[i]);
				}else{
					ans += variable[i];
				}
				i++;
			}
			cout << ans << endl;
		}
	}
}
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

int main(){
	int t;
	cin >> t;
	while(t--){
		char a[50], b[50], c[50];
		scanf("%s %*s %s %*s %s", a, b, c);
		string a_str(a), b_str(b), c_str(c);
		if(a_str.find("machula") != -1){
			int bb, cc;
			sscanf(b, "%d", &bb);
			sscanf(c, "%d", &cc);
			printf("%d + %d = %d\n", cc-bb, bb, cc);
		}else if(b_str.find("machula") != -1){
			int aa, cc;
			sscanf(a, "%d", &aa);
			sscanf(c, "%d", &cc);
			printf("%d + %d = %d\n", aa, cc-aa, cc);		
		}else{
			int aa, bb;
			sscanf(a, "%d", &aa);
			sscanf(b, "%d", &bb);
			printf("%d + %d = %d\n", aa, bb, aa+bb);
		}
	}
}
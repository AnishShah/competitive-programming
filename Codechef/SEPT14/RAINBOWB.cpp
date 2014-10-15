#include<bits/stdc++.h>
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
#define LL long long
#define CHECK(S, j) (S & (1 << j))
#define SET(S, j) (S |= (1 << j))
#define SETALL(S, j) (S = (1 << j)-1)
#define UNSET(S, j) (S &= ~(1 << j))
#define TOGGLE(S, j) (S ^= (1 << j))
#define modulo 1000000007
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}

LL dp[8][1000001];

LL getCount(int extra){
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= extra; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i <= 7; i++){
		for(int j = 1; j <= extra; j++){
			dp[i][j] = dp[i][j]%modulo + dp[i][j-1]%modulo + dp[i-1][j]%modulo;
		}
	}
	return dp[7][extra] % modulo;
}

int main(){
	int N;
	cin >> N;
	int extra;
	if(N % 2 == 1){
		extra = (N-13)/2;
	}else{
		extra = (N-14)/2;
	}
	cout << getCount(extra+1) << endl;
}
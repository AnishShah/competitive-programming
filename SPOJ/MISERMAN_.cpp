#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int dp[101][101];

int main(){
	int N, M, x = 10000000;
	cin >> N >> M;
	FOR(i, 0, 100)
		FOR(j, 0, 100)
			dp[i][j] = 10000000;
	FOR(i, 0, 100)
		dp[0][i] = 0;
	FOR(i, 1, N){
		FOR(j, 1, M){
			cin >> dp[i][j];
			dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]))+dp[i][j];
		}
	}
	FOR(i, 1, M){
		x = min(x, dp[N][i]);
	}
	cout << x << endl;
	return 0;
}
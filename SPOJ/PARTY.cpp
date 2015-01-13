#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int dp[105][505];

int main(){
	int M, N;
	cin >> M >> N;
	while(M != 0 || N != 0){
		memset(dp, 0, sizeof(dp));
		vector<int> v(N+1), w(N+1);
		FOR(i, 1, N){
			cin >> w[i] >> v[i];
		}
		FOR(i, 1, N){
			FOR(j, 0, M){
				if(w[i] <= j){
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
				}else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		int idx = 0;
		while(dp[N][idx] != dp[N][M]) idx++;
		cout << idx << " " << dp[N][M] << endl;
		cin >> M >> N;
	}
	return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define all(c) (c).begin(), (c).end()
const int INF = 1 << 30;

int dp[505][10000];

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int E, F;
		scanf("%d %d", &E, &F);
		int W = F-E;
		int N;
		scanf("%d", &N);
		vector<int> v(N+1), w(N+1);
		FOR(i, 1, N){
			scanf("%d %d", &v[i], &w[i]);
		}
		FOR(i, 0, W) dp[0][i] = INF;
		dp[0][0] = 0;
		FOR(i, 1, N){
			FOR(j, 1, W){
				dp[i][j] = dp[i-1][j];
				if(w[i] <= j)
					dp[i][j] = min(dp[i][j], dp[i][j-w[i]]+v[i]);
			}
		}
		if(dp[N][W] == INF) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[N][W]);
	}
}
#include <stdio.h>
#include <string.h>
#define FOR(i, a, b) for(i = (a); i <= (b); i++)

int dp[101][101];

int max(int a, int b){
	if(a > b) return a;
	return b;
}

int main(){
	int T, i, j, N, M, x = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		memset(dp, 0, sizeof(dp));
		FOR(i, 1, N){
			FOR(j, 1, M){
				scanf("%d", &dp[i][j]);
				dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]))+dp[i][j];
				x = max(x, dp[i][j]);
			}
		}
		printf("%d\n", x);
		x = 0;
	}
	return 0;
}
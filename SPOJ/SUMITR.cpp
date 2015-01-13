#include <iostream>
#include <cstring>
using namespace std;
int dp[105][105], buses[105][105];
int f(int i, int j){
	if(i < 0) return 0;
	int path1 = 0, path2 = 0;
	if(j == 0){
		if(dp[i-1][j]) path1 = dp[i-1][j];
		else path1 = f(i-1, j), dp[i-1][j] = path1;
	}else if(j == i){
		if(dp[i-1][j-1]) path1 = dp[i-1][j-1];
		else path1 = f(i-1, j-1), dp[i-1][j-1] = path1;
	}else{
		if(dp[i-1][j]) path1 = dp[i-1][j];
		else path1 = f(i-1, j), dp[i-1][j] = path1;
		if(dp[i-1][j-1]) path2 = dp[i-1][j-1];
		else path2 = f(i-1, j-1), dp[i-1][j-1] = path2;
	}
	return buses[i][j] + max(path1, path2);
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 0; i < N; i++)
			for(int j = 0;j <= i; j++)
				cin >> buses[i][j];
		int m = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < N; i++)
			m = max(m, f(N-1, i));
		cout << m << endl;
	}
}
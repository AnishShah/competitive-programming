#include <iostream>
using namespace std;

int main(){
	int S[] = {1, 2, 5, 10, 20, 50, 100, 200};
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		long long dp[100001] = {1};	
		for(int i = 0; i < 8; i++){
			for(int j = S[i]; j <= N; j++){
				dp[j] = dp[j] + dp[j-S[i]];
			}
		}
		cout << dp[N] << endl;
	}
}
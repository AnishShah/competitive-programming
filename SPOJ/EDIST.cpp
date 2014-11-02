#include <iostream>
#include <cstring>
using namespace std;
#define sz(c) (c).size()
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int dp[2005][2005];

int main(){
	int T;
	cin >> T;
	while(T--){
		string A, B;
		cin >> A >> B;
		FOR(i, 0, sz(A)-1){
			dp[i][0] = i;
		}
		FOR(i, 0, sz(B)-1){
			dp[0][i] = i;
		}
		FOR(i, 1, sz(A)){
			FOR(j, 1, sz(B)){
				bool match = A[i-1] != B[j-1];
				if(match)
					dp[i][j] = min(dp[i-1][j-1]+match, min(dp[i][j-1], dp[i-1][j])+1);
				else
					dp[i][j] = dp[i-1][j-1];
			}
		}
		cout << dp[sz(A)][sz(B)] << endl;
	}
	return 0;
}
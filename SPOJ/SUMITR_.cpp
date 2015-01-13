#include <iostream>
using namespace std;
#define f(a,b,c) for(a=b;a<=c;a++)
int dp[100][100],T,N,i,j,x;
int main(){
	cin >> T;
	while(T--){
		cin >> N;
		f(i,1,N)
			f(j,1,i){
				cin >> dp[i][j];
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j])+dp[i][j];
				x = max(x, dp[i][j]);
			}
		cout << x << endl;
		x=0;
	} 
	return 0;
}
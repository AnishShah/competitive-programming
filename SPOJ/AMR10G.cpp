#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		vector<int> heights(N);
		REP(i, N){
			cin >> heights[i];
		}
		sort(all(heights));
		int m = INT_MAX;
		FOR(i, 0, N-K){
			m = min(m, heights[i+K-1]-heights[i]);
		}
		cout << m << endl;
	}
}
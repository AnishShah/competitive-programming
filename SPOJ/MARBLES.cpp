#include <iostream>
using namespace std;
#define LL long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int main(){
	int T;
	cin >> T;
	while(T--){
		LL n, k, tot;
		cin >> n >> k;
		tot = n;
		int diff = n - k;
		LL ans = k;
		FOR(i, 1, k){
			ans *= n;
			n--;
		}
		FOR(i, 2, k){
			ans /= i;
		}
		ans /= tot;
		cout << ans << endl;
	}
}
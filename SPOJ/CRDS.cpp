#include <iostream>
using namespace std;
#define LL long long
#define modulo 1000007

int main(){
	int T;
	cin >> T;
	while(T--){
		LL N;
		cin >> N;
		LL ans = N * (N + 1) + N * (N -1) / 2;
		cout << ans % modulo << endl;
	}
}
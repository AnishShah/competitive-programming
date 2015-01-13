#include <iostream>
using namespace std;
#define LL long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

LL power(LL base, LL exponent, int mod){
    LL res = 1;
    while ( exponent > 0 ) {
        if ( exponent&1 ) res = (res*base)%mod;
        base = (base*base)%mod;
        exponent >>= 1;
    }
    return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int N, M, Q;
		cin >> N >> M >> Q;
		while(Q--){
			int r;
			cin >> r;
			LL num = 1, den = 1;
			FOR(i, N-r+1, N){
				num = (num*power(i, i, M)) % M;
			}
			FOR(i, 2, r){
				den = (den*power(i, i, M)) % M;
			}
			LL ans = num/den % M;
			cout << ans << endl;
		}
	}
}

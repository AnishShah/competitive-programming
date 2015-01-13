#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define LL long long

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
	FOR(i, 1, t){
		int b, m;
		LL e;
		cin >> b >> e >> m;
		cout << i << ". "<< power(b, e, m) << endl;
	}
}
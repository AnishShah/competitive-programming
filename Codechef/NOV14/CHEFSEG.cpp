#include <iostream>
#include <iomanip>
using namespace std;
#define pb push_back
#define REP(i, n) for(int i = 0; i < (n); i++)
#define sz(c) (c).size()
#define LL long long

int main(){
	int t;
	cin >> t;
	while(t--){
		double X;
		LL K;
		cin >> X >> K;
		LL pow = 1;
		while(K >= pow){ pow = pow << 1; }
		double base = X*1.0 / pow;
		cout << setprecision(15) << base*(2*(K-pow/2)+1) << endl;
	}
}
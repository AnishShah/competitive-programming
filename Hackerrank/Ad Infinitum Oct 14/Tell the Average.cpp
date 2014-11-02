#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define LL long long
#define all(c) (c).begin(), (c).end()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define modulo 1000000007

int main(){
	int N;
	cin >> N;
	vector<LL> L(N);
	LL sum = 0;
	cin >> sum;
	REP(i, N-1){
		cin >> L[i];
		sum = (sum % modulo + L[i] % modulo + sum*L[i] % modulo) % modulo;
	}
	cout << sum % modulo << endl;
}
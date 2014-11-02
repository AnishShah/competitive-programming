#include <iostream>
using namespace std;
#define LL long long

int main(){
	int T;
	cin >> T;
	while(T--){
		LL N;
		cin >> N;
		LL ans = N*(N+1)/2 + N;
		cout << ans << endl;
	}
}
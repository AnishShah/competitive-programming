#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int ans = 0;
	while(N != 0){
		int digit = N % -2;
		ans = ans * 10 + digit;
		N /= -2;
	}
	cout << ans << endl;
	return 0;
}
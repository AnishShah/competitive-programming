#include <iostream>
using namespace std;

int totient(int n){
	int result = n;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			result -= result/i;
		}
		while(n % i == 0){
			n /=i;
		}
	}
	if(n > 1) result -= result / n;
	return result;
}
 
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		cout << totient(n) << endl;
	}
}
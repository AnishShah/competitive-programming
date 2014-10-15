#include <iostream>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	map<int, int> m;
	bool ok = true;
	int cnt = 0;
	while(N != 1){
		int temp = N;
		int sum = 0;
		while(temp != 0){
			int dig = temp % 10;
			sum += dig*dig;
			temp /= 10;
		}
		if(m[sum] != 0){
			ok = false;
			break;
		}else{
			m[sum]++;
		}
		N = sum;
		cnt++;
	}
	if(ok){
		cout << cnt << endl;
	}else{
		cout << -1 << endl;
	}
}
#include <iostream>
#include <cmath>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

void power2(int num){
	if(num == 0){
		cout << "0";
		return;
	}
	while(num != 0){
		cout << "2";
		int power = log2(num);
		if(power != 1) {
			cout << "(";
			power2(power);
			cout << ")";
		}
		num -= pow(2, power);
		if(num != 0){
			cout << "+";
		}
	}
}


int main(){
	int a[] = {137, 1315, 73, 136, 255, 1384, 16385};
	REP(i, 7){
		cout << a[i] << "=";
		power2(a[i]);
		cout << endl;
	}
	return 0;
}
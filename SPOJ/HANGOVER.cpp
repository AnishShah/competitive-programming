#include <iostream>
using namespace std;

int main(){
	double d;
	cin >> d;
	while(d != 0.0){
		int sum = 2;
		while(d > 0){
			d -= 1.0/sum;
			sum++;
		}
		cout << sum-2 << " card(s)" <<endl;
		cin >> d;
	}
}
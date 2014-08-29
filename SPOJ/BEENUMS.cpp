#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int N;
	cin >> N;
	while(N != -1){
		int q = N-1;
		double root = sqrt(1 + 4 * (q/3.0));
		if((int)root == root){
			cout << "Y" << endl;
		}else{
			cout << "N" << endl;
		}
		cin >> N;
	}
	return 0;
}
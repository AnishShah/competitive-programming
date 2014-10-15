#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int dig = N % 10;
	if(dig == 0){
		cout << 2 << endl ;
	}else{
		cout << 1 << endl << dig << endl;
	}
	return 0;
}
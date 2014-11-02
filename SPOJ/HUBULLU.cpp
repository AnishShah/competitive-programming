#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int N, turn;
		cin >> N >> turn;
		if(turn == 0){
			cout << "Airborne wins." << endl;
		}else{
			cout << "Pagfloyd wins." << endl;	
		}
	}
}
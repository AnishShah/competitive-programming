#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		if(M >= N){
			if(N % 2 == 1){
				cout << "R" << endl;
			}else if(N % 2 == 0){
				cout << "L" << endl;
			}
		}else{
			if(M % 2 == 1){
				cout << "D" << endl;
			}else{
				cout << "U" << endl;
			}
		}
	}
	return 0;
}
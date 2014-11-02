#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		int ma = 0, mi = 999999999;
		REP(i, M){
			int temp; 
			cin >> temp;
			ma = max(ma, temp);
			mi = min(mi, temp);
		}
		REP(i, N){
			cout << max(abs(ma-i), abs(mi-i)) << " ";
		}
		cout << endl;
	}
}
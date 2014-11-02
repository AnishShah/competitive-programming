#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define all(c) (c).begin(), (c).end()

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
        cin >> N;
		vector<string> str(N);
		REP(i, N){
			cin >> str[i];
			sort(all(str[i]));
		}
		bool ok = true;
		REP(i, N){
			FOR(j, 1, N-1){
				if(str[j-1][i] > str[j][i]){
					ok = false;
				}
			}
		}
		if(ok){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
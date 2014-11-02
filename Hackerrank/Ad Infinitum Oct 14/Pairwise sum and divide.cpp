#include <iostream>
#include <vector>
using namespace std;
#define LL long long
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<LL> A(N);
		LL sum = 0, cnt = 0, cnt2 = 0;
		REP(i, N){
			cin >> A[i];
		}
		REPD(i, N){
			if(A[i] == 1){
				sum += (N-i-1) + cnt;
				cnt++;
			}else{
				sum += cnt;
				if(A[i] == 2){
					sum += cnt2;
					cnt2++;
				}
			}
		}
		cout << sum << endl;
	}
}
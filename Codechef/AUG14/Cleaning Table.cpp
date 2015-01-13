#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define all(c) (c).begin(), (c).end()

const int MAXN = 400;

int main(){
	int T;
	cin >> T;
	
	vector<bool> present(MAXN+1);
	vector<int> customer(MAXN+1);
	vector<int> last_use(MAXN+1);
	vector<int> seen_before(MAXN+1);

	while(T--){
		int N, M;
		cin >> N >> M;
		REP(i, M){
			cin >> customer[i];
			last_use[customer[i]] = i;
		}
		fill(all(present), false);
		fill(all(seen_before), 0);
		int cnt = 0, occ = 0;
		REP(i, M){
			if(!present[customer[i]]){
				if(occ < N){
					if(!present[customer[i]]){
						cnt++;
						present[customer[i]] = true;
						occ++;
					}
				}else{
					int victim = -1;
					REPD(j, i){
						if(present[customer[j]] && last_use[customer[j]] == j){
							victim = customer[j];
							break;
						}
					}
					if(victim == -1){
						FOR(j, i+1, M){
							if(present[customer[j]] && seen_before[customer[j]] != i){
								victim = customer[j];
								seen_before[customer[j]] = i;
							}
						}
					}
					present[victim] = false;
					cnt++;
					present[customer[i]] = true;
				}
			}
		}
		cout << cnt << endl;
	}
}
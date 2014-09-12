#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define sz(c) (c).size()
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)

int main(){
	int n;
	cin >> n;
	while(n){
		vi nums(n);
		map<int, int> m;
		REP(i, n){
			cin >> nums[i];
			m[nums[i]] = i+1;
		}
		bool ok = true;
		REP(i, n){
			if(nums[i] != m[i+1]){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << "ambiguous" << endl;
		}else{
			cout << "not ambiguous" << endl;
		}
		cin >> n;
	}
}
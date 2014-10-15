#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()
#define sz(c) (c).size()

int main(){
	int N;
	cin >> N;
	set<string> frnds, frndsoffrnd;
	REP(i, N){
		string fid;
		cin >> fid;
		frnds.insert(fid);
		int M;
		cin >> M;
		REP(j, M){
			string fofid;
			cin >> fofid;
			frndsoffrnd.insert(fofid);
		}
	}
	vector<string> ans;
	set_difference(all(frndsoffrnd), all(frnds), inserter(ans, ans.begin()));
	cout << sz(ans) << endl;
	return 0;
}
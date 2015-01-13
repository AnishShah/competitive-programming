#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair
#define REP(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()

int main(){
	int T;
	cin >> T;
	while(T--){
		int m1, m2;
		cin >> m1;
		vi mount1(m1);
		REP(i, m1) cin >> mount1[i];
		cin >> m2;
		vi mount2(m2);
		REP(i, m2) cin >> mount2[i];
		vector<pair<int, int> > points;
		REP(i, m1) points.pb(mp(mount1[i], 1));
		REP(i, m2) points.pb(mp(mount2[i], 2));
		sort(all(points));
		int last_mount1 = -1, last_mount2 = -1;
		int m = 999999999;
		REP(i, m1+m2){
			if(points[i].second == 2){
				last_mount2 = points[i].first;
			//	cout << last_mount2 << endl;
				if(last_mount1 != -1){
					m = min(m, abs(last_mount2-last_mount1));
				}
			}else{
				last_mount1 = points[i].first;
			//	cout << last_mount1 << endl;
				if(last_mount2 != -1){
					m = min(m, abs(last_mount2-last_mount1));
				}
			}
		}
		cout << m << endl;
	}
}
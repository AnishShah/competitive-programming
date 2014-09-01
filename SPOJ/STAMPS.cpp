#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int T;
	cin >> T;
	REP(k, T){
		int rem, frnds;
		cin >> rem >> frnds;
		vector<int> stamps(frnds);
		REP(i, frnds){
			cin >> stamps[i];
		}
		sort(stamps.rbegin(), stamps.rend());
		int i = 0;
		while(i < frnds && rem > 0){
			rem -= stamps[i];
			i++;
		}
		if(rem > 0){
			cout << "Scenario #" << k+1 <<":"<<endl;
			cout << "impossible" << endl << endl;
		}else{
			cout << "Scenario #" << k+1 <<":"<<endl;
			cout << i << endl << endl;
		}
	}
}
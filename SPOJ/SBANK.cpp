#include <iostream>
#include <map>
using namespace std;
#define tr(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<string, int> m;
		string str;
		getline(cin, str);
		REP(i, n){
			getline(cin, str);
			m[str]++;
		}
		tr(m, i){
			cout << i->first << " " << i->second << endl;
		}
		cout << endl;
	}
	return 0;
}
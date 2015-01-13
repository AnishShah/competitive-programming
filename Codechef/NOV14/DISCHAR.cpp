#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define sz(c) (c).size()

int main(){
	int t;
	cin >> t;
	while(t--){
		string N;
		cin >> N;
		bool a[26];
		fill(a, a+26, false);
		int cnt = 0, m = 0;
		string ans = "";
		REP(i, sz(N)){
			if(!a[N[i]-'a']){
				ans += N[i];
				a[N[i]-'a'] = true;
			}
		}
		cout << sz(ans) << endl;
	}
}
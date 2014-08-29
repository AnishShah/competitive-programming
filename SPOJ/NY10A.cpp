#include <iostream>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define sz(c) (c).size()

int main(){
	int P;
	cin >> P;
	while(P--){
		int i;
		string s;
		cin >> i >> s;
		map<string, int> m;
		REP(i, sz(s)-2){
			m[s.substr(i, 3)]++;
		}
		cout << i << " " << m["TTT"] << " " << m["TTH"] << " " << m["THT"] << " " << m["THH"] << " " << m["HTT"] << " " << m["HTH"] << " " << m["HHT"] << " " << m["HHH"] << endl;
	}
}
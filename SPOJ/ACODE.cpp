#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
#define sz(c) (c).size()
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
int toint(string t){stringstream s(t); int ret; s >> ret;return ret;}

int main(){
	int dp[5005];
	string str;
	cin >> str;
	while(str != "0"){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		FOR(i, 1, sz(str)){
			dp[i] = dp[i-1];
			if(i != sz(str)){
				string temp = str.substr(i-1, 2);
				if(toint(temp) <= 26 && toint(temp) >= 1){
					dp[i]++;
				}
				cout << temp << " " <<dp[i] << endl;
			}
		}
		cout << dp[sz(str)] << endl;
		cin >> str;
	}
}
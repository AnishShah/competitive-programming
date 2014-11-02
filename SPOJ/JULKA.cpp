#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define sz(c) (c).size()
#define pb push_back

string add(string a, string b){
	string ret(sz(a)+1, '0');
	int i = 1, carry = 0;
	while(i <= sz(b) && i <= sz(a)){
		int adig = a[sz(a)-i] - '0';
		int bdig = b[sz(b)-i] - '0';
		ret[sz(ret)-i] = '0' + (adig + bdig + carry) % 10;
		carry = (adig + bdig + carry) / 10;
		i++;
	}
	while(i <= sz(a)){
		int adig = a[sz(a)-i] - '0';
		ret[sz(ret)-i] = '0' + (adig + carry) % 10;
		carry = (adig + carry) / 10;
		i++;
	}
	ret[sz(ret)-i] = '0' + carry;
	while(ret[0] == '0') ret = ret.substr(1);
	return ret;
}

string sub(string a, string b){
	string ret(sz(a), '0');
	int i = 1, carry = 0;
	while(i <= sz(b) && i <= sz(a)){
		int adig = a[sz(a)-i] - '0';
		int bdig = b[sz(b)-i] - '0';
		ret[sz(ret)-i] = '0' + (10 + adig - bdig - carry) % 10;
		carry = (adig < (bdig+carry));
		i++;
	}
	while(i <= sz(a)){
		int adig = a[sz(a)-i] - '0';
		ret[sz(ret)-i] = '0' + (10 + adig - carry) % 10;
		carry = (adig < carry);
		i++;
	}
	while(ret[0] == '0') ret = ret.substr(1);
	if(sz(ret) == 0) return "0";
	return ret;
}

string div(string a){
	string ret;
	int i = 0, rem = 0;
	while(i < sz(a)){
		int adig = rem * 10 + (a[i] - '0');
		int ans = adig / 2;
		rem = adig % 2;
		ret.pb('0'+ans);
		i++;
	}
	while(ret[0] == '0') ret = ret.substr(1);
	if(sz(ret) == 0) return "0";
	return ret;
}

int main(){
	REP(i, 10){
		string n, k;
		cin >> n >> k;
		string xn = div(sub(n, k)), xk = sub(n, xn);
		cout << xk << endl << xn << endl;
	}
}
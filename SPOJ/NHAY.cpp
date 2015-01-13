#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define sz(c) (c).size()
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define LL long long
vector<int> transition(string P){
	vector<int> ret(sz(P));
	int k = 0;
	ret[0] = 0;
	FOR(i,1, sz(P)-1){
		while(k > 0 && P[k] != P[i])
			k = ret[k];
		if(P[k] == P[i])
			k++;
		ret[i] = k;
	}
	return ret;
}

int main(){
	LL l;
	while(scanf("%lld", &l) != EOF){
		string pat, text;
		cin >> pat >> text;
		vector<int> pi = transition(pat);
		int q = 0;
		FOR(i, 0, sz(text)-1){
			while(q > 0 && pat[q] != text[i])
				q = pi[q];
			if(pat[q] == text[i])
				q++;
			if(q == sz(pat)){
				cout << i-sz(pat)+1 << endl;
				q = pi[q-1];
			}
		}
	}
}
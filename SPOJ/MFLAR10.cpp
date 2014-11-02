#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define sz(c) (c).size()
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	string s;
	getline(cin, s);
	while(s != "*"){
		istringstream iss(s);
		vector<string> words;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
		char first = tolower(words[0][0]);
		bool ok = true;
		REP(i, sz(words)){
			ok &= (tolower(words[i][0]) == first);
		}
		if(ok){
			cout << "Y" << endl;
		}else{
			cout << "N" << endl;
		}
		getline(cin, s);
	}
}
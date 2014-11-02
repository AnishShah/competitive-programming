#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int N;
	cin >> N;
	vector<int> num(N);
	REP(i, N) cin >> num[i];
	
	return 0;
}
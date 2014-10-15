#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()

int main(){
	int A, D;
	cin >> A >> D;
	while(A && D){
		vector<int> defending(D), attacking(A);
		REP(i, A){
			cin >> attacking[i];
		}
		REP(i, D){
			cin >> defending[i];
		}
		sort(all(attacking));
		sort(all(defending));
		if(attacking[0] >= defending[1]){
			cout << "N" << endl;
		}else{
			cout << "Y" << endl;
		}
		cin >> A >> D;
	}
	return 0;
}
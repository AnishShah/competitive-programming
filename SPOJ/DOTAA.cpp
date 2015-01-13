#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int T;
	cin >> T;
	while(T--){
		int n, m, D;
		cin >> n >> m >> D;
		priority_queue<int> pq;
		REP(i, n){
			int temp;
			cin >> temp;
			pq.push(temp);
		}
		bool ok = true;
		REP(i, m){
			int top = pq.top();
			pq.pop();
			top -= D;
			ok &= (top > 0);
			if(!ok) break;
			pq.push(top);
		}
		if(ok){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
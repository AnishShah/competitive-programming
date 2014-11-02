#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define N 16
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int b[1 << N], c[1 << N];
int a[1 << N];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int m = 1 << n;
		REP(i, m){
			cin >> b[i];
		}
		sort(b, b+m);
		multiset <int> s;
		int fptr = 0, ptr = 0;
		FOR(i, 1, m-1){
			int expected = -1;
			if(!s.empty()){
				expected = *s.begin();
			}
			if(b[i] == expected){
				s.erase(s.begin());
			}else{
				a[fptr] = b[i];
				int tptr = ptr;
				REP(j, tptr){
					c[ptr] = c[j] + a[fptr];
					s.insert(c[ptr]);
					ptr++;
				}
				c[ptr++] = a[fptr];
				fptr++;
			}
		}
		REP(i, fptr) cout << a[i] << " ";
		cout << endl;
	}
}
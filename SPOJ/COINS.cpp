#include <iostream>
#include <map>
using namespace std;
#define LL long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))

map<int, LL> m;

LL f(int n){
	if(n == 0) return 0;
	LL r = m[n];
	if(r == 0){
		r = MAX(n, f(n/2)+f(n/3)+f(n/4));
		m[n] = r;
	}
	return r;
}

int main(){
	int n;
	while(cin >> n){
		cout << f(n) << endl;
	}
}
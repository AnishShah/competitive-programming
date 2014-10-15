#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define CHECK(S, j) (S & (1 << j))
#define SET(S, j) (S |= (1 << j))
#define SETALL(S, j) (S = (1 << j)-1)
#define UNSET(S, j) (S &= ~(1 << j))
#define TOGGLE(S, j) (S ^= (1 << j))
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}
#define modulo 1000000007
#define LL long long

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		queue<string> q;
		cin >> s;
		q.push(s);
		while(s != "="){
			cin >> s;
			if(s != "="){
				q.push(s);
			}
		}
		istringstream iss(q.front());
		q.pop();
		LL ans;
		iss >> ans;
		while(!q.empty()){
			string op = q.front();
			q.pop();
			istringstream iss1(q.front());
			q.pop();
			LL operand;
			iss1 >> operand;
			if(op == "+"){
				ans = ans + operand;
			}else if(op == "-"){
				ans = ans - operand;
			}else if(op == "*"){
				ans = ans * operand;
			}else{
				ans = ans / operand;
			}
		}
		cout << ans << endl;
	}
}
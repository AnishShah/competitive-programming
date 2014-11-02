#include <iostream>
#include <stack>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	string s;
	int cnt = 1;
	cin >> s;
	while(s.find('-') == -1){
		stack<char> st;
		int edit = 0;
		REP(i, sz(s)){
			if(s[i] == '}'){
				if(!st.empty()){
					st.pop();
				}else{
					edit++;
					st.push('{');
				}
			}else if(s[i] == '{'){
				st.push('{');
			}
		}
		
		cin >> s;
		cnt++;
	}
}
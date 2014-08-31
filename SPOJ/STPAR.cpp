#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int main(){
	int n;
	cin >> n;
	while(n){
		vector<int> nums(n);
		REP(i, n){
			cin >> nums[i];
		}
		stack<int> st;
		int i = 0, j = 1;
		while(i < n){
			if(nums[i] == j){
				j++;
			}else if(!st.empty() && st.top() == j){
				j++;
				st.pop();
				i--;
			}else{
				st.push(nums[i]);
			}
			i++;
		}
		while(!st.empty() && st.top() == j){
			st.pop();
			j++;
		}
		if(st.empty()){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
		cin >> n;
	}
	return 0;
}
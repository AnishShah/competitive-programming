#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define sz(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)


class GravityBomb {
public:
	vector <string> aftermath(vector <string> board) {
		REP(i, sz(board[0])){
			int count = 0;
			REP(j, sz(board)){
				if(board[j][i] == 'X'){
					count++;
				}
			}
			FOR(j, 1, count){
				board[sz(board)-j][i] = 'X';
			}
			FOR(j, 0, sz(board)-1-count){
				board[j][i] = '.';
			}
		}
		string temp(sz(board[0]), 'X');
		while(board[sz(board)-1] == temp){
			FORD(i, sz(board)-1, 1){
				board[i] = board[i-1];
			}
			string dots(sz(board[0]), '.');
			board[0] = dots;
		}
		return board;
	}
};
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
#include <ctime>
#include <limits.h>

using namespace std;
#define all(c) (c).begin(), (c).end()
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        vector<int> heights(N);
        REP(i, N){
            cin >> heights[i];
        }
        int max_height = *max_element(all(heights));
        REP(i, N){
            M = M - (max_height-heights[i]);
        }
        if(M >= 0 && M % N == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

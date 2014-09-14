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
typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vi mouse(n), holes(n);
        REP(i, n){
            cin >> mouse[i];
        }
        REP(i, n){
            cin >> holes[i];
        }
        sort(all(mouse));
        sort(all(holes));
        int ans = 0;
        REP(i, n){
            ans = max(ans, abs(mouse[i]-holes[i]));
        }
        cout << ans << endl;
    }
}

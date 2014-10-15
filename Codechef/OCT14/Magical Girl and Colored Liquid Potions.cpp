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
#define sz(c) (c).size()
#define all(c) (c).begin(), (c).end()
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
    int T;
    cin >> T;
    while(T--) {
        int R, G, B, M, max_red = 0, max_green = 0, max_blue = 0, temp;
        cin >> R >> G >> B >> M;
        REP(i, R){ cin >> temp; max_red = max(max_red, temp);}
        REP(i, G){ cin >> temp; max_green = max(max_green, temp);}
        REP(i, B){ cin >> temp; max_blue = max(max_blue, temp);}
        while(M--) {
            if (max_red > max_blue) {
                if (max_red > max_green) {
                    max_red /= 2;
                } else {
                    max_green /= 2;
                }
            } else {
                if (max_blue > max_green) {
                    max_blue /= 2;
                } else {
                    max_green /= 2;
                }
            }
        }
        cout << max(max_red, max(max_green, max_blue)) << endl;
    }
}

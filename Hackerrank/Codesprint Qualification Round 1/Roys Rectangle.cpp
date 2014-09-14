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
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        cout << min(min(abs(x-x1), abs(x-x2)), min(abs(y-y1), abs(y-y2))) << endl;
    }
    return 0;
}
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
#define sz(c) (c).size()
#define all(c) (c).begin(), (c).end()
int main() {
    int T;
    cin >> T;
    while(T--){
        string b, w;
        cin >> b >> w;
        sort(all(b));
        sort(all(w));
        vector<char> alphabets;
        set_intersection(all(b), all(w), back_inserter(alphabets));
        cout << sz(alphabets) << endl;
    }
    return 0;
}
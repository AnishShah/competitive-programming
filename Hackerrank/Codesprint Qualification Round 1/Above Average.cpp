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
typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define REP(i, n) for(int i = 0; i < (n); i++)

int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vi nums(n);
        int sum = 0;
        REP(i, n){
            cin >> nums[i];
            sum += nums[i];
        }
        double avg = sum*1.0/n;
        int cnt = 0;
        REP(i, n){
            if(nums[i] > avg){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
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
#define LL long long

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int arr[100000];
        LL sum = 0;
        REP(i, n) {
            cin >> arr[i];
            sum += arr[i];
        }
        if(sum % n == 0){
            cout << n << endl;
        }else {
            cout << n - 1 << endl;
        }
    }
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long

int main() {
    int T;
    cin >> T;
    while(T--){
        LL n;
        cin >> n;
        LL ans = n*(n+1)*(3*n*n - n - 2)/12;
        cout << abs(ans) << endl;
    }
    return 0;
}
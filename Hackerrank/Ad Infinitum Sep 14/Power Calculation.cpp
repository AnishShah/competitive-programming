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
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define LL long long
#define modulo 1000000007

LL power(LL base, LL exponent, int mod = modulo)
{
    LL res = 1;
    while ( exponent > 0 ) {
        if ( exponent&1 ) res = (res*base)%mod;
        base = (base*base)%mod;
        exponent >>= 1;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    while(T--) {
        LL K, N;
        cin >> K >> N;
        LL ans = 0;
        FOR(i, 0, 99){
            if(K < i) break;
            LL occurrence = (K-i)/100 + 1;
            if(i == 0) occurrence--;
            LL cost = power(i, N, 100);
            cost = (cost*occurrence)%100;
            ans = (ans+cost)%100;
        }
        if(ans/10==0) cout << 0;
        cout << ans << endl;
    }
    return 0;
}

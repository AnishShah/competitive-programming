#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long

LL gcd(LL a, LL b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

LL lcm(LL a, LL b)
{
    LL temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}


int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> factors;
        for(int i = 1; i <= N; i++){
            factors.push_back(i);
        }
        LL res = accumulate(factors.begin(), factors.end(), 1, lcm);
        cout << res << endl;
    }
    return 0;
}

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
        LL N;
        cin >> N;
        LL a = 1LL, b = 1LL, c = a+b, sum = 0;
        while(c <= N){
            sum += c;
            a = b + c;
            b = c + a;
            c = a + b;
        }
        cout << sum << endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long

bool isPrime(LL number){
    for(int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    vector<LL> primes;
    primes.push_back(2);
    LL cnt = 3;
    while(primes.size() < 10000){
        if(isPrime(cnt)){
            primes.push_back(cnt);
        }
        cnt += 2;
    }
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        cout << primes[N-1] << endl;
    }
    return 0;
}
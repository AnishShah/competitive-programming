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
        LL last_factor;
        if(N % 2 == 0){
            last_factor = 2;
            while(N % 2 == 0){
                N /= 2;
            }
        }else{
            last_factor = 1;
        }
        LL factor = 3;
        int max_factor = sqrt(N);
        while(N > 1 && factor <= max_factor){
            if(N % factor == 0){
                last_factor = factor;
                while(N % factor == 0){
                    N /= factor;
                }
                max_factor = sqrt(N);
            }
            factor += 2;
        }
        if(N == 1){
            cout << last_factor << endl;
        }else{
            cout << N << endl;
        }
    }
    return 0;
}

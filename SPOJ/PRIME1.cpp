#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int main() {
    //base primes
    bool base[31700] = {0};
    for(int i=3;i<31700; i+= 2) {
        if(base[i] == 1) continue;
        for(int j=i*i; j<31700; j+=i) {
            base[j] = 1;
        }
    }
    vector<int> bprimes;
    //bprimes.push_back(2);
    for(int i=3;i<31700;i += 2) {
        if(!base[i]) bprimes.push_back(i);
    }
    int T, M, N;
    scanf("%d", &T);
    for(int ll=0;ll<T;ll++) {
        scanf("%d %d", &M, &N);
        if(M < 3) {
            printf("%d\n", 2);
            M = 3;
        }
        if(M % 2 == 0) {
            M++;
        }
        bool segment[100001] = {0};
        //segment[0] corresponds to M
        for(int it = 0; it < bprimes.size(); it++) {
            int p = bprimes[it];
            if(p*p > N) break;
            int i = ceil((double)M / p);
            i = max(i, 2);
            //printf("%d %d %d\n", i, p, M);
            for(;i*p <= N; i++) {
                segment[i*p - M] = 1;
            }
        }
        for(int i=0;i<(N - M + 1); i+=2) {
            if(segment[i] == 0) {
                printf("%d\n", i + M);
            }
        }
        if(ll != T-1) {
            printf("\n");
        }
    }
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define LL long long

int main() {
	int n = 1000001;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= n; i++){
    	if(prime[i]){
    		for(int j = i*i; j < n; j+=i){
    			prime[j] = false;
    		}
    	}
    }
    LL sum[1000000];
    sum[0] = sum[1] = 0;
    sum[2] = 2;
    for(int i = 3; i < n; i++){
    	sum[i] = sum[i-1];
    	if(prime[i]){
    		sum[i] += i;
    	}
    }
    int T;
    scanf("%d", &T);
    while(T--){
    	int n;
    	scanf("%d", &n);
    	printf("%lld\n", sum[n]);
    }    
    return 0;
}
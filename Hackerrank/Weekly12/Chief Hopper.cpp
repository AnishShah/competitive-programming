#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()
#define LL long long
int h[100001], N;

bool satisfy(int energy){
    bool ok = true;
    LL en = energy;
    REP(i, N){
        en += en - h[i];
        if(en > 100000) return true;
        if(en < 0) return false;
    }
    return true;
}

int main() {
    cin >> N;
    REP(i, N) cin >> h[i];
    int low = *min_element(h, h+N), high = *max_element(h, h+N);
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        bool ok = satisfy(mid);
        if(ok && !satisfy(mid-1)){
            ans = mid;
            break;
        }else if(!ok && satisfy(mid+1)){
            ans = mid+1;
            break;
        }
        if(ok){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}

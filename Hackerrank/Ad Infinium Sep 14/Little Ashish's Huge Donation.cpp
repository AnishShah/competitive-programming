#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long

int main() {
    int t;
    cin >> t;
    while(t--){
        int low = 0, high = 1000000;
        LL x;
        cin >> x;
        while(low <= high){
            LL mid = (low+high)/2;
            LL tot = mid*(mid+1)*(2*mid + 1)/6;
            LL next_tot = (mid+1)*(mid+2)*(2*mid + 3)/6;
            LL prev_tot = mid*(mid-1)*(2*mid-1)/6;
            if(tot <= x && next_tot > x){
                cout << mid << endl;
                break;
            }else if(tot > x && prev_tot <= x){
                cout << mid-1 << endl;
                break;
            }else if(tot < x){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return 0;
}
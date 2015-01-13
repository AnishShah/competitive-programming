#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()


int main() {
    int N;
    cin >> N;
    vector<int> weight(N);
    REP(i, N) cin >> weight[i]; 
    sort(all(weight));
    int cnt = 1, cur = weight[0];
    REP(i, N){
        if(cur+4 < weight[i]){
            cnt++;
            cur = weight[i];
        }
    }
    cout << cnt << endl;
    return 0;
}
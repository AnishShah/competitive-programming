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
#define REP(i, n) for(int i = 0; i < (n); i++)

int buses[100][100], N, M;
int dp[100][100];
int f(int city, int bus_no){
    if(bus_no < 0 || bus_no >= M){
        return INT_MAX;
    }
    if(city+1 < N){
        int less, equal, great;
        if(bus_no > 0){
            if(dp[city+1][bus_no-1]){
                less = dp[city+1][bus_no-1];
            }else{
                less = f(city+1, bus_no-1);
                dp[city+1][bus_no-1] = less;
            }
        }else{
            less = INT_MAX;
        }
        if(dp[city+1][bus_no]){
            equal = dp[city+1][bus_no];
        }else{
            equal = f(city+1, bus_no);
            dp[city+1][bus_no] = equal;
        }
        if(bus_no+1 < M){
            if(dp[city+1][bus_no+1]){
                great = dp[city+1][bus_no+1];
            }else{
                great = f(city+1, bus_no+1);
                dp[city+1][bus_no+1] = great;
            }
        }else{
            great = INT_MAX;
        }
        int next_city = min(equal, min(less, great));
        return buses[city][bus_no] + next_city;
    }else{
        return buses[city][bus_no];
    }
}

int main(){
    cin >> N >> M;
    REP(i, N){
        REP(j, M){
            cin >> buses[i][j];
        }
    }
    int m = INT_MAX;
    memset(dp, 0, sizeof(dp));
    REP(i, M){
        m = min(m, f(0, i));
    }
    cout << m << endl;
}

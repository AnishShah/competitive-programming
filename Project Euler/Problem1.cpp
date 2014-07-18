#include <vector>
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
using namespace std;
#define LL long long
/* Project Euler - #1 - Multiples of 3 and 5
 * https://projecteuler.net/problem=1
 *
 * Use Arithmetic progression to find the answer in O(1) 
 * constant time.
 */
LL sumDivisibleBy(int divisible, LL N){
    return divisible*(N/divisible)*((N/divisible) + 1)/2;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        LL sum = sumDivisibleBy(3, N-1) + sumDivisibleBy(5, N-1) - sumDivisibleBy(15, N-1);
        cout << sum << endl;
    }
}

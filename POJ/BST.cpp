/* POJ 2309 - BST 
 * link - http://poj.org/problem?id=2309
 * 
 * Author : Anish Shah
 */
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
#define REP(i, n) for(int i = 0; i < (n); i++)
#define LL long long

int main() {
    int N;
    cin >> N;
    REP(t, N){
        LL X;
        cin >> X;
        int temp = 1;
        while(X/temp % 2 == 0){
            temp *= 2;
        }
        cout << (X - temp + 1) << " " << (X + temp - 1) << endl;
    }
    return 0;
}
 

/* POJ Problem 1799 : Yeehaa! 
*
* Link : http://poj.org/problem?id=1799
*
* Compiler : G++
*
* Author : anishshah
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
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define PI acos(-1)

int main(){
    int n;
    cin >> n;
    FOR(i, 1, n){
        int n;
        double R;
        cin >> R >> n;
        printf("Scenario #%d:\n%.3f\n\n", i, R/(1 + 1/sin(PI/n)));
    }
}


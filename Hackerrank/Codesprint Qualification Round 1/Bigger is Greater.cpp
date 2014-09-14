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
using namespace std;
#define all(c) (c).begin(), (c).end()

int main() {
    int T;
    cin >> T;
    while(T--){
        string w;
        cin >>  w;
        if(next_permutation(all(w))){
            cout << w << endl;
        }else{
            cout << "no answer" << endl;
        }
    }
    return 0;
}
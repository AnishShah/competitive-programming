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
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (c).size()
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define LL long long
#define CHECK(S, j) (S & (1 << j))
#define SET(S, j) (S |= (1 << j))
#define SETALL(S, j) (S = (1 << j)-1)
#define UNSET(S, j) (S &= ~(1 << j))
#define TOGGLE(S, j) (S ^= (1 << j))
#define modulo 1000000007
template<class T>string tostring(T t){stringstream s;s<<t;return s.str();}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vi nos(N);
        REP(i, N){
            cin >> nos[i];
        }
        bool ok = false;
        int index = -1;
        FOR(i, 1, N-1){
            if(nos[i-1] > nos[i]){
                if(!ok){
                    ok = true;
                    index = i;
                }
            }
        }
        int ans = 0;
        while(index < N-1 && index > 0 && nos[index] < nos[index+1]){
            index++;
            ans++;
        }
        if(!ok){
            cout << 0 << endl;
        }else if(index == N-1 && nos[0] >= nos[N-1]){
            cout << ans+1 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}

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
        int m, n;
        cin >> m >> n;
        char kingdom[100][100];
        int level[100][100];
        queue<int> q;
        REP(i, m){
            REP(j, n){
                cin >> kingdom[i][j];
                if(kingdom[i][j] >= 'A' && kingdom[i][j] <= 'Z'){
                    level[i][j] = 0;
                    q.push(i*n + j);
                }else{
                    level[i][j] = 999999999;
                }
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int c = node % n;
            int r = (node-c)/n;
            if(r - 1 > -1){
                if(level[r][c]+1 < level[r-1][c]){
                    kingdom[r-1][c] = kingdom[r][c];
                    q.push((r-1)*n+c);
                    level[r-1][c] = level[r][c]+1;
                }else if(level[r][c]+1 == level[r-1][c]){
                    if(kingdom[r][c] <= kingdom[r-1][c]){
                        q.push((r-1)*n+c);
                        kingdom[r-1][c] = kingdom[r][c];
                    }
                }
            }
            if(r + 1 < m){
                if(level[r][c]+1 < level[r+1][c]){
                    kingdom[r+1][c] = kingdom[r][c];
                    q.push((r+1)*n+c);
                    level[r+1][c] = level[r][c]+1;
                }else if(level[r][c]+1 == level[r+1][c]){
                    if(kingdom[r][c] <= kingdom[r+1][c]){
                        q.push((r+1)*n+c);
                        kingdom[r+1][c] = kingdom[r][c];
                    }
                }
            }
            if(c - 1 > -1){
                if(level[r][c]+1 < level[r][c-1]){
                    kingdom[r][c-1] = kingdom[r][c];
                    q.push(r*n+c-1);
                    level[r][c-1] = level[r][c]+1;
                }else if(level[r][c]+1 == level[r][c-1]){
                    if(kingdom[r][c] <= kingdom[r][c-1]){
                        q.push(r*n+c-1);
                        kingdom[r][c-1] = kingdom[r][c];
                    }
                }
            }
            if(c + 1 < n){
                if(level[r][c]+1 < level[r][c+1]){
                    kingdom[r][c+1] = kingdom[r][c];
                    q.push(r*n+c+1);
                    level[r][c+1] = level[r][c]+1;
                }else if(level[r][c]+1 == level[r][c+1]){
                    if(kingdom[r][c] <= kingdom[r][c+1]){
                        q.push(r*n+c+1);
                        kingdom[r][c+1] = kingdom[r][c];
                    }
                }
            }
        }
        REP(i, m){
            REP(j, n){
                cout << kingdom[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

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
const int MAXN = 500;
const LL INF = 1e18;

int adj[MAXN][MAXN];
bool intree[MAXN];
LL dist[MAXN];
int N, E;

int dijkstra(int src, int dest){
    fill(intree, intree+N, false);
    fill(dist, dist+N, INT_MAX);
    dist[src] = 0;
    int u = src;
    while(!intree[u]){
        intree[u] = true;
        REP(i, N){
            if(adj[u][i]){
                int v = i;
                int w = adj[u][i];
                int iw = adj[i][u];
                if(iw){
                    if(dist[v] > dist[u]){
                        dist[v] = dist[u];
                    }
                }else{
                    if(dist[v] > dist[u]+w){
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        int v = 1, distance = INT_MAX;
        REP(i, N){
            if(!intree[i] && (distance > dist[i])){
                distance = dist[i];
                v = i;
            }
        }
        u = v;
    }
    return dist[dest];
}

int main(){
   // freopen("input.in", "r", stdin);
    cin >> N >> E;
    while(N || E){
        memset(adj, 0, sizeof(adj));
        REP(i, E){
            int X, Y, H;
            cin >> X >> Y >> H;
            X--;
            Y--;
            adj[X][Y] = H;
        }
        int K;
        cin >> K;
        REP(i, K){
            int O,D;
            cin >> O >> D;
            int ans = dijkstra(O-1, D-1);
            if(ans == INT_MAX){
                cout << "Nao e possivel entregar a carta" << endl;
            }else{
                cout << ans << endl;
            }
        }
        cout << endl;
        cin >> N >> E;
    }
}

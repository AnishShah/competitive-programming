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
const int MAXN = 10001;
const LL INF = 1e18;

struct node{
    int y, w;
    node(){}
    node(int _y, int _w):y(_y), w(_w){}
    inline bool operator < (const node& that) const {return w > that.w;}
};

vector<node> adj[MAXN];
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
        REP(i, sz(adj[u])){
            int v = adj[u][i].y;
            int w = adj[u][i].w;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u] + w;
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
    int T;
    cin >> T;
    while(T--){
        cin >> N >> E;
        REP(i, N){
            adj[i].clear();
        }
        REP(i, E){
            int X, Y, H;
            cin >> X >> Y >> H;
            X--;
            Y--;
            adj[X].pb(node(Y, H));
        }
        int X, Y;
        cin >> X >> Y;
        --X, --Y;
        int ans = dijkstra(X, Y);
        if(ans == INT_MAX){
            cout << "NO" << endl;
        }else{
            cout << ans << endl;
        }
    }
}


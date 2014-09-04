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
const int MAXN = 10000;
const int INF = 1e9;

struct node{
    int y, w;
    node(){}
    node(int _y, int _w):y(_y), w(_w){}
    inline bool operator < (const node& that) const {return w > that.w;}
};

vector<node> adj[MAXN];
bool intree[MAXN];
int dist[MAXN];
int N;

vector<int> dijkstra(int src){
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
    int index = 0, m = 0;
    REP(i, N){
        if(dist[i] > m){
            m = dist[i];
            index = i;
        }
    }
    vector<int> ans;
    ans.pb(index);
    ans.pb(m);
    return ans;
}

int main(){
    cin >> N;
    FOR(i, 1, N-1){
        int X, Y;
        cin >> X >> Y;
        X--, Y--;
        adj[X].pb(node(Y, 1));
        adj[Y].pb(node(X, 1));
    }
    vector<int> index = dijkstra(0);
    vector<int> answer = dijkstra(index[0]);
    cout << answer[1] << endl;
}


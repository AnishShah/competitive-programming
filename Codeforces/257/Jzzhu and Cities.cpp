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
const int MAXN = 100000;
const LL INF = 1e18;

struct node{
    int y, w;
    bool is;
    node(){}
    node(int _y, int _w, bool _is):y(_y), w(_w), is(_is){}
};

vector<node> adj[MAXN];
bool intree[MAXN];
LL dist[MAXN];
bool pre[MAXN];
int N, M, K;

void dijkstra(){
    fill(intree, intree+N, false);
    fill(dist, dist+N, INF);
    fill(pre, pre+N, true);
    dist[0] = 0;
    intree[0] = true;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        intree[u] = false;
        REP(i, sz(adj[u])){
            int v = adj[u][i].y;
            int w = adj[u][i].w;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u] + w;
                pre[v] = adj[u][i].is;
                if(!intree[v]){
                    intree[v] = true;
                    Q.push(v);
                }
            }else if(dist[v] == dist[u] + w){
                pre[v] = pre[v] && adj[u][i].is;
            }
        }
    }
    int ans = 0;
    FOR(i, 1, N-1){
        ans += pre[i];
    }
    cout << K-ans << endl;
}

int main(){
   // freopen("input.in", "r", stdin);
    cin >> N >> M >> K;
    REP(i, M){
        int X, Y, H;
        cin >> X >> Y >> H;
        X--;
        Y--;
        adj[X].pb(node(Y, H, 0));
        adj[Y].pb(node(X, H, 0));
    }
    REP(i, K){
        int Y, H;
        cin >> Y >> H;
        Y--;
        adj[0].pb(node(Y, H, 1));
        adj[Y].pb(node(0, H, 1));
    }
    dijkstra();
    return 0;
}

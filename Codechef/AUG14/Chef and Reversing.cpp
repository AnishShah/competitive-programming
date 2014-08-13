#include <bits/stdc++.h>
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
const int MAXN = 100002;
const int INF = INT_MAX;
struct node{
    int y, w;
    node(){}
    node(int _y, int _w):y(_y), w(_w){}
};

vector<node> adj[MAXN];
bool intree[MAXN];
LL dist[MAXN];
int N, M;

void dijkstra(){
    fill(intree, intree+N, false);
    fill(dist, dist+N, INF);
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
                if(!intree[v]){
                    intree[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    if(dist[N-1] == INF) cout << -1 << endl;
    else cout << dist[N-1] << endl;
}

int main(){
  //  freopen("input.in", "r", stdin);
    cin >> N >> M;
    REP(i, M){
        int X, Y;
        cin >> X >> Y;
        X--, Y--;
        adj[X].pb(node(Y, 0));
        adj[Y].pb(node(X, 1));
    }
    dijkstra();
}

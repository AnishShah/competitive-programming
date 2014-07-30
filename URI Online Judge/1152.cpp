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
#define MAXN 200000
const LL INF = 1e18;
struct node{
    int y, w;
    node(){}
    node(int _y, int _w):y(_y), w(_w){}
    inline bool operator < (const node& that) const {return w > that.w;}
};

vector<node> adj[MAXN];
int m, n;
bool intree[MAXN];
LL dist[MAXN];

LL primMST(){
    fill(intree, intree+m, false);
    priority_queue<node> Q;
    Q.push(node(0, 0));
    int total = 0;
    LL tcost = 0;
    while(total < m){
        node item = Q.top(); Q.pop();
        if(intree[item.y]) continue;

        intree[item.y] = true;
        tcost += item.w;
        total++;

        REP(i, sz(adj[item.y])){
            if(!intree[adj[item.y][i].y]){
                Q.push(adj[item.y][i]);
            }
        }
    }
    return tcost;
}

int main(){
   // freopen("input.in", "r", stdin);
    cin >> m >> n;
    while(m || n){
        LL before = 0;
        REP(i, m){
            adj[i].clear();
        }
        REP(i, n){
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].pb(node(y, w));
            adj[y].pb(node(x, w));
            before += w;

        }
        cout <<  before-primMST()<< endl;
        cin >> m >> n;
    }
}

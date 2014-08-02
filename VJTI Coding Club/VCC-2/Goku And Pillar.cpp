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

struct node{
    int data;
    LL vegeta;
    node *left, *right;
};

node* newNode(int data){
    node* newn = (node*)malloc(sizeof(node));
    newn->data = data;
    newn->left = NULL;
    newn->right = NULL;
    newn->vegeta = 0;
    return newn;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        node *root = NULL;
        LL ans = 0;
        REP(i, n){
            int hi;
            cin >> hi;
            node *ptr = root, *prev = NULL;
            while(ptr){
                prev = ptr;
                if(ptr->data > hi){
                    ans += 1+ptr->vegeta;
                    ptr = ptr->left;
                }else{
                    ptr->vegeta++;
                    ptr = ptr->right;
                }
            }
            if(prev == NULL){
                root = newNode(hi);
            }else if(prev->data > hi){
                prev->left = newNode(hi);
            }else{
                prev->right = newNode(hi);
            }
        }
        cout << ans << endl;
    }
}

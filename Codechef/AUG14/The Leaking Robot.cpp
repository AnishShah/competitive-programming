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

void first_quad(int x, int y){
    if((x % 2 == 0 && (y <= x+1 || y % 2 == 1)) || (x % 2 == 1 && (y > x+1 && y % 2 == 1))){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

void second_quad(int x, int y){
    if((abs(x) % 2 == 1 && (y <= abs(x) || y % 2 == 1)) || (abs(x) % 2 == 0 && (y > abs(x) && y % 2 == 1))){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

void third_quad(int x, int y){
    if((abs(x) % 2 == 1 && (abs(y) <= abs(x) || abs(y) % 2 == 1)) || (abs(x) % 2 == 0 && (abs(y) > abs(x) && abs(y) % 2 == 1))){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

void forth_quad(int x, int y){
    if((x % 2 == 0 && (abs(y) < x || abs(y) % 2 == 1)) || (x % 2 == 1 && (x <= abs(y) && abs(y) % 2 == 1))){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

void on_line(int x, int y){
    if(x){
        if((x < 0 && x % 2 == 0) || (x > 0 && x % 2 == 1)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        if(y % 2 == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int X, Y;
        cin >> X >> Y;
        if(X == 0 && Y == 0){
            cout << "YES" << endl;
        }else if(X > 0 && Y > 0){
            first_quad(X, Y);
        }else if(X < 0 && Y > 0){
            second_quad(X, Y);
        }else if(X <0 && Y < 0){
            third_quad(X, Y);
        }else if(X > 0 && Y < 0){
            forth_quad(X, Y);
        }else{
            on_line(X, Y);
        }
    }
}

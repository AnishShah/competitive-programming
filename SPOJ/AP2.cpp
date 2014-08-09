#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define LL long long
int main(){
    int t;
    cin >> t;
    while(t--){
        LL x, y, s;
        cin >> x >> y >> s;
        LL n = 2*s/(x+y);
        LL d = (y-x)/(n-5);
        LL a = x - 2*d;
        cout << n << endl;
        REP(i, n){
            cout << a + i * d << " ";
        }
        cout << endl;
    }
}

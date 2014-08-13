#include <iostream>
using namespace std;
#define LL long long

int main(){
    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;
        if(n % 2 == 0){
            cout << n*(n+2)*(2*n+1)/8 << endl;
        }else{
            cout << (n*(n+2)*(2*n+1)-1)/8 << endl;
        }
    }
}

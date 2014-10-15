#include <iostream>
#include <cmath>
using namespace std;
#define LL long long
#define sz(c) (c).size()

int main(){
    int t;
    cin >> t;
    while(t--){
        string a_str;
        int a;
        LL b;
        cin >> a_str >> b;
        a = a_str[sz(a_str)-1] - '0';
        if(b){
            int num = a*a, cnt = 1;
            while(num % 10 != a % 10){
                cnt++;
                num *=a;
            }
            if(cnt == 1){
                cout << a % 10 << endl;
            }else{
                b = b % cnt == 0 ? cnt : b % cnt;
                cout << int(pow(a, b)) % 10 << endl;
            }
        }else{
            cout << 1 << endl;
        }
    }
}

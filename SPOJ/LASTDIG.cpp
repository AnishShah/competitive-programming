#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
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

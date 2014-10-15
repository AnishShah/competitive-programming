#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        string num;
        cin >> num;
        int m = 0;
        for(int i = 0; i <= num.size()-K; i++){
            int temp = 1;
            for(int j = 0; j < num.substr(i, K).size(); j++){
                temp = temp * (num[i+j]-'0');
            }
            m = max(temp, m);
        }
        cout << m << endl;
    }
    return 0;
}
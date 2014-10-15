#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int n){
    int res = 0;
    while(n != 0){
        int dig = n % 10;
        res = res*10 + dig;
        n/=10;
    }
    return res;
}

bool isPalindrome(int n){
    return n == reverse(n);
}

int main() {
    int a = 999, b, db, largest_pal;
    vector<int> pal;
    while(a >= 100){
        if(a % 11 == 0){
            b = 999;
            db = 1;
        }else{
            b = 990;
            db = 11;
        }
        while(b >= a){
            if(isPalindrome(a*b)){
                largest_pal = a*b;
                pal.push_back(largest_pal);
            }
            b -= db;
        }
        a-=1;
    }   
    sort(pal.begin(), pal.end());
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int i = 0;
        while(pal[i] < N){
            i++;
        }
        cout << pal[i-1]<< endl;
    }
    return 0;
}
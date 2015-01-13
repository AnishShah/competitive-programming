#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define sz(c) (c).size()


int main() {
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int index = -1;
        REP(i, sz(str)/2){
            if(str[i] != str[sz(str)-1-i]){
                index = i;
                break;
            }
        }
        if(index == -1){
        	cout << "YES" << endl;
        }else{
	        string stra = str.substr(0, index) + str.substr(index+1);
	        string strb = str.substr(0, sz(str)-1-index) +                                 str.substr(sz(str)-index);
	        bool first = true, second = true;
	        REP(i, sz(stra)/2){
	            if(stra[i] != stra[sz(stra)-1-i]){
	                first = false;
	            }
	        }
	        REP(i, sz(strb)/2){
	            if(strb[i] != strb[sz(strb)-1-i]){
	                second = false;
	            }
	        }
	        if(first){
	            cout << "YES" << endl;
	        }else if(second){
	            cout << "YES" << endl;
	        }else{
	        	cout << "NO" << endl;
	        }
    	}
    }
    return 0;
}

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

#define all(c) (c).begin(), (c).end()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define mp make_pair
#define LL long long

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vi D(n);
        LL cost = 0;
        deque<pair<int, int> > villagers, dinosaurs;
        REP(i, n) {
            cin >> D[i];
            if(D[i] > 0){
                villagers.push_back(mp(D[i], i));
                if(!dinosaurs.empty() && !villagers.empty()){
                    while(!dinosaurs.empty() && !villagers.empty()) {
                        pair<int, int> dback = dinosaurs.front(), vback = villagers.front();
                        dinosaurs.pop_front(), villagers.pop_front();
                        int ladoo = dback.first;
                        int ladoo_available = min(dback.first, vback.first);
                        cost += ladoo_available*abs(dback.second-vback.second);
                        ladoo -= ladoo_available;
                        if(ladoo != 0) {
                            dinosaurs.push_front(mp(ladoo, dback.second));
                        }else if(vback.first > dback.first){
                            villagers.push_front(mp(vback.first-ladoo_available, vback.second));
                        }
                    }
                }
            }else if(D[i] < 0){
                int ladoo = -D[i];
                if(!villagers.empty()){
                    while(ladoo > 0 && !villagers.empty()) {
                        pair<int, int> front = villagers.front();
                        villagers.pop_front();
                        int ladoo_available = min(front.first, ladoo);
                        ladoo -= ladoo_available;
                        cost += ladoo_available*abs(front.second-i);
                        if(ladoo < front.first){
                            villagers.push_front(mp(front.first-ladoo_available, front.second));
                        }
                    }
                    if(ladoo > 0){
                        dinosaurs.push_back(mp(ladoo, i));
                    }
                }else{
                    dinosaurs.push_back(mp(ladoo, i));
                }
            }
        }
        cout << cost << endl;
    }
}

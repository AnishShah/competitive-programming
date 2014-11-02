#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define LL long long
#define sz(c) (c).size()

int main(){
	int N;
	cin >> N;
	vector<int> dates;
	REP(i, N){
		int m, d;
		cin >> m >> d;
		if(m != 10){
			int decimal = 0, dig = 0;
            bool ok = true;
			while(d != 0){
                int unit = d % 10;
				decimal += unit * pow(m, dig);
                if(unit >= m){
                    ok = false;
                    break;
                }
				d/=10;
				dig++;
			}
            if(ok){
			     dates.pb(decimal);
            }
		}else{
			dates.pb(d);
		}
	}
    if(sz(dates) == 0){
        cout << 0 << endl;
    }else{
	    sort(all(dates));
        LL cnt = 0, tot = 0;
	    REP(i, sz(dates)-1){
		    if(dates[i] == dates[i+1]){
			     cnt++;
		    }else{
			     tot += cnt*(cnt+1)/2;
		         cnt = 0;
		    }
	    }
        tot += cnt*(cnt+1)/2;
        cout << tot << endl;
    }
    return 0;
}
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		vi num(N);
		REP(i, N){
			scanf("%d", &num[i]);
		}
		int current = 0, cnt = 1;
		FOR(i, 1, N-1){
			if(num[current] == num[i]) cnt++;
			else cnt--;
			if(cnt == 0){
				current = i;
				cnt = 1;
			}
		}
		cnt = 0;
		REP(i, N){
			if(num[current] == num[i]) cnt++;
		}
		if(cnt > N/2) printf("YES %d\n", num[current]);
		else printf("NO\n");
	}
}
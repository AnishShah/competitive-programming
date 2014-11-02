#include <cstdio>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int N;
	scanf("%d", &N);
	int ans = 0;
	REP(i, N){
		int temp;
		scanf("%d", &temp);
		ans ^= temp;
	}
	printf("%d\n", ans);
}
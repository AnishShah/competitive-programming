#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int N;
	scanf("%d", &N);
	vi num(N);
	REP(i, N){
		scanf("%d", &num[i]);
	}
	int current = -1, cnt = 0;
	REP(i, N){
		if(cnt == 0){
			current = num[i];
			cnt++;
		}else{
			if(current == num[i]) cnt++;
			else cnt--;
		}
	}
	printf("%d\n", current);
}
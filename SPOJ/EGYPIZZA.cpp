#include <cstdio>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(){
	int N;
	scanf("%d", &N);
	int quat = 0, half = 0, threequats = 0;
	REP(i, N){
		int x, y;
		scanf("%d/%d", &x, &y);
		if(x == 3 && y == 4) threequats++;
		else if(x == 1 && y == 4) quat++;
		else half++;
	}
	int cnt = 1;
	cnt += threequats;
	quat -= threequats;
	cnt += (half-half%2)/2;
	if(half%2){
		cnt++;
		quat-=2;
	}
	if(quat > 0){
		cnt += (quat - quat%4)/4;
		if(quat % 4 > 0){
			cnt++;
		}
	}
	printf("%d\n", cnt);
}
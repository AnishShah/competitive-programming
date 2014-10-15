#include <cstdio>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define LL long long
int main(){
	int T;
	scanf("%d", &T);
	FOR(i, 1, T){
		double r;
		scanf("%lf", &r);
		printf("Case %d: %0.2lf\n", i, 4*r*r+.25);
	}
}
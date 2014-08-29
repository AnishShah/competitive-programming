#include <cmath>
#include <cstdio>
using namespace std;
#define PI acos(-1)

int main(){
	int L;
	scanf("%d", &L);
	while(L){
		printf("%.2f\n", L*L/PI/2);
		scanf("%d", &L);
	}
}
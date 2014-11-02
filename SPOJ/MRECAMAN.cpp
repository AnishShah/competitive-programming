#include <cstdio>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

int main(){
	int a[500000];
	a[0] = 0;
	map<int, int> m;
	m[a[0]] = 1;
	FOR(i, 1, 499999){
		int temp = a[i-1] - i;
		if(temp >= 0 && !m[temp]){
			a[i] = temp;
			m[temp] = 1;
		}else{
			a[i] = a[i-1] + i;
			m[a[i]] = 1;	
		}
	}	
	int k;
	scanf("%d", &k);
	while(k != -1){
		printf("%d\n", a[k]);
		scanf("%d", &k);
	}
	return 0;
}
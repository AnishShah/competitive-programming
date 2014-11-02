#include <stdio.h>
#include <string.h>

int max(int a, int b){
	if(a > b)
		return a;
	return b;
}

int stones[100][100], N, M;
int dp[100][100];
int f(int city, int bus_no){
    if(bus_no < 0 || bus_no >= M){
        return 0;
    }
    if(city+1 < N){
        int less, equal, great;
        if(bus_no > 0){
            if(dp[city+1][bus_no-1]){
                less = dp[city+1][bus_no-1];
            }else{
                less = f(city+1, bus_no-1);
                dp[city+1][bus_no-1] = less;
            }
        }else{
            less = 0;
        }
        if(dp[city+1][bus_no]){
            equal = dp[city+1][bus_no];
        }else{
            equal = f(city+1, bus_no);
            dp[city+1][bus_no] = equal;
        }
        if(bus_no+1 < M){
            if(dp[city+1][bus_no+1]){
                great = dp[city+1][bus_no+1];
            }else{
                great = f(city+1, bus_no+1);
                dp[city+1][bus_no+1] = great;
            }
        }else{
            great = 0;
        }
        int next_city = max(equal, max(less, great));
        return stones[city][bus_no] + next_city;
    }else{
        return stones[city][bus_no];
    }
}

int main(){
    int T, i, j;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &M);
        for(i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
            	scanf("%d", &stones[i][j]);
            }
        }
        int m = 0;
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < M; i++) {
            m = max(m, f(0, i));
        }
        printf("%d\n", m);
    }
}

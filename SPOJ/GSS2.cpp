#include <iostream>
#include <cstdio>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define LL long long
const int MAXN = 50000;

int N;
int A[MAXN];

struct data{
	LL sum, pref, suff, ans;
};

data tree[4*MAXN];

data combine(data l, data r){
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref, l.sum+r.pref);
	res.suff = max(r.suff, r.sum+l.suff);
	res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	return res;
}

data make_data(int val){
	data res;
	res.sum = res.pref = res.suff = res.ans = val;
	return res;
}

void build(int v, int l, int r){
	if(l == r){
		tree[v] = make_data(A[l]);
	}else{
		int mid = (l+r)/2;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
		tree[v] = combine(tree[2*v], tree[2*v+1]);
	}
}

data query(int v, int l, int r, int x, int y){
	if(l == x && r == y)
		return tree[v];
	int mid = (l+r)/2;
	if(y <= mid)
		return query(2*v, l, mid, x, y);
	if(x > mid)
		return query(2*v+1, mid+1, r, x, y);
	return combine(
			query(2*v, l, mid, x, mid),
			query(2*v+1, mid+1, r, mid+1, y)
		);
}

int main(){
	int M;
	scanf("%d", &N);
	REP(i, N) scanf("%d", &A[i]);
	build(1, 0, N-1);
	scanf("%d", &M);
	REP(i, M){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%lld\n", query(1, 1, N, x, y).ans);
	}
	return 0;
}
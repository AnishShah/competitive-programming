#include <iostream>
using namespace std;
#define REP(i, n)       for(int i = 0; i < (n); i++)
#define REPD(i, n)      for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b)    for(int i = (a); i <= (b); i++)
#define FORD(i, a, b)   for(int i = (a); i >= (b); i--)
#define MAX 10001

struct union_set{
	int p[MAX];
	int size[MAX];
	int n;
};

void union_set_init(union_set *s, int n){
	FOR(i, 1, n){
		s->p[i] = i;
		s->size[i] = 1;
	}
	s->n = n;
}

int find(union_set *s, int x){
	if(s->p[x] == x){
		return x;
	}
	return find(s, s->p[x]);
}

bool make_set(union_set *s, int s1, int s2){
	
	int r1 = find(s, s1);
	int r2 = find(s, s2);

	if(r1 == r2) return false;

	if(s->size[r1] >= s->size[r2]){
		s->size[r1] += s->size[r2];
		s->p[r2] = r1;
	}else{
		s->size[r2] += s->size[r1];
		s->p[r1] = r2;
	}
	return true;
}

bool same_component(union_set *s, int s1, int s2){
	return find(s, s1) == find(s, s2);
}

int main(){
	int N, M;
	cin >> N >> M;
	union_set s;
	union_set_init(&s, N);
	REP(i, M){
		int X, Y;
		cin >> X >> Y;
		if(same_component(&s, X, Y)){
			cout << "NO" << endl;
			return 0;
		}else{
			make_set(&s, X, Y);
		}
	}
	cout << "YES" << endl;
	return 0;
}
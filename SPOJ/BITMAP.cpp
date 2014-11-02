#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define mp make_pair

char bitmap[183][183];
int dist[183][183];
bool visited[183][183];

int main(){
	int t;
	cin >> t;
	while(t--){
		memset(bitmap, 0, sizeof(bitmap));
		memset(dist, 0, sizeof(dist));
		memset(visited, false, sizeof(visited));
		int n, m;
		cin >> n >> m;
		queue<pair< int, pair<int, int> > > Q;
		REP(i, n){
			REP(j, m){
				cin >> bitmap[i][j];
				if(bitmap[i][j] == '1'){
					Q.push(mp(i, mp(j, 0)));
				}
			}
		}
		while(!Q.empty()){
			pair<int, pair<int, int> > front = Q.front();
			Q.pop();
			int x = front.first, y = front.second.first, cnt = front.second.second;
			if(!visited[x][y]){
				visited[x][y] = true;
				if(bitmap[x][y] == '0'){
					dist[x][y] = cnt;
				}
				if(x-1 >= 0 && !visited[x-1][y]){
					Q.push(mp(x-1, mp(y, cnt+1)));
				}
				if(x+1 < n && !visited[x+1][y]){
					Q.push(mp(x+1, mp(y, cnt+1)));
				}
				if(y-1 >= 0 && !visited[x][y-1]){
					Q.push(mp(x, mp(y-1, cnt+1)));
				}
				if(y+1 < m && !visited[x][y+1]){
					Q.push(mp(x, mp(y+1, cnt+1)));
				}
			}
		}
		REP(i, n){
			REP(j, m){
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
	}
}
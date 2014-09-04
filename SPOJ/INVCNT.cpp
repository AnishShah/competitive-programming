#include <iostream>
#include <queue>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define LL long long

LL merge(int arr[], int low, int mid, int high){
	LL sz = 0;
	queue<int> q1, q2;
	FOR(i, low, mid){
		q1.push(arr[i]);
	}
	FOR(i, mid+1, high){
		q2.push(arr[i]);
	}
	int i = low;
	while(!q1.empty() && !q2.empty()){
		if(q1.front() < q2.front()){
			arr[i++] = q1.front();
			q1.pop();
		}else{
			sz += (int)q1.size();
			arr[i++] = q2.front();
			q2.pop();
		}
	}
	while(!q1.empty()){
		arr[i++] = q1.front();
		q1.pop();
	}
	while(!q2.empty()){
		arr[i++] = q2.front();
		q2.pop();
	}
	return sz;
}

LL mergesort(int arr[], int low, int high){
	LL cnt = 0;
	if(low < high){
		int mid = (low + high)/2;
		cnt = mergesort(arr, low, mid);
		cnt += mergesort(arr, mid+1, high);
		cnt += merge(arr, low, mid, high);
	}
	return cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[200000];
		REP(i, n){
			cin >> arr[i];
		}
		cout << mergesort(arr, 0, n-1) << endl;
	}
}
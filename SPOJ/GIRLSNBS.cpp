#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int G,B;
	cin >> G >> B;
	while(G != -1 && B != -1){
		if(G > B) swap(G, B);
		if(G == 0) cout << B << endl;
		else cout << ceil(B*1.0/(G+1)) << endl;
		cin >> G >> B;
	}
}
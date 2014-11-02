#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		double a, b, c, d;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		double s = (a+b+c+d)/2.0;
		double area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%0.2lf\n", area);
	}
}
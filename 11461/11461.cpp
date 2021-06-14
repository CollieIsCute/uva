#include <cmath>
#include <iostream>
using namespace std;

using ll = long long;
const ll INDEX = 100002;
bool primeArr[ INDEX ] = { 0 };

int main() {
	for( ll i = 0; i < INDEX / 3 && i * i < INDEX; i++ ) {
		primeArr[ i * i ] = true;
	}
	ll a, b, cnt;
	while( cin >> a >> b && ( a || b ) ) {
		cnt = 0;
		for( ll i = a; i <= b; i++ )
			cnt += primeArr[ i ];
		cout << cnt << endl;
	}
}
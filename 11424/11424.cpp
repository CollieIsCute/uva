#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int MAX_N = 20001;

int main() {
	int N;
	ll sumOfGCD[ MAX_N ] = {}, ans;
	for ( int i = 2; i < MAX_N; i++ ) {
		for ( int j = 1; j < i; j++ ) {
			sumOfGCD[ i ] += __gcd( i, j );
		}
		cout << sumOfGCD[ i ] << ",";
	}
	while ( cin >> N && N ) {
		ans = 0;
		for ( int i = 2; i <= N; i++ )
			ans += sumOfGCD[ i ];
		cout << ans << endl;
	}
}
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int MAX_N = 200001;

inline int getPhi( int n ) {
	int ans = n;
	for( int i = 2; i * i <= n; ++i )
		if( n % i == 0 ) {
			ans = ans / i * ( i - 1 );
			while( n % i == 0 )
				n /= i;
		}
	if( n > 1 )
		ans = ans / n * ( n - 1 );
	return ans;
}

int main() {
	int N;
	ll phi[ MAX_N ], sumOfGCD[ MAX_N ], ans[ MAX_N ];

	for( int i = 1; i < MAX_N; i++ )
		phi[ i ] = getPhi( i );

	for( int i = 2; i < MAX_N; i++ )
		for( int j = 1; i * j < MAX_N; j++ )
			sumOfGCD[ i * j ] += phi[ i ] * j;

	ans[ 0 ] = ans[ 1 ] = 0;
	for( int i = 2; i < MAX_N; i++ )
		ans[ i ] = ans[ i - 1 ] + sumOfGCD[ i ];

	while( cin >> N && N )
		cout << ans[ N ] << endl;
}
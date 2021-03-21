#include <iostream>
using namespace std;

int getCycleLength( int n );

int main() {
	int i, j, bigest;
	while ( cin >> i >> j ) {
		bigest = 0;
		for ( int iter = min( i, j ); iter <= max( i, j ); iter++ ) {
			bigest = max( bigest, getCycleLength( iter ) );
		}
		cout << i << " " << j << " " << bigest << endl;
	}
}

int getCycleLength( int n ) {
	int cnt = 1;
	if ( n == 1 ) {
		cnt = 1;
		return cnt;
	}
	while ( n > 1 ) {
		if ( n % 2 == 1 ) {
			n = 3 * n + 1;
		}
		else {
			n = n / 2;
		}
		cnt++;
	}
	return cnt;
}
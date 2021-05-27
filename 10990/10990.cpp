#include <iostream>
using namespace std;
using ll = long long;
const int mn_MAX = 2000002;
const int test = 2000;

int phi( int n ) {
	int ans = n;
	for ( int i = 2; i * i <= n; ++i )
		if ( n % i == 0 ) {
			ans = ans / i * ( i - 1 );
			while ( n % i == 0 )
				n /= i;
		}
	if ( n > 1 )
		ans = ans / n * ( n - 1 );
	return ( int )ans;
}

int phiTable[ mn_MAX ] = {};
int depthPhi[ mn_MAX ] = {};

int main() {
	phiTable[ 1 ] = 1;
	for ( int i = 2; i < mn_MAX; i++ ) {  // init phiTable[]
		phiTable[ i ] = phi( i );
		// cout<<i<<"\t"<<phiTable[i]<<endl;
	}
	for ( int i = 1; i < mn_MAX; i++ ) {  // init depthPhi[]
		int temp = i;
		int cnt = 0;
		while ( temp != 1 ) {
			temp = phiTable[ temp ];
			cnt++;
		}
		depthPhi[ i ] = cnt;
	}
	// cout<<"finish"<<endl;
	int num, m, n;
	cin >> num;
	for ( int i = 0; i < num; i++ ) {
		cin >> m >> n;
		int sum = 0;
		for ( int j = m; j <= n; j++ ) {
			sum += depthPhi[ j ];
		}
		cout << sum << endl;
	}
}
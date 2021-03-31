#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

bool testIJ( int i, int j ) {
	int temp = j, temp2 = j / i;
	bool numUsed[ 10 ] = {};
	for ( int iter = 0; iter < 5; iter++ ) {
		numUsed[ temp % 10 ]  = true;
		numUsed[ temp2 % 10 ] = true;
		temp /= 10;
		temp2 /= 10;
	}
	for ( int iter = 0; iter < 10; iter++ ) {
		if ( !( numUsed[ iter ] ) )
			return false;
	}
	return true;
}

int main() {
	vector< vector< int > > vec;
	bool flag = false;
	vec.push_back( vector< int >() );
	vec.push_back( vector< int >() );
	for ( int i = 2; i <= 79; i++ ) {
		vec.push_back( vector< int >() );
		for ( int j = 01234; j <= 98765; j++ ) {
			if ( ( j % i == 0 ) && testIJ( i, j ) ) {
				vec[ i ].push_back( j );
			}
		}
	}
	int inputNum;
	cin >> inputNum;
	while ( inputNum ) {
		if ( !( vec[ inputNum ].size() ) )
			cout << "There are no solutions for " << inputNum << ".\n";
		for ( int i = 0; i < vec[ inputNum ].size(); i++ ) {
			cout << setw( 5 ) << setfill( '0' ) << vec[ inputNum ][ i ] << " / " << setw( 5 ) << setfill( '0' ) << vec[ inputNum ][ i ] / inputNum << " = ";
			cout << inputNum << endl;
		}
		cin >> inputNum;
		if ( inputNum )
			cout << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

int LIS( deque< int > const& d ) {
	deque< int > train;
	if( d.size() <= 1 )
		return d.size();
	train.push_back( d[ 0 ] );
	for( int i = 1; i < d.size(); i++ ) {
		if( d[ i ] > train.back() )
			train.push_back( d[ i ] );
		else {
			*lower_bound( train.begin(), train.end(), d[ i ] ) = d[ i ];
		}
	}
	return train.size();
}

int main() {
	int loopCase, numOfTrain;
	int temp;
	deque< int > train;
	cin >> loopCase;
	for( int i = 0; i < loopCase; i++ ) {
		cin >> numOfTrain;
		for( int j = 0; j < numOfTrain; j++ ) {
			cin >> temp;
			train.push_back( temp );
			train.push_front( temp );
		}
		cout << LIS( train ) << endl;
		train.clear();
	}
}
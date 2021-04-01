#include <iostream>
#include <vector>
using namespace std;

int LIS( vector< int > const &v ) {
	vector< int > temp;
	if ( !( v.size() ) )
		return 0;
	temp.push_back( v[ 0 ] );
	for ( int i = 1; i < v.size(); i++ ) {
		if ( v[ i ] < temp.back() ) {
			temp.pop_back();
			temp.push_back( v[ i ] );
		}
		else if ( v[ i ] > temp.back() ) {
			temp.push_back( v[ i ] );
		}
	}
	return temp.size();
}

int main() {
	int loopCase, numOfTrain;
	int temp;
	vector<int> train;
	cin >> loopCase;
	for ( int i = 0; i < loopCase; i++ ) {
		cin >> numOfTrain;
		for ( int j = 0; j < numOfTrain; j++ ) {
			cin>>temp;
			train.push_back(temp);
		}
		cout<<LIS(train);
	}
}
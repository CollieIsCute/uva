#pragma GCC optimize( "Ofast" )
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;
const int MAX_NUM = 700000;

inline void init_prime();
inline void set_prime_table();

bool is_prime[ MAX_NUM + 1 ] = {};
vector< int > primes;

int main() {
	init_prime();
	int input;
	while( cin >> input && input ) {
		priority_queue< int, vector< int >, greater< int > > find_next_q;
		vector< int > factors;

		for( int i = 0; ( primes[ i ] <= input ) && ( i < primes.size() ); i++ ) {
			if( input % primes[ i ] == 0 )
				factors.push_back( primes[ i ] );
		}
		int first = 1;
		for( auto& elem : factors )
			first *= elem;
		find_next_q.push( first );

		while( find_next_q.top() <= input && find_next_q.top() < MAX_NUM
			   && find_next_q.size() > 0 ) {
			ll temp = find_next_q.top();
			for( int& elem : factors )
				if( 0 < temp * elem && temp * elem < MAX_NUM )
					find_next_q.push( temp * elem );
			find_next_q.pop();
		}
		if( find_next_q.empty() )
			cout << "Not Exist!\n";
		else
			cout << find_next_q.top() << endl;
	}
}

inline void init_prime() {
	for( auto& elem : is_prime )
		elem = true;
	is_prime[ 0 ] = false;
	is_prime[ 1 ] = false;
	for( int i = 2; i * i <= MAX_NUM; i++ )
		if( is_prime[ i ] )
			for( int j = i * i; j <= MAX_NUM; j += i )
				is_prime[ j ] = false;

	set_prime_table();
}

inline void set_prime_table() {
	for( int i = 0; i <= MAX_NUM; i++ ) {
		if( is_prime[ i ] ) {
			primes.push_back( i );
		}
	}
}
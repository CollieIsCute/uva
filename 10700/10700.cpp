#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll getMax( istringstream& max ) {
	vector< ll > numbers;
	vector< char > x;
	ll num1, num2;
	char now;
	max >> num1;
	while ( !max.eof() ) {
		max >> now;
		max >> num2;
		if ( now == '+' ) {
			num1 = num1 + num2;
		}
		else {
			numbers.push_back( num1 );
			x.push_back( now );
			num1 = num2;
		}
	}
	numbers.push_back( num1 );
	ll ans = 1;
	while ( !numbers.empty() ) {
		ans *= numbers.back();
		numbers.pop_back();
	}
	return ans;
}

ll getMin( istringstream& min ) {
	vector< ll > numbers;
	vector< char > x;
	ll num1, num2;
	char now;
	min >> num1;
	while ( !min.eof() ) {
		min >> now;
		min >> num2;
		if ( now == '*' ) {
			num1 = num1 * num2;
		}
		else {
			numbers.push_back( num1 );
			x.push_back( now );
			num1 = num2;
		}
	}
	numbers.push_back( num1 );
	ll ans = 0;
	while ( !numbers.empty() ) {
		ans += numbers.back();
		numbers.pop_back();
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	string line;

	for ( int i = 0; i < n; i++ ) {
		getline( cin, line );
		if ( line == "" )
			getline( cin, line );
		istringstream maxLine( line ), minLine( line );
		ll big = getMax( maxLine );
		ll small = getMin( minLine );
		cout << "The maximum and minimum are " << big << " and " << small << "." << endl;
	}
}
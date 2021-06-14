#include <iostream>
using namespace std;

int main() {
	long long int i, j;
	while( cin >> i >> j ) {
		cout << ( i > j ? ( i - j ) : ( j - i ) ) << endl;
	}
}
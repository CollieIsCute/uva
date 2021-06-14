#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	Account( int m = 0 ) : money( m ) {}
	void donate( int m ) {
		money += m;
	}
	void report() {
		cout << money << endl;
	}

private:
	int money;
};

int main() {
	int t, amount;
	string temp;
	Account acc;
	cin >> t;
	for( int i = 0; i < t; i++ ) {
		cin >> temp;
		if( temp == "donate" ) {
			cin >> amount;
			acc.donate( amount );
		}
		else
			acc.report();
	}
}
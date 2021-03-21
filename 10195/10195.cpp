#include <cmath>
#include <iomanip>
#include <iostream>

double getRadius( double a, double b, double c );

int main() {
	double a, b, c;
	std::cout << std::fixed << std::setprecision( 3 );
	while ( std::cin >> a >> b >> c ) {
		if ( a == b && b == c && c == 0.0 ) {
			std::cout << "The radius of the round table is: 0.000\n";
			continue;
		}
		std::cout << "The radius of the round table is: " << getRadius( a, b, c ) << std::endl;
	}
}

double getRadius( double a, double b, double c ) {
	double s = ( a + b + c ) / 2;
	return sqrt( ( s - a ) * ( s - b ) * ( s - c ) / s );
}
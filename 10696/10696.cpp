#include <iostream>

using namespace std;

inline int f91(int N) {
	if(N <= 100) {
		return 91;
	}
	else {
		return N - 10;
	}
}

int main() {
	int N;
	while(cin >> N) {
		if(N == 0)
			break;
		else
			cout << "f91(" << N << ") = " << f91(N) << endl;
	}
}
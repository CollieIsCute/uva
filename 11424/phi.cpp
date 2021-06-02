#include <iostream>
using namespace std;
using T = int;

inline T phi(T n) {
    T ans = n;
    for (T i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main(){
	int i;
	while(1){
		cin>>i;
		cout<<phi(i)<<endl;
	}
}
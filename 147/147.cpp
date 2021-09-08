#include <iostream>

using namespace std;
using ll = long long;

const int MAXI = 11;
const int MAXJ = 6005;

int money[] = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };  //把幣值*20作為整數儲存
ll dp[11][6005] = {};											   // dp[i][j] 表示前i種幣值要表示j元的方法數

int main() {

	double input;

	for(int j = 0; j < MAXJ; j++) {
		dp[0][j] = 1;
	}
	for(int i = 0; i < MAXI; i++) {
		dp[i][0] = 1;
	}
	for(int i = 1; i < MAXI; i++) {
		for(int j = 1; j < MAXJ; j++) {
			ll methodNum = 0;
			if(j - money[i] >= 0)
				methodNum += dp[i][j - money[i]];
			dp[i][j] = dp[i - 1][j] + methodNum;
		}
	}
	while(cin >> input && input) {
		int dollars = (int)(input * 20);
		printf("%6.2f%17lld\n", input, dp[MAXI - 1][dollars]);
	}
}
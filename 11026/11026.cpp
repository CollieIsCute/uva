#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <vector>

using ll = long long;
using namespace std;

int main() {
	ll N, M, temp;
	vector<ll> arr;
	ll dp[1001][1001];
	while(cin >> N >> M && N) {
		arr.clear();	   // reset
		arr.push_back(0);  // don't care
		memset(dp, 0, sizeof(arr));

		for(int i = 0; i < N; i++) {
			cin >> temp;
			arr.push_back(temp);
		}
		for(int n = 1; n <= N; n++) {
			for(int k = 1; k <= N; k++) {
				if(k > n)
					continue;  // dp[n][k] = 0;
				else if(k == 1)
					dp[n][k] = (dp[n - 1][k] + arr[n]) % M;
				else
					dp[n][k] = ((dp[n - 1][k - 1] * arr[n]) % M + dp[n - 1][k]) % M;
			}
		}
		ll maxDp = 0;
		for(int k = 1; k <= N; k++)
			maxDp = maxDp > dp[N][k] ? maxDp : dp[N][k];
		cout << maxDp << endl;
	}
}
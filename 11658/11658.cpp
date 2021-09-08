#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int P_LENGTH = 10001;

int main() {
	int n, x;
	double temp;
	bool probableCombi[P_LENGTH];
	int stocks[101];
	while(cin >> n && cin >> x && n) {
		fill(probableCombi, probableCombi + 10001, false);
		fill(stocks, stocks + 101, 0);
		for(int i = 1; i <= n; i++) {
			cin >> temp;
			stocks[i] = (temp * 100.0) + 0.5;  // to fix precision problem from double to int
		}
		probableCombi[stocks[x]] = true;
		int cnt = 0;
		vector<int> setTrue;
		for(int sit = 1; sit <= n; sit++) {
			if(sit == x)
				continue;
			for(int i = 1; i < P_LENGTH; i++) {
				if(probableCombi[i] && (i + stocks[sit]) <= 10000) {
					setTrue.push_back(i + stocks[sit]);
					cnt++;
				}
			}
			for(int iter : setTrue) {
				probableCombi[iter] = true;
			}
			setTrue.clear();
		}
		// cout<<cnt <<endl;
		for(int i = 5001; i <= 10000; i++) {
			if(probableCombi[i]) {
				double ans = (double)stocks[x] / i * 100.0;
				// cout<<i<<"\t";
				cout << fixed << setprecision(2) << ans << endl;
				ans = ans;
				break;
			}
		}
	}
}